#pragma once

#include "stdio.h"
#include "windows.h"

typedef struct //学生信息结构体
{
	int num;
	char name[8]; //名字最长为四个汉字
	float score[3]; //三门成绩
	float ave; //平均分
}data;

typedef struct NODE //学生信息结点
{
	data DATA;
	struct NODE *NEXT;
}studentInfo; 

studentInfo *head; //学生信息链表表头
FILE *fp;		   //文件指针（全局）
int editFlag;	   //数据修改标记

void initilization()  //初始化数据
{
	char flag;
	studentInfo *temp;
	while (1)  //用条件为1的死循环来进行一个可以控制的重复操作（打开文件）
	{
		if ((fp = fopen("student.txt", "r+")) == NULL)
		{
			printf("\n\t 关键性错误:打开数据文件失败.\n\n");
			printf("\n\t 是否新建文件(将覆盖原有文件) (y/n):");
			scanf("%c", &flag);
			switch (flag)
			{
			case 'Y':
			case 'y':
				if ((fp = fopen("student.txt", "w+")) == NULL)
				{
					system("cls");
					printf("\n\t 新建失败,即将退出程序.");
					system("pause");
					exit(0);
				}
				system("cls");
				printf("\n\t 新建成功.");
				system("pause");
				system("cls");
				break;
			case 'N':
			case 'n':
				system("cls");
				printf("\n\t 数据文件无法打开,即将退出程序.");
				system("pause");
				exit(0);
				break;
			default:
				system("cls");  //清除屏幕上的内容
				printf("\n\t 请选择正确的操作,");
				system("pause");
				system("cls");  //清除屏幕上的内容
				break;
			}
		}
		else
			break;
	}
	head = (studentInfo*)malloc(sizeof(studentInfo));
	temp = head;
	head->NEXT = temp;
	while (!feof(fp))
	{
		temp->NEXT = (studentInfo*)malloc(sizeof(studentInfo)); //新建结点要放在赋值语句前面.赋值完成后再新建结点会发生多出来一个空结点的情况.
		temp = temp->NEXT;
		fscanf(fp, "%d%s%f%f%f", &temp->DATA.num, temp->DATA.name, &temp->DATA.score[0], &temp->DATA.score[1], &temp->DATA.score[2]);
		temp->DATA.ave = (temp->DATA.score[0] + temp->DATA.score[1] + temp->DATA.score[2]) / 3.0f;
	}
	temp->NEXT = NULL;
	fclose(fp);
	editFlag = 0;  //数据修改标记为未修改状态
}

void printList(studentInfo *infoList)
{
	int num;
	system("cls");  //清除屏幕上的内容
	if (infoList == NULL)
	{
		printf("\n\t 不存在信息，请添加信息.");
		system("pause");
		system("cls");  //清除屏幕上的内容
		return; //结束函数
	}
	num = 0;
	printf("\n\n\t序 号\t学 号\t姓 名\t语 文\t数 学\t英 语\t平 均 分\n");
	while (infoList->NEXT != NULL)
	{
		num++;
		infoList = infoList->NEXT;//指针向后移动
		printf("\t%d\t%d\t%s\t%4.1f\t%4.1f\t%4.1f\t%4.1f\n", num, infoList->DATA.num, infoList->DATA.name, infoList->DATA.score[0], infoList->DATA.score[1], infoList->DATA.score[2], infoList->DATA.ave);
	}
	printf("\n\t输出完成，共%d项.", num);
	system("pause");
	system("cls");  //清除屏幕上的内容
}

void addList(studentInfo *infoList)
{
	studentInfo *newinfo;
	system("cls");

	while (infoList->NEXT != NULL) //找到数据链表的尾部
		infoList = infoList->NEXT;
	
	newinfo = (studentInfo*)malloc(sizeof(studentInfo)); //添加结点
	infoList->NEXT = newinfo; //添加新节点到链表尾部

	printf("\n\n\t输入要添加的学生信息(不同项目之间用Tab隔开):");
	printf("\n\n\t学 号\t姓 名\t语 文\t数 学\t英 语\n");
	printf("\n\t");
	scanf("%d%s%f%f%f", &newinfo->DATA.num, newinfo->DATA.name, &newinfo->DATA.score[0], &newinfo->DATA.score[1], &newinfo->DATA.score[2]);
	newinfo->DATA.ave = (newinfo->DATA.score[0] + newinfo->DATA.score[1] + newinfo->DATA.score[2]) / 3.0f;
	newinfo->NEXT = NULL;
	system("cls");
	editFlag = 1;
}

void modify(studentInfo *infoList)
{
	int i;
	int Num;

	system("cls");  //清除屏幕上的内容
	if (infoList == NULL)
	{
		printf("\n\t 不存在链表，请新建链表.");
		system("pause");
		system("cls");  //清除屏幕上的内容
		return; //结束函数
	}

	printf("\n\t 请输入要修改的信息序号:");
	scanf("%d", &Num);

	for (i = 0;i<Num;i++)		//定位到第Num个节点
	{
		infoList = infoList->NEXT;
	}

	printf("\n\n\t输入要修改的学生信息(不同项目之间用Tab隔开):");
	printf("\n\n\t学 号\t姓 名\t语 文\t数 学\t英 语\n");
	printf("\n\t");
	scanf("%d%s%f%f%f", &infoList->DATA.num, infoList->DATA.name, &infoList->DATA.score[0], &infoList->DATA.score[1], &infoList->DATA.score[2]);
	infoList->DATA.ave = (infoList->DATA.score[0] + infoList->DATA.score[1] + infoList->DATA.score[2]) / 3.0f;
	printf("\n\t 修改信息成功.");
	system("pause");
	system("cls");  //清除屏幕上的内容
	editFlag = 1;
}

void delList(studentInfo *infoList)
{
	studentInfo *p;				//临时变量
	studentInfo *p1;
	int i;
	int Num;

	system("cls");  //清除屏幕上的内容
	if (head == NULL)
	{
		printf("\n\t 不存在链表，请新建链表.");
		system("pause");
		system("cls");  //清除屏幕上的内容
		return ; //结束函数
	}

	p = head;				//初始化临时变量
	p1 = head->NEXT;
	printf("\n\t 请输入要删除的信息序号:");
	scanf("%d", &Num);

	for (i = 1;i<Num;i++)		//定位到第Num个节点
	{
		p = p->NEXT;
		p1 = p1->NEXT;
	}

	p->NEXT = p1->NEXT;		//删除节点
	free(p1);				//释放空间

	printf("\n\t 删除结点成功.");
	system("pause");
	system("cls");  //清除屏幕上的内容
	editFlag = 1;
}

void searchNum(studentInfo *infoList)
{
	int search;		//存放需要搜索的学号
	int searchFlag;	//搜索到结果的标志
	searchFlag = 0;
	system("cls");
	printf("\n\n\t输入要搜索的学号:");
	scanf("%d", &search);
	system("cls");
	printf("\n\n\t搜索结果:");
	printf("\n\n\t学 号\t姓 名\t语 文\t数 学\t英 语\t平 均 分\n");
	while (infoList->NEXT != NULL)
	{
		infoList = infoList->NEXT;	//指针向后移动
		if (infoList->DATA.num == search)
		{
			printf("\t%d\t%s\t%4.1f\t%4.1f\t%4.1f\t%4.1f\n", infoList->DATA.num, infoList->DATA.name, infoList->DATA.score[0], infoList->DATA.score[1], infoList->DATA.score[2], infoList->DATA.ave);
			searchFlag++;
		}
	}
	if (searchFlag == 0)	//判断是否搜索到结果
	{
		system("cls");
		printf("\n\n\t没有搜索到结果.");
	}
	printf("\n\t");
	system("pause");
	system("cls");
}

void searchName(studentInfo *infoList)
{
	char search[8];	//存放需要搜索的姓名
	int searchFlag;	//搜索到结果的标志
	searchFlag = 0;
	system("cls");
	printf("\n\n\t输入要搜索的姓名:");
	scanf("%s", &search);
	system("cls");
	printf("\n\n\t搜索结果:");
	printf("\n\n\t学 号\t姓 名\t语 文\t数 学\t英 语\t平 均 分\n");
	while (infoList->NEXT != NULL)
	{
		infoList = infoList->NEXT;//指针向后移动
		if (*infoList->DATA.name == *search)  //需要使用取值运算符(*)获取这个地址里的数据
		{
			printf("\t%d\t%s\t%4.1f\t%4.1f\t%4.1f\t%4.1f\n", infoList->DATA.num, infoList->DATA.name, infoList->DATA.score[0], infoList->DATA.score[1], infoList->DATA.score[2], infoList->DATA.ave);
			searchFlag++;
		}
	}
	if (searchFlag == 0)//判断是否搜索到结果
	{
		system("cls");
		printf("\n\n\t没有搜索到结果.");
	}
	printf("\n\t");
	system("pause");
	system("cls");
}

void BubbleShortList_1(studentInfo *infoList)
{
	studentInfo *first;				//临时变量
	studentInfo *second;
	studentInfo *temp;
	int ListLen;
	int i;
	int j;
	int flag;

	temp = (studentInfo*)malloc(sizeof(studentInfo));

	system("cls");  //清除屏幕上的内容

	first = infoList->NEXT; //统计有效结点时不统计head
	ListLen = 0;
	while (first->NEXT != NULL) //统计链表结点数
	{
		ListLen++;
		first = first->NEXT;
	}
	flag = 1;//初始化排序标志flag
	for (i = 0;i < ListLen;i++)
	{
		first = infoList->NEXT;
		second = first->NEXT; //重新回到链表表头，但是跳过Head结点。

		if (flag == 0) //如果flag为0那么表示没有发生替换
		{
			printf("\n\t排序完成.");
			system("pause");
			system("cls");  //清除屏幕上的内容
			return; //排序完成，结束函数
		}
		else
			flag = 0; //重置flag

		for (j = 0;j < ListLen - i - 1;j++) //减去1，防止发生越界
		{
			if (first->DATA.num > second->DATA.num) //如果左边的大于右边的就进行替换（替换数据，不交换链表位置）
			{
				temp->DATA = first->DATA;
				first->DATA = second->DATA;
				second->DATA = temp->DATA;
				flag++;
			}
			first = first->NEXT;
			second = second->NEXT;
		}
	}

	printf("\n\t排序完成.");
	system("pause");
	system("cls");  //清除屏幕上的内容
	editFlag = 1;
}

void save(studentInfo *infoList)
{
	int num;	//用来统计被保存的结点的个数
	num = 0;	//初始化变量
	if ((fp = fopen("student.txt", "w+")) == NULL)
	{
		system("cls");
		printf("\n\t 保存失败.");
		system("pause");
		return ; //退出函数
	}
	if (infoList->NEXT != NULL)  //防止保存后的文件在下次读取时发生错误，需要保证保存后的文件和打开前的文件的格式相同，所以第一行的行前没有换行符
	{
		infoList = infoList->NEXT;//指针向后移动
		fprintf(fp, "%d\t%s\t%4.1f\t%4.1f\t%4.1f", infoList->DATA.num, infoList->DATA.name, infoList->DATA.score[0], infoList->DATA.score[1], infoList->DATA.score[2]);
		num++;
	}
	while (infoList->NEXT != NULL) //把换行符放在第二行行前，而不是行后，防止最后一行多出来的换行符影响下一次读取
	{
		infoList = infoList->NEXT;//指针向后移动
		fprintf(fp,"\n%d\t%s\t%4.1f\t%4.1f\t%4.1f", infoList->DATA.num, infoList->DATA.name, infoList->DATA.score[0], infoList->DATA.score[1], infoList->DATA.score[2]);
		num++;
	}
	fclose(fp);
	system("cls");
	printf("\n\t 保存成功,共保存了%d条数据.",num);
	system("pause");
	system("cls");
}