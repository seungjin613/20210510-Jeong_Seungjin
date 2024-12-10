#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GArray(double *arr, int size, int iint) //�迭 ���� �Լ�
{
    for (int i = 0; i < size; i++)
    {
        if (iint)//������ ����
        {
            *(arr+i) = rand() % 201 - 100; // -100 ~ +100 ������ �����Ͽ� ���� �迭�� ����
        }
        else//�Ǽ��� ����
        {
            *(arr+i) = ((double)rand() / RAND_MAX) * 200.0 - 100.0;//-100~100 ������ �����Ͽ� �Ǽ� �迭�� ����
        }
    }
}

void CalcSortArray(double *arr, int size, int ascending) //�迭 ���� �Լ�
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++) 
        {
            if ((ascending && *(arr+j) > *(arr+j + 1)) || (!ascending && *(arr+j) < *(arr+j + 1))) 
            {
                double temp = *(arr+j);
                arr[j] = *(arr+j + 1);
                *(arr+j + 1) = temp;
            }
        }
    }
}

void PrintArray(double *arr, int size)//�迭 ��� �Լ�
{
    for (int i = 0; i < size; i++)
    {
        printf("%.1lf  ", *(arr+ i));
    }
    printf("\n");//�迭�� �� ��µ� �� ���� ������
}

int main(void)
{
    srand((unsigned int)(time(NULL)));//���� �õ� �ʱ�ȭ

    int num;
    const int size = 10;
    double array[size];

    printf("�˰� ���� ��(����:1, �Ǽ�:2)�� �Է��Ͻÿ�:");//������ �迭�� �����Ұ��� �Ǽ��� �迭�� �����Ұ��� ����
    scanf_s("%d", &num);

    GArray(array, size, num==1);   // �迭 ����
    printf("������ �迭:");
    PrintArray(array, size);

    CalcSortArray(array, size, 1); // �������� ����
    printf("�������� ���ĵ� �迭:");
    PrintArray(array, size);

    CalcSortArray(array, size, 0);// �������� ����
    printf("�������� ���ĵ� �迭:");
    PrintArray(array, size);

    return 0;
}