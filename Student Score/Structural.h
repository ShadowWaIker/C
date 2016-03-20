#pragma once
#include "string.h" /*��������ͷ�ļ��а��������ͷ�ļ�*/
#define N 10
#define NEXT 10 /*��������(Name Extent)*/

typedef struct { /*ѧ����Ϣ�ṹ*/
	char  Name[NEXT];  /*ѧ������*/
	float Score;	   /*ѧ���ɼ�*/
}STUDENTINFO;

int Structural_Search_Max(STUDENTINFO TempStudent[], int Num) /*Ѱ�ҳɼ���ߵ�ѧ��������ѧ���±�*/
{
	int i;/*������*/
	int Flag;
	float Value; /*�����ҵ�������*/
	Value = TempStudent[0].Score;
	Flag = 0;
	for (i = 0;i<Num;i++)
		if (TempStudent[i].Score>Value)
		{
			Value = TempStudent[i].Score;
			Flag = i;
		}
	return Flag;
}

int Structural_Search_Min(STUDENTINFO TempStudent[], int Num) /*Ѱ�ҳɼ���͵�ѧ��������ѧ���±�*/
{
	int i;/*������*/
	int Flag;
	float Value; /*�����ҵ�������*/
	Value = TempStudent[0].Score;
	Flag = 0;
	for (i = 0;i<Num;i++)
		if (TempStudent[i].Score<Value)
		{
			Value = TempStudent[i].Score;
			Flag = i;
		}
	return Flag;
}

void Structural(char TempName[][NEXT], float TempScore[], int Num)/*ʹ�ýṹ���ѯѧ�����(��)�ɼ�*/
{
	int i;		/*������*/
	int Max;	/*��߳ɼ��±�*/
	int Min;	/*��ͳɼ��±�*/
	STUDENTINFO Student[N];


	for (i = 0;i < Num;i++) /*��ʼ��ѧ����Ϣ�ṹ������*/
	{
		strcpy(Student[i].Name, TempName[i]); /*ʹ��Student[i].Name,TempName[i]���ֱ��������Ϊ�������˶��Ǵ����ַ�����ܽ��и�ֵ������ʹ��"string.h"�е�strcpy()������������и���*/
		Student[i].Score = TempScore[i];
	}

	Max = Structural_Search_Max(Student, Num);
	Min = Structural_Search_Min(Student, Num);
	printf("\n\t�ɼ���ߵ�ͬѧ��������:%s(%f��)\n", Student[Max].Name, Student[Max].Score);
	printf("\n\t�ɼ���͵�ͬѧ��������:%s(%f��)\n", Student[Min].Name, Student[Min].Score);
}