#include "stdio.h"
#include "windows.h"

#include "Array.h"
#include "Structural.h"
#include "LinkedList.h"

#define N 10	/*ѧ������,�����������ѧ�����ݻ����,�޸ĺ��Ӧͷ�ļ��ĺ궨��ҲҪ�޸�*/
#define NEXT 10 /*��������(Name Extent)*/

void InputData(char TempName[N][NEXT], float TempScore[N], int Num)
{
	int i;		/*������*/
	printf("\n");
	for (i = 0;i<Num;i++)
	{
		printf("  *�����%d��ѧ������:", i + 1);
		scanf("%s", TempName[i]);
		printf("  *�����%d��ѧ���ɼ�:", i + 1);
		scanf("%f", &TempScore[i]); //�����&?
	}
	printf("\n\n **¼����Ϣ�ɹ�(��%d��),�����������.**\n\n", Num);
	getch();
}

void Memu(char TempName[N][NEXT], float TempScore[N],int Num)
{
	int i;				/*��Ų�����*/

	system("cls");

	printf("\n \t\t�� \t��\n\n");
	printf(" 1.ֱ�Ӳ�ѯ        2.ת��Ϊ�ṹ���������\n\n");
	printf(" 3.ת��Ϊ�����ѯ  4.�˳�����\n\n");
	printf(" ��ѡ�����:");

	scanf("%d", &i);	/*���������*/

	switch (i)
	{
	case 1 :
		Array(TempName,TempScore,Num);
		getch();
		Memu(TempName,TempScore,Num);
		break;
	case 2 :
		Structural(TempName, TempScore,Num);
		getch();
		Memu(TempName,TempScore,Num);
		break;
	case 3 :
		LinkedList(LinkedList_Initialize(TempName, TempScore,Num));
		getch();
		Memu(TempName,TempScore,Num);
		break;
	case 4 :
		break;
	default:
		printf("\n\n\t     ��ѡ����ȷ����Ŀ.\n");
		getch();
		Memu(TempName, TempScore,Num);
	}
}

int main(void)
{
	char Name[N][NEXT];		 /*ѧ������*/
	float Score[N];			 /*ѧ���ɼ�*/
	int Num;				 /*ѧ������*/

	printf("\n  *������ѧ������(С��%d):", N);
	scanf("%d", &Num);
	system("cls");

	InputData(Name, Score, Num);	 /*����ѧ����Ϣ*/
	Memu(Name, Score, Num);		 /*ʹ�ò˵�ѡ�����*/

	return 0;
}