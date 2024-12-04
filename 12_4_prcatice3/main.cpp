#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GArray(int arr[], int size)// �迭 ���� �Լ�
{
    for (int i = 0; i < size; i++)
    {
        *(arr+i) = rand() % 101; // 0~100 ������ ���� ���� ����
    }
}

void PrintArray(int arr[], int size) // �迭 ��� �Լ�
{
    for (int i = 0; i < size; i++) 
    {
        if (*(arr+i) != -1) // �ǹ� ���� ���� ����
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void CalcEvenOddArray(int arr[], int evenArr[], int oddArr[], int size) // ¦���� Ȧ�� �и� �Լ�
{
    int evenIndex = 0, oddIndex = 0;

    for (int i = 0; i < size; i++) 
    {
        if (*(arr+i) % 2 == 0) 
        {
            evenArr[evenIndex++] = arr[i]; // ¦�� ����
        }
        else 
        {
            oddArr[oddIndex++] = arr[i]; // Ȧ�� ����
        }
    }

    // ���� ������ -1�� �ʱ�ȭ
    for (int i = evenIndex; i < size; i++) 
    {
        *(evenArr+i) = -1;
    }
    for (int i = oddIndex; i < size; i++) 
    {
        *(oddArr+i) = -1;
    }
}

int main(void) 
{
    const int size = 10;
    int array[size], evenArray[size], oddArray[size];

    srand((unsigned int)time(NULL));//���� �õ� �ʱ�ȭ

    GArray(array, size);//�迭 ����
    printf("������ �迭:");
    PrintArray(array, size);

    CalcEvenOddArray(array, evenArray, oddArray, size);//¦���� Ȧ�� �и�

    printf("¦�� �迭:");
    PrintArray(evenArray, size);

    printf("Ȧ�� �迭:");
    PrintArray(oddArray, size);

    return 0;
}