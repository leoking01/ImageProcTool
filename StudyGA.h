#pragma once

//�������ó��� 
// https://www.cnblogs.com/lyrichu/p/6152897.html#undefined
/*
* �Ŵ��㷨��⺯��������ֵ����
* �ο��ԡ�MATLAB�����㷨30������������
* ������Ѱ�ź���Ϊ:f = -5*sin(x1)*sin(x2)*sin(x3)*sin(x4)*sin(x5) - sin(5*x1)*sin(5*x2)*sin(5*x3)*sin(5*x4)*sin(5*x5) + 8
* ����x1,x2,x3,x4,x5��0~0.9*PI֮���ʵ�����ú�������СֵΪ2,��x1,x2,x3,x4,x5��ȡPI/2ʱ�õ���
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
#define PI 3.1415926   //Բ����
#define sizepop 50     // ��Ⱥ��Ŀ
#define maxgen 500     // ��������
#define pcross 0.6     // �������
#define pmutation 0.1     // �������
#define lenchrom 5        // Ⱦɫ�峤��
#define bound_down 0      // �����½磬������Ϊ����ͬ�����Ծ��õ���ֵȥ�����ˣ����ÿ���������½粻ͬ��Ҳ����Ҫ�����鶨��
#define bound_up (0.9*3.1415926)      // �Ͻ�

const int  numsExit = 400;   //  ֵ����ѭ����������


class StudyGA
{
public:
	StudyGA(void);
	~StudyGA(void);
};

int mainGA(void);
double *   min_local(  double * fitness);

