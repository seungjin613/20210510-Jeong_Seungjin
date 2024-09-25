#include <stdio.h>

int main(void)
{
	
	double base = 0.0;
	double height = 0.0;
	double length = 0.0; 
	double width = 0.0;
	double redius = 0.0;
	double Pi = 3.141592;

	printf("삼각형의 밑변의 길이와 높이를 입력하시오, 사각형의 두변의 길이를 입력하시오, 원의 반지름을 7번 입력하시오 : \n");
	scanf_s("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &base, &height, &length, &width, &redius, &redius, &redius, &redius, &redius, &redius, &redius);
	printf("도형들의 넓이와 체적: (%.2lf㎠ %.2lf㎠ %.2lf㎠ %.2lf㎠ %.2lf㎤)\n", base*height/2, length*width, Pi*redius*redius, 4*Pi*redius*redius, 4/3*Pi*redius*redius*redius );

	return 0;
}
