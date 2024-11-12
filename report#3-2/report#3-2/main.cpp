#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void RandomNumbers(int min, int max, int* num) 
{
    *num = rand() % (max - min + 1) + min; // lower�� upper ���̿��� ������ ���� ����
}

double dcalculateSum(int num, double total) 
{
    return total + num;  // ���� ���
}

double dcalculateSquaredSum(int num, double squaredTotal) 
{
    return squaredTotal + num * num; // ������ �� ���
}

double dcalculateVariance(double totalSquared, double total, int count) 
{
    double mean = total / count;  // �л� ���
    return (totalSquared / count) - (mean * mean);
}

double dcalculateStandardDeviation(double variance) 
{
    return sqrt(variance);  // ǥ������ ���
}

int main() 
{
    int min, max;
    int num;
    double total = 0.0, totalSquared = 0.0;
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
        RandomNumbers(min, max, &num); // ���� ���� ����
        printf("%d ", num); // ������ ���� ���

        total = dcalculateSum(num, total); // ���� ���
        totalSquared = dcalculateSquaredSum(num, totalSquared); // ������ �� ���
    }

    printf("\n");

    average = total / 10.0;  // ��� ���

    variance = dcalculateVariance(totalSquared, total, 10);  // �л� ���

    std = dcalculateStandardDeviation(variance); // ǥ������ ���

    printf("����: %.2f\n", total);
    printf("���: %.2f\n", average);
    printf("�л�: %.2f\n", variance);
    printf("ǥ������: %.2f\n", std);  // ��� ���

    return 0;
}