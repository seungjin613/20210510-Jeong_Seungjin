#include <stdio.h>

int main(void)
{
	double feet = 0.0;
	double inches = 0.0;
	double kg = 0.0;

	printf("��Ʈ�� ��ġ �׸��� ���� ���� �Է��ϼ��� : \n");
	scanf_s("%lf %lf %lf", &feet, &inches, &kg);
	printf("m�� slug�� ����:(%.2lfm %.2lfm %.2lfslug)\n", feet * 0.3048, inches * 0.0254, kg * 0.06852);

	return 0;

}