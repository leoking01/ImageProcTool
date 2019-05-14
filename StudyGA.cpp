#include "StdAfx.h"
#include "StudyGA.h"


StudyGA::StudyGA(void)
{
}


StudyGA::~StudyGA(void)
{
}

/*
˵����
��1����������������Сֵ������ֵԽС�ĸ�����Ӧ��Խ������������õ����任��
������Ӧ�Ⱥ���F(x)����Ϊ1/f(x)(f(x)ΪĿ�꺯��ֵ),�����ͱ�֤����Ӧ�Ⱥ���F(x)Խ�󣬸�����Խ�ŵġ�
(��Ȼ�����Ѿ���֤��f��x��ʼ����һ������)
(2) ѡ��������õ��Ǿ�������̶ķ�����ÿ�����屻ѡΪ�����ĸ���������Ӧ���ǳ����ȵģ���Ӧ��Խ�ߣ�
��ѡ�еĸ���Խ����piΪ��i�����屻ѡ�еĸ��ʣ���
pi=Fi/(��Fi),FiΪ��i���������Ӧ�Ⱥ�����
(3)������������ڸ������ʵ�����룬���Խ������Ҳ����ʵ�����淨��
��k��Ⱦɫ��ak�͵�l��Ⱦɫ��al�ڵ�jλ�Ľ����������Ϊ:
akj=aij(1-b)+aijb;  alj=alj(1-b)+akjb,����b��[0,1]֮����������k��l��j������������ģ�
�����ѡȡ���������������ѡȡһ�����򣬰��չ�ʽ��ɽ��������
(4)�����������i������ĵ�j��������б���Ĳ��������ǣ�
r>=0.5ʱ��aij=aij+(amax-aij)*f(g)
r<0.5ʱ��aij=aij+(amin-aij)*f(g)
����amax�ǻ���aij���Ͻ磬amin��aij���½磬f(g)=r2*(1-g/Gmax��2��r2��һ��[0,1]֮����������
g�ǵ�ǰ����������Gmax�ǽ�����������r��[0,1]֮����������
���Կ�������r>=0.5ʱ��aij����aij��amax֮��仯�ģ�r<0.5ʱ��aij����amin��aij֮��仯�ġ�
�����ĺ�����ʵ���Թ��첻ֹһ�֣�����ɱ���Ĳ�����ֻҪ��������ԣ��Լ���֤��������Ч�ı仯��Χ�ڼ��ɡ�
����ubuntu16.04�£�ʹ��gcc���������еõ��Ľ�����£�
�ӽ������������Ⱥ��ĿΪ50����������Ϊ500ʱ���õ������Ž�Ϊ2.014102�Ѿ��ǳ��ӽ�ʵ�ʵ����Ž�2�ˣ�
��Ȼ���������Ⱥ��Ŀ�ٱ�����500����������������1000������ô�õ��Ľ���������ȷ����Ⱥ��ĿΪ500��
��������Ϊ1000ʱ�����Ž����£�
���Կ�����������Ⱥ��Ŀ�Լ����ӽ�������֮������ֵ��2.014102��Ϊ2.000189,��ԭ���ľ����������λ��
������Ӧ�أ����������ʱ��Ҳ����������(��0.08���������ӵ�2������)��
�����ھ�����⸴�������ʱ��(�����е�ʱ����������������м�ʮ��֮��),
���Ǿͱ����ۺϿ������Ž�ľ����Լ����㸴�Ӷ�(����ʱ��)���������棬Ȩ��֮��ȡ���ʵĲ��������������⡣
��Ȼ������ֻ��������Ԫ�����Ժ����ļ�ֵ����Ϊ����˵���Ŵ��㷨�ľ���ʵ�ֲ��裬
�Ŵ��㷨��ʵ�����÷ǳ��㷺��������������⸴�Ӻ�����ֵ���������˳�ѧ���ڶ��������ŷǳ��㷺��Ӧ�ã�
Ҳ������������������㷨�����Ż��㷨�����������⡣��������һ����ٽ�Ϊ��ϸ��������
 */

double chrom[sizepop][lenchrom]; // ��Ⱥ����
double fitness[sizepop]; //��Ⱥÿ���������Ӧ��
double fitness_prob[sizepop]; // ÿ�����屻ѡ�еĸ���(ʹ�����̶ķ�ȷ��)
double bestfitness[maxgen]; // ÿһ������ֵ
double gbest_pos[lenchrom]; // ȡ����ֵ��λ��
double average_best[maxgen+1]; // ÿһ��ƽ������ֵ
double gbest; // ���н����е�����ֵ
int gbest_index; // ȡ������ֵ�ĵ����������



// Ŀ�꺯��
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

// ��ͺ���
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

// ��Ⱥ��ʼ��
void init_chrom()
{
	for(int i=0;i<sizepop;i++)
	{
		for(int j=0;j<lenchrom;j++)
		{
			chrom[i][j] = bound_up*(((double)rand())/RAND_MAX);
		}
		fitness[i] = fit_func(chrom[i]); // ��ʼ����Ӧ��
	}
}

// ѡ�����
void Select(double chrom[sizepop][lenchrom])
{
	//cout<< "\t Select(double chrom[sizepop][lenchrom]):    "<<   endl;
	int index[sizepop];
	for(int i=0;i<sizepop;i++)
	{
		double * arr = chrom[i];
		fitness[i] = 1/(fit_func(arr)); // ����������Сֵ����Ӧ��ΪĿ�꺯���ĵ�����������ֵԽС����Ӧ��Խ��
	}
	double sum_fitness = 0;
	for(int i=0;i<sizepop;i++)
	{
		sum_fitness += fitness[i]; // ��Ӧ�����
	}
	for(int i=0;i<sizepop;i++)
	{
		fitness_prob[i] = fitness[i]/sum_fitness;
	}
	for(int i=0;i<sizepop;i++)
	{
		fitness[i] = 1/fitness[i]; // �ָ�����ֵ
	}
	for(int i=0;i<sizepop;i++) // sizepop �����̶�
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

// �������
void Cross(double chrom[sizepop][lenchrom])
{
	for(int i=0;i<sizepop;i++)
	{
		//cout<< "\t Cross(double chrom[sizepop][lenchrom]): i = "<< i <<  endl;
		// ���ѡ������Ⱦɫ����н���
		double pick1 = ((double)rand())/RAND_MAX;
		double pick2 = ((double)rand())/RAND_MAX;
		int choice1 = (int)(pick1*sizepop);// ��һ�����ѡȡ��Ⱦɫ�����
		int choice2 = (int)(pick2*sizepop);// �ڶ���Ⱦɫ�����
		int  idExit = 0 ;
		while(choice1 > sizepop-1)
		{
			pick1 = ((double)rand())/RAND_MAX;
			choice1 = (int)(pick1*sizepop); //��ֹѡȡλ�ù���

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
		double pick = ((double)rand())/RAND_MAX;// �����ж��Ƿ���н������
		if(pick>pcross)
		{
			continue;
		}
		int flag = 0; // �жϽ����Ƿ���Ч�ı��
		while(flag == 0)
		{
			double pick = ((double)rand())/RAND_MAX;
			int pos = (int)(pick*lenchrom);
			int  idExit = 0 ;
			while(pos > lenchrom-1)
			{
				double pick = ((double)rand())/RAND_MAX;
				int pos = (int)(pick*lenchrom); // ����Խ��

				idExit ++ ;
				if( idExit>numsExit  )
				{
					cout<< "force break. "<< endl ;
					break;
				}
			}
			// ���濪ʼ
			double r = ((double)rand())/RAND_MAX;
			double v1 = chrom[choice1][pos];
			double v2 = chrom[choice2][pos];
			chrom[choice1][pos] = r*v2 + (1-r)*v1;
			chrom[choice2][pos] = r*v1 + (1-r)*v2; // �������
			if(chrom[choice1][pos] >=bound_down && chrom[choice1][pos]<=bound_up && chrom[choice2][pos] >=bound_down && chrom[choice2][pos]<=bound_up)
				flag = 1; // ������Ч���˳����棬���������һ�ν���
		}
	}
}

// �������
void Mutation(double chrom[sizepop][lenchrom])
{
	  int  idExit  ;
	
	for(int i=0;i<sizepop;i++)
	{
		//cout<< "\t Mutation(double chrom[sizepop][lenchrom]): i = "<< i <<  endl;
		double pick = ((double)rand())/RAND_MAX; // ���ѡ��һ��Ⱦɫ����б���
		int choice = (int)(pick*sizepop);
		idExit = 0;
		while(choice > sizepop-1)
		{
			pick = ((double)rand())/RAND_MAX;
			int choice = (int)(pick*sizepop);  // �����±�Խ��
			idExit ++ ;
			if( idExit>numsExit  )
			{
				cout<< "force break. "<< endl ;
				break;
			}
		}
		pick = ((double)rand())/RAND_MAX; // ���ھ��������Ƿ���б���
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
		// ע������д���ǲ���Խ��ģ�����ֻ��һ�α���Ϳ�����
	}
}

// ������
int mainGA(void  )
{
	time_t start,  finish;
	start = clock(); // ����ʼ��ʱ
	srand(  ( unsigned  ) time(NULL)  ); // ��ʼ�����������
	init_chrom(); // ��ʼ����Ⱥ
	double * best_fit_index = min_local(fitness);
	int best_index =(int)(*best_fit_index);
	gbest = *(best_fit_index+1); // ����ֵ
	gbest_index = 0;
	average_best[0] = sum(fitness)/sizepop; //��ʼƽ������ֵ
	for(int i=0;i<lenchrom;i++)
	{
		gbest_pos[i] = chrom[best_index][i];
	}
	// ������ʼ
	for(int i=0;i<maxgen;i++)
	{
		try
		{
			Select(chrom); // ѡ��
			Cross(chrom); //����
			Mutation(chrom); //����
			for(int j=0;j<sizepop;j++)
			{
				fitness[j] = fit_func(chrom[j]);
			}
			double sum_fit = sum(fitness);
			average_best[i+1] = sum_fit/sizepop; // ƽ������ֵ
			double * arr = min_local(fitness);
			double new_best = *(arr+1);
			int new_best_index = (int)(*arr); // ������ֵ���
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
	finish = clock(); // ����������
	double duration = ((double)(finish-start))/CLOCKS_PER_SEC;
	printf("��������ʱ:%lf��\n.",duration);
	printf("�Ŵ��㷨������%d�Σ�����ֵΪ:%lf,����ֵ�ڵ�%d��ȡ��,�˴���ƽ������ֵΪ%lf.\n",
		maxgen,gbest,gbest_index,average_best[gbest_index]);
	printf("ȡ������ֵ�ĵط�Ϊ(%lf,%lf,%lf,%lf,%lf).\n",
		gbest_pos[0],gbest_pos[1],gbest_pos[2],gbest_pos[3],gbest_pos[4]);
	cout<<  endl;


	cv::Mat imgShow= cv::Mat( 200,200, CV_8UC3,Scalar(0,0,0 ));
	imshow( "imgShow",  imgShow );
	waitKey(0);
	return 0;
}



