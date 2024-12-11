#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void CStats(int* array, int size, double* sum, double* mean, double* variance, double* std_dev) 
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
    int inSize, addSize;
    int* array;

    printf("�ʱ� �迭 ũ��: ");
    scanf_s("%d", &inSize);

    array = (int*)malloc(inSize * sizeof(int));
    if (array == NULL) 
    {
        printf("�޸� ����\n");
        return 1;
    }

    printf("�Էµ� ��: ", inSize);
    for (int i = 0; i < inSize; i++)
    {
        scanf_s("%d", &array[i]);
    }

    double sum, mean, variance, std_dev;
    
    CStats(array, inSize, &sum, &mean, &variance, &std_dev);

    printf("�հ�: %.2lf\n", sum);
    printf("���: %.2lf\n", mean);
    printf("�л�: %.2lf\n", variance);
    printf("ǥ������: %.2lf\n", std_dev);

    printf("�߰� �迭 ũ��: ");
    scanf_s("%d", &addSize);

    array = (int*)realloc(array, (static_cast < unsigned long long > (inSize) + addSize) * sizeof(int));
    if (array == NULL) 
    {
        printf("�޸� ����\n");
        return 1;
    }

    printf("�߰��� ��: ", addSize);
    for (int i = inSize; i < inSize + addSize; i++)
    {
        scanf_s("%d", &array[i]);
    }

    CStats(array, inSize + addSize, &sum, &mean, &variance, &std_dev);

    printf("���ο� �հ�: %.2lf\n", sum);
    printf("���ο� ���: %.2lf\n", mean);
    printf("���ο� �л�: %.2lf\n", variance);
    printf("���ο� ǥ������: %.2lf\n", std_dev);

    free(array);

    return 0;
}