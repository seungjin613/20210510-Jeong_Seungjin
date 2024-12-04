#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void GArray(double arr[], int size, int iint) // �迭 ���� �Լ�
{
    for (int i = 0; i < size; i++) 
    {
        if(iint)
        {
            arr[i] = rand() % 201 - 100; // -100 ~ +100 ���� ����
        }
        else if(iint)
        {
            arr[i] = ((double)rand() / RAND_MAX) * 200.0 - 100.0; // -100.0 ~ +100.0 ����

        }
    }
}

void PrintArray(double arr[], int size)// �迭 ��� �Լ�
{
    for (int i = 0; i < size; i++) 
    {
        printf("%.1f ", arr[i]);
    }
    printf("\n");
}

void CalcInverseArray(double arr[], double inverseArr[], int size) // �迭 ���� �Լ�
{
    for (int i = 0; i < size; i++) 
    {
        inverseArr[i] = arr[size - 1 - i]; // �������� ����
    }
}

int main() 
{
    const int size = 10;
    double array[size], inverseArray[size];
    int num;

    srand(time(NULL));// ���� �õ� �ʱ�ȭ

    printf("���ϴ� ��(���� : 1, �Ǽ�: 2)�� �Է��Ͻÿ� : ");
    scanf_s("%d", &num);

    GArray(array, size, num);// �迭 ����
    printf("������ �迭:");
    PrintArray(array, size);

    CalcInverseArray(array, inverseArray, size);// �迭 ���� ���
    printf("���� �迭:");
    PrintArray(inverseArray, size);

    return 0;
}