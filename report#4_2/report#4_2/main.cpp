#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 100
#define SUB_SIZE 10

void GRandomNum(int* arr, int size, int min, int max)// ������ ���� ���� �Լ�
{
    for (int i = 0; i < size; ++i)
    {
        arr[i] = (rand() % (max - min + 1)) + min;
    }
}

void CStatistics(int* arr, int size, int* sum, double* variance, double* stddev)// ����, �л�, ǥ������ ��� �Լ�
{
    *sum = 0;
    double mean = 0.0;
    *variance = 0.0;

    for (int i = 0; i < size; ++i)// ���� ���
    {
        *sum += arr[i];
    }
    mean = (double)(*sum) / size; //��� ���

    for (int i = 0; i < size; ++i)// �л� ���
    {
        *variance += (arr[i] - mean) * (arr[i] - mean);
    }
    *variance /= size;  // ��ü�������� �л��� ���ϱ� ���� size�� ������

    *stddev = sqrt(*variance);  // ǥ������ ���
}

int main()
{
    int num[SIZE];          // 100���� ����
    int SelectedNum[SUB_SIZE];  // ���õ� 10���� ���� 
    int sum;
    double variance, stddev;

    srand((unsigned int)time(NULL)); // ���� ������ �õ� �ʱ�ȭ

    GRandomNum(num, SIZE, 1, 100);// 100���� ���� ����

    printf("���õ� ���ڵ�: ");
    for (int i = 0; i < SUB_SIZE; ++i) // �������� ���õ� 10���� ���� ���
    {
        int Index = rand() % SIZE;  // 0���� SIZE-1������ ���� �ε����� ����
        SelectedNum[i] = num[Index];
        printf("%d ", SelectedNum[i]);
    }
    printf("\n");

    CStatistics(SelectedNum, SUB_SIZE, &sum, &variance, &stddev);// ���õ� ���ڵ��� ����, �л�, ǥ������ ���

    printf("����: %d\n", sum);// ����, �л�, ǥ������ ���
    printf("�л�: %.2f\n", variance);
    printf("ǥ������: %.2f\n", stddev);

    return 0;
}