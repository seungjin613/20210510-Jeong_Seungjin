#include <stdio.h>

int main(void)
{
	int num1, num2, result = 0;
	char operations;
	printf("������ �Է��Ͻÿ�:\n");
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
	printf("����� : %d\n", result);
	return 0;
}