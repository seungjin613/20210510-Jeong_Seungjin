#include <stdio.h>

int main(void)
{
	int num1, num2, result = 0;
	char operations;
	printf("수식을 입력하시오:\n");
	scanf_s("%d %c %d", &num1, &operations, sizeof(operations), &num2);

	if (operations == '+')
	{
		result = num1 + num2;
	}
	else if (operations == '-')
	{
		result = num1 - num2;
	}
	else if (operations == '*')
	{
		result = num1 * num2;
	}
	else if (operations == '/')
	{
		result = num1 / num2;
	}
	printf("계산결과 : %d\n", result);
	return 0;
}