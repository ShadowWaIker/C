#include "Manager.h"	 //自定义头文件,用来存放实现功能的函数.

int main(viod)
{
	char chooseSave;
	int flag;

	initilization();	 //初始化

	while (1)			 //用条件为1的死循环来进行一个可以控制的重复操作
	{
		do
		{
			printf("\n");
			printf("\t === 学生信息管理系统 ===\n\n");
			printf("\t ========= 菜单 =========\n\n");
			printf("\t查看信息 …………………… 1\n\n");
			printf("\t添加信息 …………………… 2\n\n");
			printf("\t修改信息 …………………… 3\n\n");
			printf("\t删除信息 …………………… 4\n\n");
			printf("\t查询信息 (学号)  ………… 5\n\n");
			printf("\t查询信息 (姓名)  ………… 6\n\n");
			printf("\t按学号从小到大重排序 …… 7\n\n");
			printf("\t保存到文件 ………………… 8\n\n");
			printf("\t退出程序 …………………… 0\n\n");
			printf("\t选择:");
			scanf("%d", &flag);
		} while (flag<0 || flag>8); //不是菜单中的选项重新显示菜单

		switch (flag)
		{
		case 0:
			if (editFlag != 0) 				 //发生数据修改，询问是否保存
			{
				system("cls");
				printf("\n\t修改后的文件没有保存,是否保存(Y/N):");
				scanf("%s", &chooseSave);
				switch (chooseSave)
				{
				case 'Y':
				case 'y':
					save(head);
					exit(0);	//在这里使用return 0;会导致chooseSave溢出
				case 'N':
				case 'n':
					system("cls");
					printf("\n\t即将退出程序.");
					system("pause");
					exit (0);
					break;
				default:
					system("cls");  //清除屏幕上的内容
					printf("\n\t 请选择正确的操作,");
					system("pause");
					system("cls");  //清除屏幕上的内容
					break;
				}
			}
			else			//如果没发生数据修改就直接退出
				return 0;	//主函数中使用 return 可以退出程序, exit(0) 可以在任何地方退出程序
			break;
		case 1:
			printList(head);
			break;
		case 2:
			addList(head);
			break;
		case 3:
			modify(head);
			break;
		case 4:
			delList(head);
			break;
		case 5:
			searchNum(head);
			break;
		case 6:
			searchName(head);
			break;
		case 7:
			BubbleShortList_1(head);
			break;
		case 8:
			save(head);
			break;
		default:
			system("cls");  //清除屏幕上的内容
			printf("\n\t 请选择正确的操作,");
			system("pause");
			system("cls");  //清除屏幕上的内容
		}
	}
}