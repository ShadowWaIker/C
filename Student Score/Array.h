#pragma once
#define NEXT 10 /*姓名长度(Name Extent)*/

int Array_Search_Max(float SearchScore[], int Num) /*寻找成绩最高的学生并返回学生下标*/
{
	int i;/*计数器*/
	int Flag;
	float Value; /*储存找到的数据*/
	Value = SearchScore[0];
	Flag = 0;
	for (i = 0;i<Num;i++)
		if (SearchScore[i]>Value)
		{
			Value = SearchScore[i];
			Flag = i;
		}
	return Flag;
} 

int Array_Search_Min(float SearchScore[], int Num) /*寻找成绩最低的学生并返回学生下标*/
{
	int i;/*计数器*/
	int Flag;
	float Value; /*储存找到的数据*/
	Value = SearchScore[0];
	Flag = 0;
	for (i = 0;i<Num;i++)
		if (SearchScore[i]<Value)
		{
			Value = SearchScore[i];
			Flag = i;
		}
	return Flag;
}

void Array(char TempName[][NEXT], float TempScore[], int Num) /*使用数组查询学生最高(低)成绩*/
{
	int Max;	/*最高成绩下标*/
	int Min;	/*最低成绩下标*/
	Max = Array_Search_Max(TempScore, Num);
	Min = Array_Search_Min(TempScore, Num);
	printf("成绩最高的同学的姓名是:%s(%f分)\n", TempName[Max], TempScore[Max]);
	printf("成绩最低的同学的姓名是:%s(%f分)\n", TempName[Min], TempScore[Min]);
}
