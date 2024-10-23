#include <stdio.h>

int main(void)
{
	double grades = 0;//입력받는 값이 실수값이므로 double를 활용하여 변수를 선언한다.
	printf("0.0~100.0 범위의 실수를 입력하세요:\n");
	scanf_s("%lf", &grades);

	if (grades >= 90.0)//입력 받은 실수가 90.0보다 크거나 같으면 학점A를 부여한다.
	{
		printf("학점:A");
	}
	else if (grades >= 80.0)//입력 받은 실수가 80.0보다 크거나 같으면 학점B를 부여한다.
	{
		printf("학점:B");
	}
	else if (grades >= 70.0)//입력 받은 실수가 70.0보다 크거나 같으면 학점C를 부여한다.
	{
		printf("학점:C");
	}
	else if (grades >= 60.0)//입력 받은 실수가 60.0보다 크거나 같으면 학점D를 부여한다.
	{
		printf("학점:D");
	}
	else if (grades >= 50.0)//입력 받은 실수가 50.0보다 크거나 같으면 학점E를 부여한다.
	{
		printf("학점:E");
	}
	else//입력 받은 실수가 0~49.9점 사이값이면 학점F를 부여한다.
	{
		printf("학점:F");
	}
	return 0;
}