#include <stdio.h>

int main(void)
{
	double num = 0.0; //실수값이라 0.0이라 입력했습니다.
	double angle_1 = 0.0;
	double angle_2 = 0.0;
	int convert_angle1 = 0; //나누어진 값은 정수로 나오기 위해 int를 활용하여 0으로 설정하였습니다.
	int convert_angle2 = 0;

	printf("각도를 입력하세요(0~360도 범위 또는 그 이상)\n");
	scanf_s("%lf", &num);
	convert_angle1 = num / 360; //먼저 각도를 입력받아서 convert_angle1에 값을 할당해준다.
	angle_1 = num - convert_angle1 * 360; //각도값이 360을 초과시 0~360의 수로 변환하는 계산식이다.
	convert_angle2 = angle_1 / 180;
	angle_2 = angle_1 - convert_angle2 * 360; // -180~180도 값으로 변환한다.
	printf("변환된 각도 : %.2lf˚%.2lf˚", num, angle_2);

	return 0;
}