#include <stdio.h>

int main(void)
{
	double feet = 0.0;
	double inches = 0.0;
	double kg = 0.0;

	printf("피트와 인치 그리고 질량 값을 입력하세요 : \n");
	scanf_s("%lf %lf %lf", &feet, &inches, &kg);
	printf("m와 slug의 값은:(%.2lfm %.2lfm %.2lfslug)\n", feet * 0.3048, inches * 0.0254, kg * 0.06852);

	return 0;

}