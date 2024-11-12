#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void RandomNumbers(int min, int max, int* num) 
{
    *num = rand() % (max - min + 1) + min; // lower와 upper 사이에서 랜덤한 정수 생성
}

double dcalculateSum(int num, double total) 
{
    return total + num;  // 총합 계산
}

double dcalculateSquaredSum(int num, double squaredTotal) 
{
    return squaredTotal + num * num; // 제곱의 합 계산
}

double dcalculateVariance(double totalSquared, double total, int count) 
{
    double mean = total / count;  // 분산 계산
    return (totalSquared / count) - (mean * mean);
}

double dcalculateStandardDeviation(double variance) 
{
    return sqrt(variance);  // 표준편차 계산
}

int main() 
{
    int min, max;
    int num;
    double total = 0.0, totalSquared = 0.0;
    double average, variance, std;

    srand(time(NULL)); // 랜덤 시드 초기화

    printf("정수 생성 범위 (최소값과 최댓값을 입력하세요): ");
    scanf_s("%d %d", &min, &max);

    if (min > max) 
    {
        printf("잘못된 범위입니다. 최소값이 최댓값보다 클 수 없습니다.\n");
        return 0;
    }

    for (int i = 0; i < 10; i++) // 10번 반복하여 10개의 랜덤 정수를 생성하고 계산
    {
        RandomNumbers(min, max, &num); // 랜덤 정수 생성
        printf("%d ", num); // 생성된 정수 출력

        total = dcalculateSum(num, total); // 총합 계산
        totalSquared = dcalculateSquaredSum(num, totalSquared); // 제곱의 합 계산
    }

    printf("\n");

    average = total / 10.0;  // 평균 계산

    variance = dcalculateVariance(totalSquared, total, 10);  // 분산 계산

    std = dcalculateStandardDeviation(variance); // 표준편차 계산

    printf("총합: %.2f\n", total);
    printf("평균: %.2f\n", average);
    printf("분산: %.2f\n", variance);
    printf("표준편차: %.2f\n", std);  // 결과 출력

    return 0;
}