#include <stdio.h>

int main(void)
{
	int num1, num2, result = 0;
	char operations;
	printf("������ �Է��Ͻÿ�:\n");
	scanf_s("%d %c %d", &num1, &operations, sizeof(operations), &num2);

	switch (operations)
	{
	case '+' :
		result = num1 + num2;
		break;
		
	case '-' :
		result = num1 - num2;
		break;

	case '*' :
		result = num1 * num2;
		break;
		
	case '/' :
		result = num1 / num2;
		break;
	default :
		printf("�߸��� �����Դϴ�.\n");
		break;
	}

	printf("����� : %d\n", result);
	return 0;
}