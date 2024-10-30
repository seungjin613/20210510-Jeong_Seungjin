#include <stdio.h>

double Fahrenheit(double c)
{
	double f;
	f = 1.8 * c + 32;
	return f;
}
double celsius(double f)
{
	double c;
	c = (f - 32) / 1.8;
	return c;
}

int main(void)
{
	int num;
	double num2;

	printf("주어진 온도를 입력하시오, 섭씨온도 1, 화씨온도 2 : ");
	scanf_s("%d", &num);
	printf("\n");

	if (num == 1)
	{
		printf("섭씨를 입력하세요 : ");
		scanf_s("%lf", &num2);
		printf("주어진 섭씨에 대한 화씨 온도는 :  %lf : ", Fahrenheit(num2));
	}

	else if (num == 2) 
	{
		printf("화씨를 입력하세요 : ");
		scanf_s("%lf", &num2);
		printf("주어진 화씨에 대한 섭씨 온도는 :  %lf : ", celsius(num2));
	}
	else
	{
		printf("주어진 입력은 잘못된 입력입니다.");
	}
	return 0;
}