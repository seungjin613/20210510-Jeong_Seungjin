#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592

// 양력과 항력을 계산하는 함수
void calculate_forces(double* rho, double* velocities, double* areas, double* coefficients, double* results, int n) {
    for (int i = 0; i < n; i++) {
        results[2 * i] = 0.5 * (*rho) * velocities[i] * velocities[i] * areas[i] * coefficients[2 * i];     // 양력 계산
        results[2 * i + 1] = 0.5 * (*rho) * velocities[i] * velocities[i] * areas[i] * coefficients[2 * i + 1]; // 항력 계산
    }
}

int main() {
    int num_cases;
    printf("계산할 데이터의 개수를 입력하세요: ");
    scanf_s("%d", &num_cases);

    if (num_cases <= 0) {
        printf("잘못된 입력입니다. 1 이상의 값을 입력하세요.\n");
        return 1;
    }

    // 동적 메모리 할당
    double* rho = (double*)malloc(sizeof(double));
    double* velocities = (double*)malloc(num_cases * sizeof(double));
    double* areas = (double*)malloc(num_cases * sizeof(double));
    double* coefficients = (double*)malloc(num_cases * 2 * sizeof(double)); // 양력과 항력 계수를 함께 저장
    double* results = (double*)malloc(num_cases * 2 * sizeof(double));      // 양력과 항력 결과를 함께 저장

    if (!rho || !velocities || !areas || !coefficients || !results) {
        printf("메모리 할당 실패\n");
        free(rho);
        free(velocities);
        free(areas);
        free(coefficients);
        free(results);
        return 1;
    }

    // 공기 밀도 입력
    printf("공기 밀도를 입력하세요 (kg/m^3): ");
    scanf_s("%lf", rho);

    // 데이터 입력
    for (int i = 0; i < num_cases; i++) {
        printf("\n--- 데이터 %d ---\n", i + 1);
        printf("속도를 입력하세요 (m/s): ");
        scanf_s("%lf", &velocities[i]);

        printf("날개 면적을 입력하세요 (m^2): ");
        scanf_s("%lf", &areas[i]);

        printf("양력 계수를 입력하세요 (C_L): ");
        scanf_s("%lf", &coefficients[2 * i]);

        printf("항력 계수를 입력하세요 (C_D): ");
        scanf_s("%lf", &coefficients[2 * i + 1]);
    }

    // 양력과 항력 계산
    calculate_forces(rho, velocities, areas, coefficients, results, num_cases);

    // 결과 출력
    printf("\n--- 결과 ---\n");
    for (int i = 0; i < num_cases; i++) {
        printf("데이터 %d: 양력 = %.2lf N, 항력 = %.2lf N\n", i + 1, results[2 * i], results[2 * i + 1]);
    }

    // 메모리 해제
    free(rho);
    free(velocities);
    free(areas);
    free(coefficients);
    free(results);

    return 0;
}