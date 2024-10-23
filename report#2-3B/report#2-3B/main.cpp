#include <stdio.h>

int main(void)
{
	double grades = 0;//입력하는 값의 범위가 0.0~100.0이므로 실수이기 때문에 double를 활용하여 변수 선언한다.
	printf("0.0~100.0 범위의 실수를 입력하세요:\n");
	scanf_s("%lf", &grades);
	int gpa = grades / 10;//switch-case문을 사용할려면 case에 값을 지정하여 코드를 만들어야 되기 때문에 받은 실수값을 10으로 나누어서 정수부분만 뽑아낸다.

	switch (gpa)
	{
	case 10://실수값을 10으로 나누었을 때 정수부분이 10이면 학점A를 부여한다.
	{
		printf("학점:A");
		break;
	}
	case 9://실수값을 10으로 나누었을 때 정수부분이 9이면 학점A를 부여한다.
	{
		printf("학점:A");
		break;
	}
	case 8://실수값을 10으로 나누었을 때 정수부분이 8이면 학점B를 부여한다.
	{
		printf("학점:B");
		break;
	}
	case 7://실수값을 10으로 나누었을 때 정수부분이 7이면 학점C를 부여한다.
	{
		printf("학점:C");
		break;
	}
	case 6://실수값을 10으로 나누었을 때 정수부분이 6이면 학점D를 부여한다.
	{
		printf("학점:D");
		break;
	}
	case 5://실수값을 10으로 나누었을 때 정수부분이 5이면 학점E를 부여한다.
	{
		printf("학점:E");
		break;
	}
	default://실수값을 10으로 나누었을 때 정수부분이 5~10범위가 아닌 다른 값이 들어오게 되면 학점F를 부여한다.
	{
		printf("학점:F");
		break;
	}
	}
	return 0;
}