#include <stdio.h>

int main(void)
{
	int num = 0;//입력 받는 값이 정수이므로 int를 활용하여 변수선언
	printf("정수를 입력하세요:\n");
	scanf_s("%d", &num);

	switch (num % 2)//입력 받은 정수를 2로 나눈다.
	{
	case 0://정수를 2로 나눴을때 나머지가 0이면 짝수를 출력
	{
		printf("입력하신 정수는 짝수입니다.");
		break;
	}
	default ://정수를 2로 나눴을때 나머지가 0이 아니면 홀수를 출력
	{
		printf("입력하신 정수는 홀수입니다.");
		break;
	}
	}
	return 0;
}