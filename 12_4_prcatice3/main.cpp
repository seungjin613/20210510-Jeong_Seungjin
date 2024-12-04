#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GArray(int arr[], int size)// 배열 생성 함수
{
    for (int i = 0; i < size; i++)
    {
        *(arr+i) = rand() % 101; // 0~100 사이의 랜덤 정수 생성
    }
}

void PrintArray(int arr[], int size) // 배열 출력 함수
{
    for (int i = 0; i < size; i++) 
    {
        if (*(arr+i) != -1) // 의미 없는 공간 제외
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void CalcEvenOddArray(int arr[], int evenArr[], int oddArr[], int size) // 짝수와 홀수 분리 함수
{
    int evenIndex = 0, oddIndex = 0;

    for (int i = 0; i < size; i++) 
    {
        if (*(arr+i) % 2 == 0) 
        {
            evenArr[evenIndex++] = arr[i]; // 짝수 저장
        }
        else 
        {
            oddArr[oddIndex++] = arr[i]; // 홀수 저장
        }
    }

    // 남은 공간을 -1로 초기화
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

    srand((unsigned int)time(NULL));//랜덤 시드 초기화

    GArray(array, size);//배열 생성
    printf("생성된 배열:");
    PrintArray(array, size);

    CalcEvenOddArray(array, evenArray, oddArray, size);//짝수와 홀수 분리

    printf("짝수 배열:");
    PrintArray(evenArray, size);

    printf("홀수 배열:");
    PrintArray(oddArray, size);

    return 0;
}