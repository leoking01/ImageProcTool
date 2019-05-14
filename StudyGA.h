#pragma once

//代码引用出处 
// https://www.cnblogs.com/lyrichu/p/6152897.html#undefined
/*
* 遗传算法求解函数的最优值问题
* 参考自《MATLAB智能算法30个案例分析》
* 本例的寻优函数为:f = -5*sin(x1)*sin(x2)*sin(x3)*sin(x4)*sin(x5) - sin(5*x1)*sin(5*x2)*sin(5*x3)*sin(5*x4)*sin(5*x5) + 8
* 其中x1,x2,x3,x4,x5是0~0.9*PI之间的实数。该函数的最小值为2,当x1,x2,x3,x4,x5都取PI/2时得到。
* update in 16/12/3
* author:Lyrichu
* email:919987476@qq.com
*/
#include<iostream>
using namespace  std;


#include<opencv2/opencv.hpp>
using namespace  cv;

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define PI 3.1415926   //圆周率
#define sizepop 50     // 种群数目
#define maxgen 500     // 进化代数
#define pcross 0.6     // 交叉概率
#define pmutation 0.1     // 变异概率
#define lenchrom 5        // 染色体长度
#define bound_down 0      // 变量下界，这里因为都相同，所以就用单个值去代替了，如果每个变量上下界不同，也许需要用数组定义
#define bound_up (0.9*3.1415926)      // 上界

const int  numsExit = 400;   //  值更新循环次数上限


class StudyGA
{
public:
	StudyGA(void);
	~StudyGA(void);
};

int mainGA(void);
double *   min_local(  double * fitness);

