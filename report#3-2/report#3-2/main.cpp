#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void RandomNum(int min, int max, int* num) 
{
    *num = rand() % (max - min + 1) + min; // �ּҰ��� �ִ� ���̿��� ������ ���� ����
}

double dcalSum(int num, double total) 
{
    return total + num;  // ���� ���
}

double dcalSqadSum(int num, double sqaTotal) 
{
    return sqaTotal + num * num; // ������ �� ���
}

double dcalVar(double totalSqa, double total, int count) 
{
    double mean = total / count;  // �л� ���
    return (totalSqa / count) - (mean * mean);
}

double dcalStadDev(double variance) 
{
    return sqrt(variance);  // ǥ������ ���
}

int main() 
{
    int min, max;
    int num;
    double total = 0.0, totalSqa = 0.0;
    double average, variance, std;

    srand(time(NULL)); // ���� �õ� �ʱ�ȭ

    printf("���� ���� ���� (�ּҰ��� �ִ��� �Է��ϼ���): ");
    scanf_s("%d %d", &min, &max);

    if (min > max) 
    {
        printf("�߸��� �����Դϴ�. �ּҰ��� �ִ񰪺��� Ŭ �� �����ϴ�.\n");
        return 0;
    }

    for (int i = 0; i < 10; i++) // 10�� �ݺ��Ͽ� 10���� ���� ������ �����ϰ� ���
    {
        RandomNum(min, max, &num); // ���� ���� ����
        printf("%d ", num); // ������ ���� ���

        total = dcalSum(num, total); // ���� ���
        totalSqa = dcalSqadSum(num, totalSqa); // ������ �� ���
    }

    printf("\n");

    average = total / 10.0;  // ��� ���

    variance = dcalVar(totalSqa, total, 10);  // �л� ���

    std = dcalStadDev(variance); // ǥ������ ���

    printf("����: %.2f\n", total);
    printf("���: %.2f\n", average);
    printf("�л�: %.2f\n", variance);
    printf("ǥ������: %.2f\n", std);  // ��� ���

    return 0;
}