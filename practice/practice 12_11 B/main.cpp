#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calculateStats(int* array, int size, double* sum, double* mean, double* variance, double* std_dev) 
{
    *sum = 0;
    *variance = 0;

    for (int i = 0; i < size; i++) 
    {
        *sum += array[i];
    }
    *mean = *sum / size;

    for (int i = 0; i < size; i++) 
    {
        *variance += pow(array[i] - *mean, 2);
    }
    *variance /= size;

    *std_dev = sqrt(*variance);
}

int main(void) 
{
    int initialSize, additionalSize;
    int* array;

    printf("초기 배열 크기: ");
    scanf_s("%d", &initialSize);

    array = (int*)malloc(initialSize * sizeof(int));
    if (array == NULL) 
    {
        printf("메모리 실패\n");
        return 1;
    }

    printf("입력된 값: ", initialSize);
    for (int i = 0; i < initialSize; i++) 
    {
        scanf_s("%d", &array[i]);
    }

    double sum, mean, variance, std_dev;
    calculateStats(array, initialSize, &sum, &mean, &variance, &std_dev);

    printf("합계: %.2lf\n", sum);
    printf("평균: %.2lf\n", mean);
    printf("분산: %.2lf\n", variance);
    printf("표준편차: %.2lf\n", std_dev);

    printf("추가 배열 크기: ");
    scanf_s("%d", &additionalSize);

    array = (int*)realloc(array, (static_cast<unsigned long long>(initialSize) + additionalSize) * sizeof(int));
    if (array == NULL) 
    {
        printf("메모리 실패\n");
        return 1;
    }

    printf("추가된 값: ", additionalSize);
    for (int i = initialSize; i < initialSize + additionalSize; i++)
    {
        scanf_s("%d", &array[i]);
    }

    calculateStats(array, initialSize + additionalSize, &sum, &mean, &variance, &std_dev);

    printf("새로운 합계: %.2lf\n", sum);
    printf("새로운 평균: %.2lf\n", mean);
    printf("새로운 분산: %.2lf\n", variance);
    printf("새로운 표준편차: %.2lf\n", std_dev);

    free(array);

    return 0;
}