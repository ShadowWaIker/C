#include "stdio.h"
#include "windows.h"

#include "Array.h"
#include "Structural.h"
#include "LinkedList.h"

#define N 10	/*学生个数,定义个数多于学生数据会出错,修改后对应头文件的宏定义也要修改*/
#define NEXT 10 /*姓名长度(Name Extent)*/

void InputData(char TempName[N][NEXT], float TempScore[N], int Num)
{
	int i;		/*计数器*/
	printf("\n");
	for (i = 0;i<Num;i++)
	{
		printf("  *输入第%d个学生姓名:", i + 1);
		scanf("%s", TempName[i]);
		printf("  *输入第%d个学生成绩:", i + 1);
		scanf("%f", &TempScore[i]); //必须加&?
	}
	printf("\n\n **录入信息成功(共%d个),按任意键继续.**\n\n", Num);
	getch();
}

void Memu(char TempName[N][NEXT], float TempScore[N],int Num)
{
	int i;				/*存放操作数*/

	system("cls");

	printf("\n \t\t菜 \t单\n\n");
	printf(" 1.直接查询        2.转化为结构体数组操作\n\n");
	printf(" 3.转化为链表查询  4.退出程序\n\n");
	printf(" 请选择操作:");

	scanf("%d", &i);	/*输入操作数*/

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
		printf("\n\n\t     请选择正确的项目.\n");
		getch();
		Memu(TempName, TempScore,Num);
	}
}

int main(void)
{
	char Name[N][NEXT];		 /*学生姓名*/
	float Score[N];			 /*学生成绩*/
	int Num;				 /*学生个数*/

	printf("\n  *请输入学生总数(小于%d):", N);
	scanf("%d", &Num);
	system("cls");

	InputData(Name, Score, Num);	 /*输入学生信息*/
	Memu(Name, Score, Num);		 /*使用菜单选择操作*/

	return 0;
}