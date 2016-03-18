/*运用一维数组设计一个可计算多个数的平均值的程序*/
#include "stdio.h"
int main(void)
{
	int Max = 0;
	int i;
	float Number[20];
	float Summary;
	float Average;

	Summary = 0;
	printf("Please input the number of data:");
	scanf("%d", &Max);
	if (Max <= 20)
	{
		for (i = 0;i < Max;i++)
		{
			printf("Please input a number:");
			scanf("%f", &Number[i]);
			Summary += Number[i];
		}
		Average = Summary / Max;
		printf("The average is %5.2f \n", Average);
	}
	else
		printf("Please input a number less than 20.");
}