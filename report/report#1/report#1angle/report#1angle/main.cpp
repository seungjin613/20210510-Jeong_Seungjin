#include <stdio.h>

int main(void)
{
	double num = 0.0; //�Ǽ����̶� 0.0�̶� �Է��߽��ϴ�.
	double angle_1 = 0.0;
	double angle_2 = 0.0;
	int convert_angle1 = 0; //�������� ���� ������ ������ ���� int�� Ȱ���Ͽ� 0���� �����Ͽ����ϴ�.
	int convert_angle2 = 0;

	printf("������ �Է��ϼ���(0~360�� ���� �Ǵ� �� �̻�)\n");
	scanf_s("%lf", &num);
	convert_angle1 = num / 360; //���� ������ �Է¹޾Ƽ� convert_angle1�� ���� �Ҵ����ش�.
	angle_1 = num - convert_angle1 * 360; //�������� 360�� �ʰ��� 0~360�� ���� ��ȯ�ϴ� �����̴�.
	convert_angle2 = angle_1 / 180;
	angle_2 = angle_1 - convert_angle2 * 360; // -180~180�� ������ ��ȯ�Ѵ�.
	printf("��ȯ�� ���� : %.2lf��%.2lf��", num, angle_2);

	return 0;
}