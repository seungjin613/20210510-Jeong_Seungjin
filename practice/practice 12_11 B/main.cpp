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

    printf("�ʱ� �迭 ũ��: ");
    scanf_s("%d", &initialSize);

    array = (int*)malloc(initialSize * sizeof(int));
    if (array == NULL) 
    {
        printf("�޸� ����\n");
        return 1;
    }

    printf("�Էµ� ��: ", initialSize);
    for (int i = 0; i < initialSize; i++) 
    {
        scanf_s("%d", &array[i]);
    }

    double sum, mean, variance, std_dev;
    calculateStats(array, initialSize, &sum, &mean, &variance, &std_dev);

    printf("�հ�: %.2lf\n", sum);
    printf("���: %.2lf\n", mean);
    printf("�л�: %.2lf\n", variance);
    printf("ǥ������: %.2lf\n", std_dev);

    printf("�߰� �迭 ũ��: ");
    scanf_s("%d", &additionalSize);

    array = (int*)realloc(array, (static_cast<unsigned long long>(initialSize) + additionalSize) * sizeof(int));
    if (array == NULL) 
    {
        printf("�޸� ����\n");
        return 1;
    }

    printf("�߰��� ��: ", additionalSize);
    for (int i = initialSize; i < initialSize + additionalSize; i++)
    {
        scanf_s("%d", &array[i]);
    }

    calculateStats(array, initialSize + additionalSize, &sum, &mean, &variance, &std_dev);

    printf("���ο� �հ�: %.2lf\n", sum);
    printf("���ο� ���: %.2lf\n", mean);
    printf("���ο� �л�: %.2lf\n", variance);
    printf("���ο� ǥ������: %.2lf\n", std_dev);

    free(array);

    return 0;
}