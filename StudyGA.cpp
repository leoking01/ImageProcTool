#include "StdAfx.h"
#include "StudyGA.h"


StudyGA::StudyGA(void)
{
}


StudyGA::~StudyGA(void)
{
}

/*
说明：
（1）这里是求函数的最小值，函数值越小的个体适应度越大，所以这里采用倒数变换，
即把适应度函数F(x)定义为1/f(x)(f(x)为目标函数值),这样就保证了适应度函数F(x)越大，个体是越优的。
(当然我们已经保证了f（x）始终是一个正数)
(2) 选择操作采用的是经典的轮盘赌法，即每个个体被选为父代的概率与其适应度是成正比的，适应度越高，
被选中的概率越大，设pi为第i个个体被选中的概率，则
pi=Fi/(∑Fi),Fi为第i个个体的适应度函数。
(3)交叉操作：由于个体采用实数编码，所以交叉操作也采用实数交叉法，
第k个染色体ak和第l个染色体al在第j位的交叉操作方法为:
akj=aij(1-b)+aijb;  alj=alj(1-b)+akjb,其中b是[0,1]之间的随机数。k，l，j都是随机产生的，
即随机选取两个父代，再随机选取一个基因，按照公式完成交叉操作。
(4)变异操作：第i个个体的第j个基因进行变异的操作方法是：
r>=0.5时，aij=aij+(amax-aij)*f(g)
r<0.5时，aij=aij+(amin-aij)*f(g)
其中amax是基因aij的上界，amin是aij的下界，f(g)=r2*(1-g/Gmax）2，r2是一个[0,1]之间的随机数，
g是当前迭代次数，Gmax是进化最大次数，r是[0,1]之间的随机数。
可以看出，当r>=0.5时，aij是在aij到amax之间变化的；r<0.5时，aij是在amin到aij之间变化的。
这样的函数其实可以构造不止一种，来完成变异的操作。只要符合随机性，以及保证基因在有效的变化范围内即可。
我在ubuntu16.04下，使用gcc编译器运行得到的结果如下：
从结果上来看，种群数目为50，进化代数为500时，得到的最优解为2.014102已经非常接近实际的最优解2了，
当然，如果把种群数目再变大比如500，进化代数变多比如1000代，那么得到的结果将会更精确，种群数目为500，
进化代数为1000时的最优解如下：
可以看出，增加种群数目以及增加进化代数之后，最优值从2.014102变为2.000189,比原来的精度提高了两位，
但是相应地，程序的运行时间也显著增加了(从0.08秒左右增加到2秒左右)。
所以在具体求解复杂问题的时候(比如有的时候会碰到函数参数有几十个之多),
我们就必须综合考虑最优解的精度以及运算复杂度(运算时间)这两个方面，权衡之后，取合适的参数进行问题的求解。
当然，这里只是以求解多元非线性函数的极值问题为例来说明遗传算法的具体实现步骤，
遗传算法的实际运用非常广泛，不仅仅可以求解复杂函数极值，而且在运筹学等众多领域有着非常广泛的应用，
也经常会和其他的智能算法或者优化算法结合来求解问题。这个后面我还会再较为详细地论述。
 */

double chrom[sizepop][lenchrom]; // 种群数组
double fitness[sizepop]; //种群每个个体的适应度
double fitness_prob[sizepop]; // 每个个体被选中的概率(使用轮盘赌法确定)
double bestfitness[maxgen]; // 每一代最优值
double gbest_pos[lenchrom]; // 取最优值的位置
double average_best[maxgen+1]; // 每一代平均最优值
double gbest; // 所有进化中的最优值
int gbest_index; // 取得最优值的迭代次数序号



// 目标函数
double fit_func(double * arr)
{
	double x1 = *arr;
	double x2 = *(arr+1);
	double x3 = *(arr+2);
	double x4 = *(arr+3);
	double x5 = *(arr+4);
	double func_result = -5*sin(x1)*sin(x2)*sin(x3)*sin(x4)*sin(x5) - sin(5*x1)*sin(5*x2)*sin(5*x3)*sin(5*x4)*sin(5*x5) + 8;
	return func_result;
}

// 求和函数
double sum(double * fitness)
{
	double sum_fit = 0;
	for(int i=0;i<sizepop;i++)
		sum_fit += *(fitness+i);
	return sum_fit;
}

double * min_local(double * fitness)
{
	double min_fit = *fitness;
	double min_index = 0;
	static double arr[2];
	for(int i=1;i<sizepop;i++)
	{
		if(*(fitness+i) < min_fit)
		{
			min_fit = *(fitness+i);
			min_index = i;
		}
	}
	arr[0] = min_index;
	arr[1] = min_fit;
	return arr;
}

// 种群初始化
void init_chrom()
{
	for(int i=0;i<sizepop;i++)
	{
		for(int j=0;j<lenchrom;j++)
		{
			chrom[i][j] = bound_up*(((double)rand())/RAND_MAX);
		}
		fitness[i] = fit_func(chrom[i]); // 初始化适应度
	}
}

// 选择操作
void Select(double chrom[sizepop][lenchrom])
{
	//cout<< "\t Select(double chrom[sizepop][lenchrom]):    "<<   endl;
	int index[sizepop];
	for(int i=0;i<sizepop;i++)
	{
		double * arr = chrom[i];
		fitness[i] = 1/(fit_func(arr)); // 本例是求最小值，适应度为目标函数的倒数，即函数值越小，适应度越大
	}
	double sum_fitness = 0;
	for(int i=0;i<sizepop;i++)
	{
		sum_fitness += fitness[i]; // 适应度求和
	}
	for(int i=0;i<sizepop;i++)
	{
		fitness_prob[i] = fitness[i]/sum_fitness;
	}
	for(int i=0;i<sizepop;i++)
	{
		fitness[i] = 1/fitness[i]; // 恢复函数值
	}
	for(int i=0;i<sizepop;i++) // sizepop 次轮盘赌
	{
		double pick = ((double)rand())/RAND_MAX;

		int  idExit = 0 ;
		while(pick < 0.0001)
		{
			pick = ((double)rand())/RAND_MAX;

			idExit ++ ;
			if( idExit>numsExit  )
			{
				cout<< "force break. "<< endl ;
				break;
			}
		}
		for(int j=0;j<sizepop;j++)
		{
			pick = pick - fitness_prob[j];
			if(pick<=0)
			{
				index[i] = j;
				break;
			}
		}
	}
	for(int i=0;i<sizepop;i++)
	{
		for(int j=0;j<lenchrom;j++)
		{
			chrom[i][j] = chrom[index[i]][j];
		}
		fitness[i] = fitness[index[i]];
	}
}

// 交叉操作
void Cross(double chrom[sizepop][lenchrom])
{
	for(int i=0;i<sizepop;i++)
	{
		//cout<< "\t Cross(double chrom[sizepop][lenchrom]): i = "<< i <<  endl;
		// 随机选择两个染色体进行交叉
		double pick1 = ((double)rand())/RAND_MAX;
		double pick2 = ((double)rand())/RAND_MAX;
		int choice1 = (int)(pick1*sizepop);// 第一个随机选取的染色体序号
		int choice2 = (int)(pick2*sizepop);// 第二个染色体序号
		int  idExit = 0 ;
		while(choice1 > sizepop-1)
		{
			pick1 = ((double)rand())/RAND_MAX;
			choice1 = (int)(pick1*sizepop); //防止选取位置过界

			idExit ++ ;
			if( idExit>numsExit  )
			{
				cout<< "force break. "<< endl ;
				break;
			}
		}
		   idExit = 0 ;
		while(choice2 > sizepop-1)
		{
			pick2 = ((double)rand())/RAND_MAX;
			choice2 = (int)(pick2*sizepop);

			idExit ++ ;
			if( idExit>numsExit  )
			{
				cout<< "force break. "<< endl ;
				break;
			}
		}
		double pick = ((double)rand())/RAND_MAX;// 用于判断是否进行交叉操作
		if(pick>pcross)
		{
			continue;
		}
		int flag = 0; // 判断交叉是否有效的标记
		while(flag == 0)
		{
			double pick = ((double)rand())/RAND_MAX;
			int pos = (int)(pick*lenchrom);
			int  idExit = 0 ;
			while(pos > lenchrom-1)
			{
				double pick = ((double)rand())/RAND_MAX;
				int pos = (int)(pick*lenchrom); // 处理越界

				idExit ++ ;
				if( idExit>numsExit  )
				{
					cout<< "force break. "<< endl ;
					break;
				}
			}
			// 交叉开始
			double r = ((double)rand())/RAND_MAX;
			double v1 = chrom[choice1][pos];
			double v2 = chrom[choice2][pos];
			chrom[choice1][pos] = r*v2 + (1-r)*v1;
			chrom[choice2][pos] = r*v1 + (1-r)*v2; // 交叉结束
			if(chrom[choice1][pos] >=bound_down && chrom[choice1][pos]<=bound_up && chrom[choice2][pos] >=bound_down && chrom[choice2][pos]<=bound_up)
				flag = 1; // 交叉有效，退出交叉，否则继续下一次交叉
		}
	}
}

// 变异操作
void Mutation(double chrom[sizepop][lenchrom])
{
	  int  idExit  ;
	
	for(int i=0;i<sizepop;i++)
	{
		//cout<< "\t Mutation(double chrom[sizepop][lenchrom]): i = "<< i <<  endl;
		double pick = ((double)rand())/RAND_MAX; // 随机选择一个染色体进行变异
		int choice = (int)(pick*sizepop);
		idExit = 0;
		while(choice > sizepop-1)
		{
			pick = ((double)rand())/RAND_MAX;
			int choice = (int)(pick*sizepop);  // 处理下标越界
			idExit ++ ;
			if( idExit>numsExit  )
			{
				cout<< "force break. "<< endl ;
				break;
			}
		}
		pick = ((double)rand())/RAND_MAX; // 用于决定该轮是否进行变异
		if(pick>pmutation)
		{
			continue;
		}
		pick = ((double)rand())/RAND_MAX;
		int pos = (int)(pick*lenchrom);
		while(pos > lenchrom-1)
		{
			pick = ((double)rand())/RAND_MAX;
			pos = (int)(pick*lenchrom);

			idExit ++ ;
			if( idExit>numsExit  )
			{
				cout<< "force break. "<< endl ;
				break;
			}
		}
		double v = chrom[i][pos];
		double v1 = v - bound_up;
		double v2 = bound_down - v;
		double r = ((double)rand())/RAND_MAX;
		double r1 = ((double)rand())/RAND_MAX;
		if(r >= 0.5)
			chrom[i][pos] = v - v1*r1*(1-((double)i)/maxgen)*(1-((double)i)/maxgen);
		else
			chrom[i][pos] = v + v2*r1*(1-((double)i)/maxgen)*(1-((double)i)/maxgen);
		// 注意这里写法是不会越界的，所以只用一次变异就可以了
	}
}

// 主函数
int mainGA(void  )
{
	time_t start,  finish;
	start = clock(); // 程序开始计时
	srand(  ( unsigned  ) time(NULL)  ); // 初始化随机数种子
	init_chrom(); // 初始化种群
	double * best_fit_index = min_local(fitness);
	int best_index =(int)(*best_fit_index);
	gbest = *(best_fit_index+1); // 最优值
	gbest_index = 0;
	average_best[0] = sum(fitness)/sizepop; //初始平均最优值
	for(int i=0;i<lenchrom;i++)
	{
		gbest_pos[i] = chrom[best_index][i];
	}
	// 进化开始
	for(int i=0;i<maxgen;i++)
	{
		try
		{
			Select(chrom); // 选择
			Cross(chrom); //交叉
			Mutation(chrom); //变异
			for(int j=0;j<sizepop;j++)
			{
				fitness[j] = fit_func(chrom[j]);
			}
			double sum_fit = sum(fitness);
			average_best[i+1] = sum_fit/sizepop; // 平均最优值
			double * arr = min_local(fitness);
			double new_best = *(arr+1);
			int new_best_index = (int)(*arr); // 新最优值序号
			if(new_best < gbest)
			{
				gbest = new_best;
				for(int j=0;j<lenchrom;j++)
				{
					gbest_pos[j] = chrom[new_best_index][j];
				}
				gbest_index = i+1;
			}
			cout<< "gen = "<< i  ;
			cout<< " , ( new_best, gbest ) = "<< new_best<< " , "<< gbest<<  endl;
		}
		catch (CMemoryException* e)
		{
			cout<< " some CMemoryException occur. "<< endl ;
			continue;
		}
		catch (CFileException* e)
		{
			cout<< " some CFileException occur. "<< endl ;
			continue;
		}
		catch (CException* e)
		{
			cout<< " some CException occur. "<< endl ;
			continue;
		}
	}
	finish = clock(); // 程序计算结束
	double duration = ((double)(finish-start))/CLOCKS_PER_SEC;
	printf("程序计算耗时:%lf秒\n.",duration);
	printf("遗传算法进化了%d次，最优值为:%lf,最优值在第%d代取得,此代的平均最优值为%lf.\n",
		maxgen,gbest,gbest_index,average_best[gbest_index]);
	printf("取得最优值的地方为(%lf,%lf,%lf,%lf,%lf).\n",
		gbest_pos[0],gbest_pos[1],gbest_pos[2],gbest_pos[3],gbest_pos[4]);
	cout<<  endl;


	cv::Mat imgShow= cv::Mat( 200,200, CV_8UC3,Scalar(0,0,0 ));
	imshow( "imgShow",  imgShow );
	waitKey(0);
	return 0;
}



