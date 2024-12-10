#include <stdio.h>

double IProduct(double* a, double* b) // ���� ���� �Լ�
{
    return (a[0] * b[0]) + (a[1] * b[1]) + (a[2] * b[2]);
}

void CProduct(double* a, double* b, double* result) // ���� ���� �Լ�
{
    result[0] = a[1] * b[2] - a[2] * b[1];
    result[1] = a[2] * b[0] - a[0] * b[2];
    result[2] = a[0] * b[1] - a[1] * b[0];
}

int main(void)
{
    double vector_a[3] = { 1, 3, 2 }; // ���� A�� B�� ����
    double vector_b[3] = { 2, 1, 3 };
    double c_result[3];

    double I_result = IProduct(vector_a, vector_b);// ���� ���
    
    CProduct(vector_a, vector_b, c_result);// �����ͷ� �迭�� ù ��°�� �����Ͽ� ���� ���

    printf("Vector A: (%.2lf, %.2lf, %.2lf)\n", vector_a[0], vector_a[1], vector_a[2]);// ��� ���
    printf("Vector B: (%.2lf, %.2lf, %.2lf)\n", vector_b[0], vector_b[1], vector_b[2]);
    printf("Inner Product: %.2f\n", I_result);
    printf("Cross Product: (%.2lf, %.2lf, %.2lf)\n", c_result[0], c_result[1], c_result[2]);

    return 0;
}