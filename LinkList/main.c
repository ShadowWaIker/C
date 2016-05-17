#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "time.h"

typedef struct Node
{
	char Name;
	int  Score;
	struct Node *NEXT; /*指向下一个结点*/
}Student, *LinkList;  

LinkList Createlist()/*创建链表*/
{
	LinkList Head; /*头指针*/
	LinkList P;	/*尾指针*/
	LinkList NewNode;
	int i;
	int ListLen;

	system("cls");  //清除屏幕上的内容
	printf("\n\t 请输入要创建的结点个数:");
	scanf("%d", &ListLen);

	NewNode = (Student*)malloc(sizeof(Student));/*分配存储空间*/
	NewNode->NEXT = NULL;

	Head = NewNode;
	P = NewNode;

	srand(time(0));
	for (i = 0;i<ListLen;i++)
	{
		NewNode = (Student*)malloc(sizeof(Student));/*分配存储空间*/
		NewNode->Name = 'a' + i;//添加数据
		NewNode->Score = rand() % 100;
		NewNode->NEXT = NULL;
		P->NEXT = NewNode;//将新节点添加到链表末尾
		P = NewNode;//将尾指针P移动到新链表末尾
	}

	system("cls");  //清除屏幕上的内容
	printf("\n\t新建链表成功.\n");
	printf("\n\t");
	system("pause");
	system("cls");  //清除屏幕上的内容

	return Head;
}

void Printlist(LinkList Head)/*打印链表*/
{
	int flag;
	system("cls");  //清除屏幕上的内容
	if (Head == NULL)
	{
		printf("\n\t 不存在链表，请新建链表.");
		printf("\n\t");
		system("pause");
		system("cls");  //清除屏幕上的内容
		return ; //结束函数
	}
	flag = 0;
	while (Head->NEXT != NULL)
	{
		Head = Head->NEXT;//指针向后移动
		printf("\tName:%c  Score:%d\n", Head->Name, Head->Score);
		flag++;
	}
	printf("\t输出完成，共%d项.", flag);
	printf("\n\t");
	system("pause");
	system("cls");  //清除屏幕上的内容
}

LinkList DeList(LinkList Head)/*删除链表*/
{
	LinkList p;				//临时变量
	LinkList p1;
	int i;
	int Num;

	system("cls");  //清除屏幕上的内容
	if (Head == NULL)
	{
		printf("\n\t 不存在链表，请新建链表.");
		printf("\n\t");
		system("pause");
		system("cls");  //清除屏幕上的内容
		return 0; //结束函数
	}

	p = Head;				//初始化临时变量
	p1 = Head->NEXT;
	printf("\n\t 请输入要删除的结点序号:");
	scanf("%d", &Num);

	for (i = 1;i<Num;i++)		//定位到第Num个节点
	{
		p = p->NEXT;
		p1 = p1->NEXT;
	}

	p->NEXT = p1->NEXT;		//删除节点
	free(p1);				//释放空间

	printf("\n\t 删除结点成功.");
	printf("\n\t");
	system("pause");
	system("cls");  //清除屏幕上的内容
	return Head;
}

LinkList BubbleShortList_1(LinkList Head)  //排序算法(从小到大)
{
	LinkList first;				//临时变量
	LinkList second;
	LinkList temp;
	int ListLen;
	int i;
	int j;
	int flag;

	temp = (Student*)malloc(sizeof(Student));

	system("cls");  //清除屏幕上的内容

	first = Head->NEXT; //统计有效结点时不统计head
	ListLen = 0;
	while (first->NEXT != NULL) //统计链表结点数
	{
		ListLen++;
		first = first->NEXT;
	}

	flag = 1;//初始化排序标志flag
	for (i = 0;i < ListLen;i++)
	{
		first = Head->NEXT; 
		second = first->NEXT; //重新回到链表表头，但是跳过Head结点。

		if (flag == 0) //如果flag为0那么表示没有发生替换
		{
			printf("\n\t排序完成.");
			printf("\n\t");
			system("pause");
			system("cls");  //清除屏幕上的内容
			return Head; //排序完成，结束函数
		}
		else
			flag = 0; //重置flag

		for (j = 0;j < ListLen - i;j++)
		{
			if (first->Score > second->Score) //如果左边的成绩大于右边的就进行替换（替换数据，不交换链表位置）
			{
				temp->Name = first->Name;
				temp->Score = first->Score;
				first->Name = second->Name;
				first->Score = second->Score;
				second->Name = temp->Name;
				second->Score = temp->Score;
				flag++;
			}
			first = first->NEXT;
			second = second->NEXT;
		}
	}

	printf("\n\t排序完成.");
	printf("\n\t");
	system("pause");
	system("cls");  //清除屏幕上的内容
	return Head;
}

LinkList addList(LinkList infoList)
{
	LinkList newinfo;
	system("cls");

	newinfo = infoList;

	while (newinfo->NEXT != NULL) //找到数据链表的尾部
		newinfo = newinfo->NEXT;

	newinfo->NEXT = (Student*)malloc(sizeof(Student));  //添加结点
	newinfo = newinfo->NEXT;							//移动到新结点

	newinfo->Name = 'a' + rand() % 25;//添加数据
	newinfo->Score = rand() % 100;
	newinfo->NEXT = NULL;

	system("cls");
	printf("\n\t");
	printf("添加完成.");
	printf("\n\t");
	system("pause");
	system("cls");
	return infoList;
}

int menu()
{
	int flag;
	do
	{
		printf("\n");
		printf("\t ========= 菜单 =========\n\n");
		printf("\t新建链表 …………………… 1\n\n");
		printf("\t显示链表 …………………… 2\n\n");
		printf("\t添加链表 …………………… 3\n\n");
		printf("\t删除链表 …………………… 4\n\n");
		printf("\t排序链表 …………………… 5\n\n");
		printf("\t退出程序 …………………… 0\n\n");
		printf("\t选择:");
		scanf("%d", &flag); 
		if (flag<0 || flag>7)
		{
			system("cls");  //清除屏幕上的内容
			printf("\n\t 请选择正确的操作.\n\n");
			system("pause");
			system("cls");  //清除屏幕上的内容
		}
	} while (flag<0 || flag>7); //不是菜单中的选项重新显示菜单

	return flag;
}

int main(void)
{
	LinkList Head;
	Head = NULL;

	while (1)
	{
		int flag;
		flag = menu();

		switch (flag)
		{
		case 1:
			Head = Createlist();
			break;
		case 2:
			Printlist(Head);
			break;
		case 3:
			Head = addList(Head);
			break;
		case 4:
			Head = DeList(Head);
			break;
		case 5:
			Head = BubbleShortList_1(Head);
			break;
		case 0: 
			return 0; //主函数中使用 return 可以退出程序, exit(0) 可以在任何地方退出程序
		}
	}
}