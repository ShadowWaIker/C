/* 费氏级数(Fibonacci) */
#include "stdio.h"
int main(void)
{
	int Number;
	int FibN;
	int FibN1;
	int FibN2;
	int i;

	printf("The Fibnacci Number \n");
	printf("Please Enter a number:");  /*输入数值*/
	scanf("%d", &Number);

	if (Number <= 1)
		printf("Fiboncci Number of %d = 1", Number);
	else
	{
		FibN2 = 0;
		FibN1 = 1;
		for (i = 2;i <= Number;i++)
		{
			FibN = FibN1 + FibN2;
			FibN2 = FibN1;
			FibN1 = FibN;
		}
		printf("Fibonacci Numbers of %d = %d\n", Number, FibN);
	}
	getch();
	return 0;
}