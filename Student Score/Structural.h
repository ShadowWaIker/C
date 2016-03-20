#pragma once
#include "string.h" /*尽量不在头文件中包含另外的头文件*/
#define N 10
#define NEXT 10 /*姓名长度(Name Extent)*/

typedef struct { /*学生信息结构*/
	char  Name[NEXT];  /*学生姓名*/
	float Score;	   /*学生成绩*/
}STUDENTINFO;

int Structural_Search_Max(STUDENTINFO TempStudent[], int Num) /*寻找成绩最高的学生并返回学生下标*/
{
	int i;/*计数器*/
	int Flag;
	float Value; /*储存找到的数据*/
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

int Structural_Search_Min(STUDENTINFO TempStudent[], int Num) /*寻找成绩最低的学生并返回学生下标*/
{
	int i;/*计数器*/
	int Flag;
	float Value; /*储存找到的数据*/
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

void Structural(char TempName[][NEXT], float TempScore[], int Num)/*使用结构体查询学生最高(低)成绩*/
{
	int i;		/*计数器*/
	int Max;	/*最高成绩下标*/
	int Min;	/*最低成绩下标*/
	STUDENTINFO Student[N];


	for (i = 0;i < Num;i++) /*初始化学生信息结构体数组*/
	{
		strcpy(Student[i].Name, TempName[i]); /*使用Student[i].Name,TempName[i]出现编译错误，因为左右两端都是代表地址，不能进行赋值，所以使用"string.h"中的strcpy()函数将数组进行复制*/
		Student[i].Score = TempScore[i];
	}

	Max = Structural_Search_Max(Student, Num);
	Min = Structural_Search_Min(Student, Num);
	printf("\n\t成绩最高的同学的姓名是:%s(%f分)\n", Student[Max].Name, Student[Max].Score);
	printf("\n\t成绩最低的同学的姓名是:%s(%f分)\n", Student[Min].Name, Student[Min].Score);
}