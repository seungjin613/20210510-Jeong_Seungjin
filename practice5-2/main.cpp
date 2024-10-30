#include <stdio.h>
#include <math.h>

const double PI = 3.141592;
double degree, rad, deg_sin, deg_cos = 0.0;

double radian(double deg)
{
	return deg * PI / 180;
}

int main(void)
{
	printf("각도를 입력하세요\n",degree);
	scanf_s("%lf", &degree);

	if ((degree >= 0) && (degree <= 180))
	{
		rad = radian(degree);
		deg_sin = sin(rad);
		deg_cos = cos(rad);
		printf("sin(%lf) = %lf, cos(%lf) = %lf", degree, deg_sin, degree, deg_cos);
	}
	else
	{
		printf("잘못된 입력입니다.");
	}
	return 0;
}