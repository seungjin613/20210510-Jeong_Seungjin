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

	printf("�־��� �µ��� �Է��Ͻÿ�, �����µ� 1, ȭ���µ� 2 : ");
	scanf_s("%d", &num);
	printf("\n");

	if (num == 1)
	{
		printf("������ �Է��ϼ��� : ");
		scanf_s("%lf", &num2);
		printf("�־��� ������ ���� ȭ�� �µ��� :  %lf : ", Fahrenheit(num2));
	}

	else if (num == 2) 
	{
		printf("ȭ���� �Է��ϼ��� : ");
		scanf_s("%lf", &num2);
		printf("�־��� ȭ���� ���� ���� �µ��� :  %lf : ", celsius(num2));
	}
	else
	{
		printf("�־��� �Է��� �߸��� �Է��Դϴ�.");
	}
	return 0;
}