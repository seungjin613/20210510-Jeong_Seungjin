#include <stdio.h>

int main(void)
{
	int num = 0;//입력값이 정수이므로 int를 활용하여 변수 선언
	printf("정수를 입력하세요:\n");
	scanf_s("%d", &num);
	
	if (num % 2 == 0)//입력된 정수를 2로 나눠서 나머지를 검사하였을때, 짝수인지 홀수인지 판별한다.
	{
		printf("입력하신 정수는 짝수입니다.");//나머지가 0이면 짝수를 출력한다.
	}
	else
	{
		printf("입력하신 정수는 홀수입니다.");//나머지가 0이 아니면 홀수를 출력한다.
	}
	return 0;
}