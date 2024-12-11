#include <stdio.h>

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int max = 0;
	int min = 0;

	printf("두수를 입력하세요\n", num1, num2);
	scanf_s("%d %d", &num1, &num2);

	int i = num1, j = num2;
	do
	{
		if (i > j)
			i -= j;
		else
			j -= i;
	} while (i != j);

	max = i;
	min = num1 * num2 / max;

	printf("%d가 최대공약수입니다.\n", max);
	printf("%d가 최소공배수입니다.\n", min);

	return 0;
}