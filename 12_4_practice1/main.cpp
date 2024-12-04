#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GArray(double *arr, int size, int iint) //배열 생성 함수
{
    for (int i = 0; i < size; i++)
    {
        if (iint)//정수로 생성
        {
            *(arr+i) = rand() % 201 - 100; // -100 ~ +100 범위로 설정하여 정수 배열을 생성
        }
        else//실수로 생성
        {
            *(arr+i) = ((double)rand() / RAND_MAX) * 200.0 - 100.0;//-100~100 범위로 설정하여 실수 배열을 생성
        }
    }
}

void CalcSortArray(double *arr, int size, int ascending) //배열 정렬 함수
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

void PrintArray(double *arr, int size)//배열 출력 함수
{
    for (int i = 0; i < size; i++)
    {
        printf("%.1lf  ", *(arr+ i));
    }
    printf("\n");//배열이 다 출력된 후 한줄 내리기
}

int main(void)
{
    srand((unsigned int)(time(NULL)));//랜덤 시드 초기화

    int num;
    const int size = 10;
    double array[size];

    printf("알고 싶은 값(정수:1, 실수:2)을 입력하시오:");//정수로 배열을 생성할건지 실수로 배열을 생성할건지 고르기
    scanf_s("%d", &num);

    GArray(array, size, num==1);   // 배열 생성
    printf("생성된 배열:");
    PrintArray(array, size);

    CalcSortArray(array, size, 1); // 오름차순 정렬
    printf("오름차순 정렬된 배열:");
    PrintArray(array, size);

    CalcSortArray(array, size, 0);// 내림차순 정렬
    printf("내림차순 정렬된 배열:");
    PrintArray(array, size);

    return 0;
}