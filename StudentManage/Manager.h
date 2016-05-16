#pragma once

#include "stdio.h"
#include "windows.h"

typedef struct //ѧ����Ϣ�ṹ��
{
	int num;
	char name[8]; //�����Ϊ�ĸ�����
	float score[3]; //���ųɼ�
	float ave; //ƽ����
}data;

typedef struct NODE //ѧ����Ϣ���
{
	data DATA;
	struct NODE *NEXT;
}studentInfo; 

studentInfo *head; //ѧ����Ϣ�����ͷ
FILE *fp;		   //�ļ�ָ�루ȫ�֣�
int editFlag;	   //�����޸ı��

void initilization()  //��ʼ������
{
	char flag;
	studentInfo *temp;
	while (1)  //������Ϊ1����ѭ��������һ�����Կ��Ƶ��ظ����������ļ���
	{
		if ((fp = fopen("student.txt", "r+")) == NULL)
		{
			printf("\n\t �ؼ��Դ���:�������ļ�ʧ��.\n\n");
			printf("\n\t �Ƿ��½��ļ�(������ԭ���ļ�) (y/n):");
			scanf("%c", &flag);
			switch (flag)
			{
			case 'Y':
			case 'y':
				if ((fp = fopen("student.txt", "w+")) == NULL)
				{
					system("cls");
					printf("\n\t �½�ʧ��,�����˳�����.");
					system("pause");
					exit(0);
				}
				system("cls");
				printf("\n\t �½��ɹ�.");
				system("pause");
				system("cls");
				break;
			case 'N':
			case 'n':
				system("cls");
				printf("\n\t �����ļ��޷���,�����˳�����.");
				system("pause");
				exit(0);
				break;
			default:
				system("cls");  //�����Ļ�ϵ�����
				printf("\n\t ��ѡ����ȷ�Ĳ���,");
				system("pause");
				system("cls");  //�����Ļ�ϵ�����
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
		temp->NEXT = (studentInfo*)malloc(sizeof(studentInfo)); //�½����Ҫ���ڸ�ֵ���ǰ��.��ֵ��ɺ����½����ᷢ�������һ���ս������.
		temp = temp->NEXT;
		fscanf(fp, "%d%s%f%f%f", &temp->DATA.num, temp->DATA.name, &temp->DATA.score[0], &temp->DATA.score[1], &temp->DATA.score[2]);
		temp->DATA.ave = (temp->DATA.score[0] + temp->DATA.score[1] + temp->DATA.score[2]) / 3.0f;
	}
	temp->NEXT = NULL;
	fclose(fp);
	editFlag = 0;  //�����޸ı��Ϊδ�޸�״̬
}

void printList(studentInfo *infoList)
{
	int num;
	system("cls");  //�����Ļ�ϵ�����
	if (infoList == NULL)
	{
		printf("\n\t ��������Ϣ���������Ϣ.");
		system("pause");
		system("cls");  //�����Ļ�ϵ�����
		return; //��������
	}
	num = 0;
	printf("\n\n\t�� ��\tѧ ��\t�� ��\t�� ��\t�� ѧ\tӢ ��\tƽ �� ��\n");
	while (infoList->NEXT != NULL)
	{
		num++;
		infoList = infoList->NEXT;//ָ������ƶ�
		printf("\t%d\t%d\t%s\t%4.1f\t%4.1f\t%4.1f\t%4.1f\n", num, infoList->DATA.num, infoList->DATA.name, infoList->DATA.score[0], infoList->DATA.score[1], infoList->DATA.score[2], infoList->DATA.ave);
	}
	printf("\n\t�����ɣ���%d��.", num);
	system("pause");
	system("cls");  //�����Ļ�ϵ�����
}

void addList(studentInfo *infoList)
{
	studentInfo *newinfo;
	system("cls");

	while (infoList->NEXT != NULL) //�ҵ����������β��
		infoList = infoList->NEXT;
	
	newinfo = (studentInfo*)malloc(sizeof(studentInfo)); //��ӽ��
	infoList->NEXT = newinfo; //����½ڵ㵽����β��

	printf("\n\n\t����Ҫ��ӵ�ѧ����Ϣ(��ͬ��Ŀ֮����Tab����):");
	printf("\n\n\tѧ ��\t�� ��\t�� ��\t�� ѧ\tӢ ��\n");
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

	system("cls");  //�����Ļ�ϵ�����
	if (infoList == NULL)
	{
		printf("\n\t �������������½�����.");
		system("pause");
		system("cls");  //�����Ļ�ϵ�����
		return; //��������
	}

	printf("\n\t ������Ҫ�޸ĵ���Ϣ���:");
	scanf("%d", &Num);

	for (i = 0;i<Num;i++)		//��λ����Num���ڵ�
	{
		infoList = infoList->NEXT;
	}

	printf("\n\n\t����Ҫ�޸ĵ�ѧ����Ϣ(��ͬ��Ŀ֮����Tab����):");
	printf("\n\n\tѧ ��\t�� ��\t�� ��\t�� ѧ\tӢ ��\n");
	printf("\n\t");
	scanf("%d%s%f%f%f", &infoList->DATA.num, infoList->DATA.name, &infoList->DATA.score[0], &infoList->DATA.score[1], &infoList->DATA.score[2]);
	infoList->DATA.ave = (infoList->DATA.score[0] + infoList->DATA.score[1] + infoList->DATA.score[2]) / 3.0f;
	printf("\n\t �޸���Ϣ�ɹ�.");
	system("pause");
	system("cls");  //�����Ļ�ϵ�����
	editFlag = 1;
}

void delList(studentInfo *infoList)
{
	studentInfo *p;				//��ʱ����
	studentInfo *p1;
	int i;
	int Num;

	system("cls");  //�����Ļ�ϵ�����
	if (head == NULL)
	{
		printf("\n\t �������������½�����.");
		system("pause");
		system("cls");  //�����Ļ�ϵ�����
		return ; //��������
	}

	p = head;				//��ʼ����ʱ����
	p1 = head->NEXT;
	printf("\n\t ������Ҫɾ������Ϣ���:");
	scanf("%d", &Num);

	for (i = 1;i<Num;i++)		//��λ����Num���ڵ�
	{
		p = p->NEXT;
		p1 = p1->NEXT;
	}

	p->NEXT = p1->NEXT;		//ɾ���ڵ�
	free(p1);				//�ͷſռ�

	printf("\n\t ɾ�����ɹ�.");
	system("pause");
	system("cls");  //�����Ļ�ϵ�����
	editFlag = 1;
}

void searchNum(studentInfo *infoList)
{
	int search;		//�����Ҫ������ѧ��
	int searchFlag;	//����������ı�־
	searchFlag = 0;
	system("cls");
	printf("\n\n\t����Ҫ������ѧ��:");
	scanf("%d", &search);
	system("cls");
	printf("\n\n\t�������:");
	printf("\n\n\tѧ ��\t�� ��\t�� ��\t�� ѧ\tӢ ��\tƽ �� ��\n");
	while (infoList->NEXT != NULL)
	{
		infoList = infoList->NEXT;	//ָ������ƶ�
		if (infoList->DATA.num == search)
		{
			printf("\t%d\t%s\t%4.1f\t%4.1f\t%4.1f\t%4.1f\n", infoList->DATA.num, infoList->DATA.name, infoList->DATA.score[0], infoList->DATA.score[1], infoList->DATA.score[2], infoList->DATA.ave);
			searchFlag++;
		}
	}
	if (searchFlag == 0)	//�ж��Ƿ����������
	{
		system("cls");
		printf("\n\n\tû�����������.");
	}
	printf("\n\t");
	system("pause");
	system("cls");
}

void searchName(studentInfo *infoList)
{
	char search[8];	//�����Ҫ����������
	int searchFlag;	//����������ı�־
	searchFlag = 0;
	system("cls");
	printf("\n\n\t����Ҫ����������:");
	scanf("%s", &search);
	system("cls");
	printf("\n\n\t�������:");
	printf("\n\n\tѧ ��\t�� ��\t�� ��\t�� ѧ\tӢ ��\tƽ �� ��\n");
	while (infoList->NEXT != NULL)
	{
		infoList = infoList->NEXT;//ָ������ƶ�
		if (*infoList->DATA.name == *search)  //��Ҫʹ��ȡֵ�����(*)��ȡ�����ַ�������
		{
			printf("\t%d\t%s\t%4.1f\t%4.1f\t%4.1f\t%4.1f\n", infoList->DATA.num, infoList->DATA.name, infoList->DATA.score[0], infoList->DATA.score[1], infoList->DATA.score[2], infoList->DATA.ave);
			searchFlag++;
		}
	}
	if (searchFlag == 0)//�ж��Ƿ����������
	{
		system("cls");
		printf("\n\n\tû�����������.");
	}
	printf("\n\t");
	system("pause");
	system("cls");
}

void BubbleShortList_1(studentInfo *infoList)
{
	studentInfo *first;				//��ʱ����
	studentInfo *second;
	studentInfo *temp;
	int ListLen;
	int i;
	int j;
	int flag;

	temp = (studentInfo*)malloc(sizeof(studentInfo));

	system("cls");  //�����Ļ�ϵ�����

	first = infoList->NEXT; //ͳ����Ч���ʱ��ͳ��head
	ListLen = 0;
	while (first->NEXT != NULL) //ͳ����������
	{
		ListLen++;
		first = first->NEXT;
	}
	flag = 1;//��ʼ�������־flag
	for (i = 0;i < ListLen;i++)
	{
		first = infoList->NEXT;
		second = first->NEXT; //���»ص������ͷ����������Head��㡣

		if (flag == 0) //���flagΪ0��ô��ʾû�з����滻
		{
			printf("\n\t�������.");
			system("pause");
			system("cls");  //�����Ļ�ϵ�����
			return; //������ɣ���������
		}
		else
			flag = 0; //����flag

		for (j = 0;j < ListLen - i - 1;j++) //��ȥ1����ֹ����Խ��
		{
			if (first->DATA.num > second->DATA.num) //�����ߵĴ����ұߵľͽ����滻���滻���ݣ�����������λ�ã�
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

	printf("\n\t�������.");
	system("pause");
	system("cls");  //�����Ļ�ϵ�����
	editFlag = 1;
}

void save(studentInfo *infoList)
{
	int num;	//����ͳ�Ʊ�����Ľ��ĸ���
	num = 0;	//��ʼ������
	if ((fp = fopen("student.txt", "w+")) == NULL)
	{
		system("cls");
		printf("\n\t ����ʧ��.");
		system("pause");
		return ; //�˳�����
	}
	if (infoList->NEXT != NULL)  //��ֹ�������ļ����´ζ�ȡʱ����������Ҫ��֤�������ļ��ʹ�ǰ���ļ��ĸ�ʽ��ͬ�����Ե�һ�е���ǰû�л��з�
	{
		infoList = infoList->NEXT;//ָ������ƶ�
		fprintf(fp, "%d\t%s\t%4.1f\t%4.1f\t%4.1f", infoList->DATA.num, infoList->DATA.name, infoList->DATA.score[0], infoList->DATA.score[1], infoList->DATA.score[2]);
		num++;
	}
	while (infoList->NEXT != NULL) //�ѻ��з����ڵڶ�����ǰ���������к󣬷�ֹ���һ�ж�����Ļ��з�Ӱ����һ�ζ�ȡ
	{
		infoList = infoList->NEXT;//ָ������ƶ�
		fprintf(fp,"\n%d\t%s\t%4.1f\t%4.1f\t%4.1f", infoList->DATA.num, infoList->DATA.name, infoList->DATA.score[0], infoList->DATA.score[1], infoList->DATA.score[2]);
		num++;
	}
	fclose(fp);
	system("cls");
	printf("\n\t ����ɹ�,��������%d������.",num);
	system("pause");
	system("cls");
}