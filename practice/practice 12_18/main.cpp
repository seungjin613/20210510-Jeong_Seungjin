#include <stdio.h>
#include <math.h>

struct Point// 3���� ���� ��Ÿ���� ����ü
{
    double x;
    double y;
    double z;
};
typedef struct Point;

double CDistance(Point* p1, Point* p2)// �� �� ������ ��Ŭ���� �Ÿ� ��� �Լ�
{
    return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2) + pow(p2->z - p1->z, 2));// �����͸� ���� �� ���� ��ǥ�� �����Ͽ� �Ÿ� ���
}

int main(void) 
{
    Point point[2];//�� ���� �迭�� �����Ͽ� �Է�

    printf("ù��° ���� ��ǥ�� �Է��ϼ���.\n");
    printf("x_1: ");
    scanf_s("%lf", &point[0].x);
    printf("y_1: ");
    scanf_s("%lf", &point[0].y);
    printf("z_1: ");
    scanf_s("%lf", &point[0].z);

    printf("�ι�° ���� ��ǥ�� �Է��ϼ��� :\n");
    printf("x_2: ");
    scanf_s("%lf", &point[1].x);
    printf("y_2: ");
    scanf_s("%lf", &point[1].y);
    printf("z_2: ");
    scanf_s("%lf", &point[1].z);

    double Distance = CDistance(&point[0], &point[1]);// �迭�� ù ��° ���� �� ��° ���� ���Ͽ� ��Ŭ���� �Ÿ� ���

    printf("�� �� ���̿� �Ÿ��� : %f\n", Distance);// �Ÿ� ���

    return 0;
}