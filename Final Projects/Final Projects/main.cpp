#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592

// ��°� �׷��� ����ϴ� �Լ�
void calculate_forces(double* rho, double* velocities, double* areas, double* coefficients, double* results, int n) {
    for (int i = 0; i < n; i++) {
        results[2 * i] = 0.5 * (*rho) * velocities[i] * velocities[i] * areas[i] * coefficients[2 * i];     // ��� ���
        results[2 * i + 1] = 0.5 * (*rho) * velocities[i] * velocities[i] * areas[i] * coefficients[2 * i + 1]; // �׷� ���
    }
}

int main() {
    int num_cases;
    printf("����� �������� ������ �Է��ϼ���: ");
    scanf_s("%d", &num_cases);

    if (num_cases <= 0) {
        printf("�߸��� �Է��Դϴ�. 1 �̻��� ���� �Է��ϼ���.\n");
        return 1;
    }

    // ���� �޸� �Ҵ�
    double* rho = (double*)malloc(sizeof(double));
    double* velocities = (double*)malloc(num_cases * sizeof(double));
    double* areas = (double*)malloc(num_cases * sizeof(double));
    double* coefficients = (double*)malloc(num_cases * 2 * sizeof(double)); // ��°� �׷� ����� �Բ� ����
    double* results = (double*)malloc(num_cases * 2 * sizeof(double));      // ��°� �׷� ����� �Բ� ����

    if (!rho || !velocities || !areas || !coefficients || !results) {
        printf("�޸� �Ҵ� ����\n");
        free(rho);
        free(velocities);
        free(areas);
        free(coefficients);
        free(results);
        return 1;
    }

    // ���� �е� �Է�
    printf("���� �е��� �Է��ϼ��� (kg/m^3): ");
    scanf_s("%lf", rho);

    // ������ �Է�
    for (int i = 0; i < num_cases; i++) {
        printf("\n--- ������ %d ---\n", i + 1);
        printf("�ӵ��� �Է��ϼ��� (m/s): ");
        scanf_s("%lf", &velocities[i]);

        printf("���� ������ �Է��ϼ��� (m^2): ");
        scanf_s("%lf", &areas[i]);

        printf("��� ����� �Է��ϼ��� (C_L): ");
        scanf_s("%lf", &coefficients[2 * i]);

        printf("�׷� ����� �Է��ϼ��� (C_D): ");
        scanf_s("%lf", &coefficients[2 * i + 1]);
    }

    // ��°� �׷� ���
    calculate_forces(rho, velocities, areas, coefficients, results, num_cases);

    // ��� ���
    printf("\n--- ��� ---\n");
    for (int i = 0; i < num_cases; i++) {
        printf("������ %d: ��� = %.2lf N, �׷� = %.2lf N\n", i + 1, results[2 * i], results[2 * i + 1]);
    }

    // �޸� ����
    free(rho);
    free(velocities);
    free(areas);
    free(coefficients);
    free(results);

    return 0;
}