#include <stdio.h>

int main(void)
{
	int num1, num2, result = 0;
	char operations;
	printf("수식을 입력하시오:\n");
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
		printf("잘못된 수식입니다.\n");
		break;
	}

	printf("계산결과 : %d\n", result);
	return 0;
}