#include "stdio.h"

int Data[20] = { 1,7,9,12,15,16,20,32,35,67,78,80,83,89,90,92,97,108,120,177 };/*输入数据数组*/
int Counter = 1;/*这两个变量为全局变量*/

/*顺序查找*/
int Seq_Search(int Key)
{
	int i;

	for (i = 0;i<20;i++)
	{
		printf("[%d]", Data[i]);
		if (Key == Data[i])
			return 1;
		Counter++;
	}
	return 0;
}

/*主程序*/
int main(void)
{
	int KeyValue; /*欲查找数据变量*/
	printf("Please Enter Your Key Value:");
	scanf("%d", &KeyValue);/*输入欲查找数据值*/

	if (Seq_Search(KeyValue))
		printf("\nSearch Time = %d\n", Counter);
	else
		printf("No Found!!\n");
}