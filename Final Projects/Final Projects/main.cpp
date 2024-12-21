#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592

void C_forces(double* rho, double* velocities, double* areas, double* coefficients, double* results)//��°� �׷� ��� �Լ�
{
    if (coefficients[0] != 0)//��� ��� (��� ����� ���� ���� ���)
    {
        results[0] = 0.5 * (*rho) * velocities[0] * velocities[0] * areas[0] * coefficients[0];
    }
    else
    {
        results[0] = 0;//��� ����� ������ ����� 0���� ����
    }

    if (coefficients[1] != 0)//�׷� ��� (�׷� ����� ���� ���� ���)
    {
        results[1] = 0.5 * (*rho) * velocities[0] * velocities[0] * areas[0] * coefficients[1];
    }
    else
    {
        results[1] = 0;//�׷� ����� ������ �׷��� 0���� ����
    }
}

int main(void)
{
    int num_case = 1;

    double* rho = (double*)malloc(sizeof(double));//���� �޸� �Ҵ�
    double* velocities = (double*)malloc(num_case * sizeof(double));
    double* areas = (double*)malloc(num_case * sizeof(double));
    double* coefficients = (double*)malloc(2 * sizeof(double));//��°� �׷� ����� �Բ� ����
    double* results = (double*)malloc(2 * sizeof(double));//��°� �׷� ����� �Բ� ����

    if (!rho || !velocities || !areas || !coefficients || !results)
    {
        printf("�޸� �Ҵ� ����\n");
        free(rho);
        free(velocities);
        free(areas);
        free(coefficients);
        free(results);
        return 1;
    }

    printf("���� �е��� �Է��ϼ��� (kg/m^3): ");//���� �е� �Է�
    scanf_s("%lf", rho);

    printf("\n������\n");//������ �Է�
    printf("�ӵ��� �Է��ϼ��� (m/s): ");
    scanf_s("%lf", &velocities[0]);

    printf("���� ������ �Է��ϼ��� (m^2): ");
    scanf_s("%lf", &areas[0]);

    printf("��� ���(C_L)�� �Է��ϼ��� (C_L, ������ 0�� �Է�): ");//��� ��� �Է�
    scanf_s("%lf", &coefficients[0]);

    printf("�׷� ���(C_D)�� �Է��ϼ��� (C_D, ������ 0�� �Է�): ");// �׷� ��� �Է�
    scanf_s("%lf", &coefficients[1]);

    C_forces(rho, velocities, areas, coefficients, results);//��°� �׷� ���

    printf("\n ��� \n");//��� ���
    if (coefficients[0] != 0)
    {
        printf("��� = %.2lf N\n", results[0]);
    }
    else
    {
        printf("��� ����� �Էµ��� �ʾ� ��� ����� �����߽��ϴ�.\n");
    }

    if (coefficients[1] != 0)
    {
        printf("�׷� = %.2lf N\n", results[1]);
    }
    else
    {
        printf("�׷� ����� �Էµ��� �ʾ� �׷� ����� �����߽��ϴ�.\n");
    }

    free(rho);//�޸� ����
    free(velocities);
    free(areas);
    free(coefficients);
    free(results);

    return 0;
}