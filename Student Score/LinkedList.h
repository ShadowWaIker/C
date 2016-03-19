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

NODE *LinkedList_Initialize(char TempName[][NEXT],float TempScore[],int Num)/*初始化学生信息链表*/
{
	int i; /*计数器*/
	NODE *Head; /*表头指针*/
	NODE *Value;/*数据结点指针*/
	NODE *Operate;/*新建结点指针*/

	Head = (NODE*)malloc(sizeof(NODE));/*建立表头*/
	Value = Head;/*将数据结点指针指向表头*/

	for(i=0;i<Num;i++)/*初始化学生信息链表*/
	{
		strcpy(Value->Name,TempName[i]);
		Value->Score = TempScore[i];
		Operate = (NODE*)malloc(sizeof(NODE)); /*新建结点*/
		Value->Next = Operate;/*将现有表的指针域指向新结点*/
		Value = Operate;/*将数据结点指针指向新结点*/
	}
	return Head;
}

NODE *LinkedList_Search_Max(NODE *Head,int Num) /*寻找成绩最高的学生并返回学生下标*/
{
	int i;
	NODE *Flag; /*储存找到的数据*/

	Flag = Head;

	for (i = 0;i<Num;i++)
	{
		if (Head->Score > Flag->Score)/*如果当前结点数据大于Value就把当前结点的数据赋给Value*/
			Flag = Head;
		Head = Head->Next;/*将结点指针指向下一个结点*/
	}
	return Flag;
} 

NODE *LinkedList_Search_Min(NODE *Head) /*寻找成绩最低的学生并返回学生下标*/
{
	NODE *Flag; /*储存找到的数据*/

	Flag = Head;

	for (;Head->Next != NULL;)
	{
		if (Head->Score < Flag->Score)/*如果当前结点数据大于Value就把当前结点的数据赋给Value*/
			Flag = Head;
		Head = Head->Next;/*将结点指针指向下一个结点*/
	}
	return Flag;
}

void LinkedList(NODE *Head, int Num)/*使用链表查询学生最高(低)成绩*/
{
	NODE *Max;	/*最高成绩下标*/
	NODE *Min;	/*最低成绩下标*/
	Max = LinkedList_Search_Max(Head,Num);
//	Min = LinkedList_Search_Min(Head);
	printf("成绩最高的同学的姓名是:%s(%f分)\n", Max->Name, Max->Score);
//	printf("成绩最低的同学的姓名是:%s(%f分)\n", Min->Name, Min->Score);
}
