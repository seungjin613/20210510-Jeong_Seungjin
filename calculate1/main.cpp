#include <stdio.h>

int main(void)
{

	double base = 0.0;
	double height = 0.0;
	double length = 0.0;
	double width = 0.0;
	double redius = 0.0;
	double Pi = 3.141592;

	printf("�ﰢ���� �غ��� ���̿� ���̸� �Է��Ͻÿ�, �簢���� �κ��� ���̸� �Է��Ͻÿ�, ���� �������� 7�� �Է��Ͻÿ� : \n");
	scanf_s("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &base, &height, &length, &width, &redius, &redius, &redius, &redius, &redius, &redius, &redius);
	printf("�������� ���̿� ü��: (%.2lf�� %.2lf�� %.2lf�� %.2lf�� %.2lf��)\n", base * height / 2, length * width, Pi * redius * redius, 4 * Pi * redius * redius, 4 / 3 * Pi * redius * redius * redius);

	return 0;
}
