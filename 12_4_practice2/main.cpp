#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void GArray(double arr[], int size, int iint) // 배열 생성 함수
{
    for (int i = 0; i < size; i++) 
    {
        if(iint)
        {
            arr[i] = rand() % 201 - 100; // -100 ~ +100 범위 정수
        }
        else if(iint)
        {
            arr[i] = ((double)rand() / RAND_MAX) * 200.0 - 100.0; // -100.0 ~ +100.0 범위

        }
    }
}

void PrintArray(double arr[], int size)// 배열 출력 함수
{
    for (int i = 0; i < size; i++) 
    {
        printf("%.1f ", arr[i]);
    }
    printf("\n");
}

void CalcInverseArray(double arr[], double inverseArr[], int size) // 배열 역순 함수
{
    for (int i = 0; i < size; i++) 
    {
        inverseArr[i] = arr[size - 1 - i]; // 역순으로 저장
    }
}

int main() 
{
    const int size = 10;
    double array[size], inverseArray[size];
    int num;

    srand(time(NULL));// 랜덤 시드 초기화

    printf("원하는 값(정수 : 1, 실수: 2)을 입력하시오 : ");
    scanf_s("%d", &num);

    GArray(array, size, num);// 배열 생성
    printf("생성된 배열:");
    PrintArray(array, size);

    CalcInverseArray(array, inverseArray, size);// 배열 역순 계산
    printf("역순 배열:");
    PrintArray(inverseArray, size);

    return 0;
}