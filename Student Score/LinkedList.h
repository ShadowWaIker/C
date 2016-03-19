#pragma once
#define NEXT 10
#include "stdlib.h"
#include "string.h"

typedef struct Node
{
	char Name[NEXT];
	float Score;
	struct Node *Next;
} NODE;

NODE *LinkedList_Initialize(char TempName[][NEXT],float TempScore[],int Num)/*��ʼ��ѧ����Ϣ����*/
{
	int i; /*������*/
	NODE *Head; /*��ͷָ��*/
	NODE *Value;/*���ݽ��ָ��*/
	NODE *Operate;/*�½����ָ��*/

	Head = (NODE*)malloc(sizeof(NODE));/*������ͷ*/
	Value = Head;/*�����ݽ��ָ��ָ���ͷ*/

	for(i=0;i<Num;i++)/*��ʼ��ѧ����Ϣ����*/
	{
		strcpy(Value->Name,TempName[i]);
		Value->Score = TempScore[i];
		Operate = (NODE*)malloc(sizeof(NODE)); /*�½����*/
		Value->Next = Operate;/*�����б��ָ����ָ���½��*/
		Value = Operate;/*�����ݽ��ָ��ָ���½��*/
	}
	return Head;
}

NODE *LinkedList_Search_Max(NODE *Head,int Num) /*Ѱ�ҳɼ���ߵ�ѧ��������ѧ���±�*/
{
	int i;
	NODE *Flag; /*�����ҵ�������*/

	Flag = Head;

	for (i = 0;i<Num;i++)
	{
		if (Head->Score > Flag->Score)/*�����ǰ������ݴ���Value�Ͱѵ�ǰ�������ݸ���Value*/
			Flag = Head;
		Head = Head->Next;/*�����ָ��ָ����һ�����*/
	}
	return Flag;
} 

NODE *LinkedList_Search_Min(NODE *Head) /*Ѱ�ҳɼ���͵�ѧ��������ѧ���±�*/
{
	NODE *Flag; /*�����ҵ�������*/

	Flag = Head;

	for (;Head->Next != NULL;)
	{
		if (Head->Score < Flag->Score)/*�����ǰ������ݴ���Value�Ͱѵ�ǰ�������ݸ���Value*/
			Flag = Head;
		Head = Head->Next;/*�����ָ��ָ����һ�����*/
	}
	return Flag;
}

void LinkedList(NODE *Head, int Num)/*ʹ�������ѯѧ�����(��)�ɼ�*/
{
	NODE *Max;	/*��߳ɼ��±�*/
	NODE *Min;	/*��ͳɼ��±�*/
	Max = LinkedList_Search_Max(Head,Num);
//	Min = LinkedList_Search_Min(Head);
	printf("�ɼ���ߵ�ͬѧ��������:%s(%f��)\n", Max->Name, Max->Score);
//	printf("�ɼ���͵�ͬѧ��������:%s(%f��)\n", Min->Name, Min->Score);
}
