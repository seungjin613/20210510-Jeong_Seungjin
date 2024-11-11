#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void generateRandomNumbers(int arr[], int size, int lower, int upper)// 무작위 정수를 생성하는 함수
{
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (upper - lower + 1) + lower;  // lower부터 upper까지의 랜덤 정수 생성
    }
}


double calculateSum(int arr[], int size) // 총합을 계산하는 함수
{
    double total = 0.0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

double calculateVariance(int arr[], int size, double mean) // 분산을 계산하는 함수
{
    double variance = 0.0;
    for (int i = 0; i < size; i++) {
        variance += pow(arr[i] - mean, 2);
    }
    return variance / size;
}

double calculateStandardDeviation(double variance) // 표준편차를 계산하는 함수
{
    return sqrt(variance);
}

int main() 
{
    int numbers[10];  // 10개의 정수를 저장할 배열
    int lower, upper;
    double total, average, variance, std;

    srand(time(NULL)); // 랜덤 시드 초기화

    printf("정수 생성 범위 (최소값과 최댓값을 입력하세요): "); // 범위 입력 받기
    scanf_s("%d %d", &lower, &upper);

    if (lower > upper)
    {
        printf("잘못된 범위입니다. 하한이 상한보다 클 수 없습니다.\n"); // 범위가 잘못된 경우
        return 1;
    }

    generateRandomNumbers(numbers, 10, lower, upper); // 10개의 무작위 정수 생성

    printf("생성된 정수들: ");

    for (int i = 0; i < 10; i++) 
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    total = calculateSum(numbers, 10); //총합 계산

    average = total / 10.0; // 평균 계산

    variance = calculateVariance(numbers, 10, average); // 분산 계산

    std = calculateStandardDeviation(variance); // 표준편차 계산

    printf("총합: %.2f\n", total);
    printf("평균: %.2f\n", average);
    printf("분산: %.2f\n", variance);
    printf("표준편차: %.2f\n", std); // 결과 출력

    return 0;
}