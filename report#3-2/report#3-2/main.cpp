#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void generateRandomNumbers(int arr[], int size, int lower, int upper)// ������ ������ �����ϴ� �Լ�
{
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (upper - lower + 1) + lower;  // lower���� upper������ ���� ���� ����
    }
}


double calculateSum(int arr[], int size) // ������ ����ϴ� �Լ�
{
    double total = 0.0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

double calculateVariance(int arr[], int size, double mean) // �л��� ����ϴ� �Լ�
{
    double variance = 0.0;
    for (int i = 0; i < size; i++) {
        variance += pow(arr[i] - mean, 2);
    }
    return variance / size;
}

double calculateStandardDeviation(double variance) // ǥ�������� ����ϴ� �Լ�
{
    return sqrt(variance);
}

int main() 
{
    int numbers[10];  // 10���� ������ ������ �迭
    int lower, upper;
    double total, average, variance, std;

    srand(time(NULL)); // ���� �õ� �ʱ�ȭ

    printf("���� ���� ���� (�ּҰ��� �ִ��� �Է��ϼ���): "); // ���� �Է� �ޱ�
    scanf_s("%d %d", &lower, &upper);

    if (lower > upper)
    {
        printf("�߸��� �����Դϴ�. ������ ���Ѻ��� Ŭ �� �����ϴ�.\n"); // ������ �߸��� ���
        return 1;
    }

    generateRandomNumbers(numbers, 10, lower, upper); // 10���� ������ ���� ����

    printf("������ ������: ");

    for (int i = 0; i < 10; i++) 
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    total = calculateSum(numbers, 10); //���� ���

    average = total / 10.0; // ��� ���

    variance = calculateVariance(numbers, 10, average); // �л� ���

    std = calculateStandardDeviation(variance); // ǥ������ ���

    printf("����: %.2f\n", total);
    printf("���: %.2f\n", average);
    printf("�л�: %.2f\n", variance);
    printf("ǥ������: %.2f\n", std); // ��� ���

    return 0;
}