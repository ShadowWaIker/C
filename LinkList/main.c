#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "time.h"

typedef struct Node
{
	char Name;
	int  Score;
	struct Node *NEXT; /*ָ����һ�����*/
}Student, *LinkList;  

LinkList Createlist()/*��������*/
{
	LinkList Head; /*ͷָ��*/
	LinkList P;	/*βָ��*/
	LinkList NewNode;
	int i;
	int ListLen;

	system("cls");  //�����Ļ�ϵ�����
	printf("\n\t ������Ҫ�����Ľ�����:");
	scanf("%d", &ListLen);

	NewNode = (Student*)malloc(sizeof(Student));/*����洢�ռ�*/
	NewNode->NEXT = NULL;

	Head = NewNode;
	P = NewNode;

	srand(time(0));
	for (i = 0;i<ListLen;i++)
	{
		NewNode = (Student*)malloc(sizeof(Student));/*����洢�ռ�*/
		NewNode->Name = 'a' + i;//�������
		NewNode->Score = rand() % 100;
		NewNode->NEXT = NULL;
		P->NEXT = NewNode;//���½ڵ���ӵ�����ĩβ
		P = NewNode;//��βָ��P�ƶ���������ĩβ
	}

	system("cls");  //�����Ļ�ϵ�����
	printf("\n\t�½�����ɹ�.\n");
	printf("\n\t");
	system("pause");
	system("cls");  //�����Ļ�ϵ�����

	return Head;
}

void Printlist(LinkList Head)/*��ӡ����*/
{
	int flag;
	system("cls");  //�����Ļ�ϵ�����
	if (Head == NULL)
	{
		printf("\n\t �������������½�����.");
		printf("\n\t");
		system("pause");
		system("cls");  //�����Ļ�ϵ�����
		return ; //��������
	}
	flag = 0;
	while (Head->NEXT != NULL)
	{
		Head = Head->NEXT;//ָ������ƶ�
		printf("\tName:%c  Score:%d\n", Head->Name, Head->Score);
		flag++;
	}
	printf("\t�����ɣ���%d��.", flag);
	printf("\n\t");
	system("pause");
	system("cls");  //�����Ļ�ϵ�����
}

LinkList DeList(LinkList Head)/*ɾ������*/
{
	LinkList p;				//��ʱ����
	LinkList p1;
	int i;
	int Num;

	system("cls");  //�����Ļ�ϵ�����
	if (Head == NULL)
	{
		printf("\n\t �������������½�����.");
		printf("\n\t");
		system("pause");
		system("cls");  //�����Ļ�ϵ�����
		return 0; //��������
	}

	p = Head;				//��ʼ����ʱ����
	p1 = Head->NEXT;
	printf("\n\t ������Ҫɾ���Ľ�����:");
	scanf("%d", &Num);

	for (i = 1;i<Num;i++)		//��λ����Num���ڵ�
	{
		p = p->NEXT;
		p1 = p1->NEXT;
	}

	p->NEXT = p1->NEXT;		//ɾ���ڵ�
	free(p1);				//�ͷſռ�

	printf("\n\t ɾ�����ɹ�.");
	printf("\n\t");
	system("pause");
	system("cls");  //�����Ļ�ϵ�����
	return Head;
}

LinkList BubbleShortList_1(LinkList Head)  //�����㷨(��С����)
{
	LinkList first;				//��ʱ����
	LinkList second;
	LinkList temp;
	int ListLen;
	int i;
	int j;
	int flag;

	temp = (Student*)malloc(sizeof(Student));

	system("cls");  //�����Ļ�ϵ�����

	first = Head->NEXT; //ͳ����Ч���ʱ��ͳ��head
	ListLen = 0;
	while (first->NEXT != NULL) //ͳ����������
	{
		ListLen++;
		first = first->NEXT;
	}

	flag = 1;//��ʼ�������־flag
	for (i = 0;i < ListLen;i++)
	{
		first = Head->NEXT; 
		second = first->NEXT; //���»ص������ͷ����������Head��㡣

		if (flag == 0) //���flagΪ0��ô��ʾû�з����滻
		{
			printf("\n\t�������.");
			printf("\n\t");
			system("pause");
			system("cls");  //�����Ļ�ϵ�����
			return Head; //������ɣ���������
		}
		else
			flag = 0; //����flag

		for (j = 0;j < ListLen - i;j++)
		{
			if (first->Score > second->Score) //�����ߵĳɼ������ұߵľͽ����滻���滻���ݣ�����������λ�ã�
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

	printf("\n\t�������.");
	printf("\n\t");
	system("pause");
	system("cls");  //�����Ļ�ϵ�����
	return Head;
}

LinkList addList(LinkList infoList)
{
	LinkList newinfo;
	system("cls");

	newinfo = infoList;

	while (newinfo->NEXT != NULL) //�ҵ����������β��
		newinfo = newinfo->NEXT;

	newinfo->NEXT = (Student*)malloc(sizeof(Student));  //��ӽ��
	newinfo = newinfo->NEXT;							//�ƶ����½��

	newinfo->Name = 'a' + rand() % 25;//�������
	newinfo->Score = rand() % 100;
	newinfo->NEXT = NULL;

	system("cls");
	printf("\n\t");
	printf("������.");
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
		printf("\t ========= �˵� =========\n\n");
		printf("\t�½����� ���������������� 1\n\n");
		printf("\t��ʾ���� ���������������� 2\n\n");
		printf("\t������� ���������������� 3\n\n");
		printf("\tɾ������ ���������������� 4\n\n");
		printf("\t�������� ���������������� 5\n\n");
		printf("\t�˳����� ���������������� 0\n\n");
		printf("\tѡ��:");
		scanf("%d", &flag); 
		if (flag<0 || flag>7)
		{
			system("cls");  //�����Ļ�ϵ�����
			printf("\n\t ��ѡ����ȷ�Ĳ���.\n\n");
			system("pause");
			system("cls");  //�����Ļ�ϵ�����
		}
	} while (flag<0 || flag>7); //���ǲ˵��е�ѡ��������ʾ�˵�

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
			return 0; //��������ʹ�� return �����˳�����, exit(0) �������κεط��˳�����
		}
	}
}