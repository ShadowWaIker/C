#pragma once
#define NEXT 10 /*��������(Name Extent)*/

int Array_Search_Max(float SearchScore[], int Num) /*Ѱ�ҳɼ���ߵ�ѧ��������ѧ���±�*/
{
	int i;/*������*/
	int Flag;
	float Value; /*�����ҵ�������*/
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

int Array_Search_Min(float SearchScore[], int Num) /*Ѱ�ҳɼ���͵�ѧ��������ѧ���±�*/
{
	int i;/*������*/
	int Flag;
	float Value; /*�����ҵ�������*/
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

void Array(char TempName[][NEXT], float TempScore[], int Num) /*ʹ�������ѯѧ�����(��)�ɼ�*/
{
	int Max;	/*��߳ɼ��±�*/
	int Min;	/*��ͳɼ��±�*/
	Max = Array_Search_Max(TempScore, Num);
	Min = Array_Search_Min(TempScore, Num);
	printf("�ɼ���ߵ�ͬѧ��������:%s(%f��)\n", TempName[Max], TempScore[Max]);
	printf("�ɼ���͵�ͬѧ��������:%s(%f��)\n", TempName[Min], TempScore[Min]);
}
