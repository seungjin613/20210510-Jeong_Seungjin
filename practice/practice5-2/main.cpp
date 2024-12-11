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
	printf("������ �Է��ϼ���\n",degree);
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
		printf("�߸��� �Է��Դϴ�.");
	}
	return 0;
}