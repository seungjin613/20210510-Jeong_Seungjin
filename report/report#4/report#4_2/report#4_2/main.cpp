#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 100
#define SUB_SIZE 10

void GRandomNum(int* arr, int size, int min, int max)// 무작위 숫자 생성 함수
{
    for (int i = 0; i < size; ++i)
    {
        arr[i] = (rand() % (max - min + 1)) + min;
    }
}

void CStatistics(int* arr, int size, int* sum, double* variance, double* stddev)// 총합, 분산, 표준편차 계산 함수
{
    *sum = 0;
    double mean = 0.0;
    *variance = 0.0;

    for (int i = 0; i < size; ++i)// 총합 계산
    {
        *sum += arr[i];
    }
    mean = (double)(*sum) / size; //평균 계산

    for (int i = 0; i < size; ++i)// 분산 계산
    {
        *variance += (arr[i] - mean) * (arr[i] - mean);
    }
    *variance /= size;  // 전체기준으로 분산을 구하기 위해 size로 나눈다

    *stddev = sqrt(*variance);  // 표준편차 계산
}

int main()
{
    int num[SIZE];          // 100개의 숫자
    int SelectedNum[SUB_SIZE];  // 선택된 10개의 숫자 
    int sum;
    double variance, stddev;

    srand((unsigned int)time(NULL)); // 난수 생성기 시드 초기화

    GRandomNum(num, SIZE, 1, 100);// 100개의 난수 생성

    printf("선택된 숫자들: ");
    for (int i = 0; i < SUB_SIZE; ++i) // 무작위로 선택된 10개의 숫자 출력
    {
        int Index = rand() % SIZE;  // 0부터 SIZE-1까지의 랜덤 인덱스를 선택
        SelectedNum[i] = num[Index];
        printf("%d ", SelectedNum[i]);
    }
    printf("\n");

    CStatistics(SelectedNum, SUB_SIZE, &sum, &variance, &stddev);// 선택된 숫자들의 총합, 분산, 표준편차 계산

    printf("총합: %d\n", sum);// 총합, 분산, 표준편차 출력
    printf("분산: %.2f\n", variance);
    printf("표준편차: %.2f\n", stddev);

    return 0;
}