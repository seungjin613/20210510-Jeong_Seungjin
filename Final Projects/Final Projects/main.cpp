#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592

void C_forces(double* rho, double* velocities, double* areas, double* coefficients, double* results)//양력과 항력 계산 함수
{
    if (coefficients[0] != 0)//양력 계산 (양력 계수가 있을 때만 계산)
    {
        results[0] = 0.5 * (*rho) * velocities[0] * velocities[0] * areas[0] * coefficients[0];
    }
    else
    {
        results[0] = 0;//양력 계수가 없으면 양력은 0으로 설정
    }

    if (coefficients[1] != 0)//항력 계산 (항력 계수가 있을 때만 계산)
    {
        results[1] = 0.5 * (*rho) * velocities[0] * velocities[0] * areas[0] * coefficients[1];
    }
    else
    {
        results[1] = 0;//항력 계수가 없으면 항력은 0으로 설정
    }
}

int main(void)
{
    int num_case = 1;

    double* rho = (double*)malloc(sizeof(double));//동적 메모리 할당
    double* velocities = (double*)malloc(num_case * sizeof(double));
    double* areas = (double*)malloc(num_case * sizeof(double));
    double* coefficients = (double*)malloc(2 * sizeof(double));//양력과 항력 계수를 함께 저장
    double* results = (double*)malloc(2 * sizeof(double));//양력과 항력 결과를 함께 저장

    if (!rho || !velocities || !areas || !coefficients || !results)
    {
        printf("메모리 할당 실패\n");
        free(rho);
        free(velocities);
        free(areas);
        free(coefficients);
        free(results);
        return 1;
    }

    printf("공기 밀도를 입력하세요 (kg/m^3): ");//공기 밀도 입력
    scanf_s("%lf", rho);

    printf("\n데이터\n");//데이터 입력
    printf("속도를 입력하세요 (m/s): ");
    scanf_s("%lf", &velocities[0]);

    printf("날개 면적을 입력하세요 (m^2): ");
    scanf_s("%lf", &areas[0]);

    printf("양력 계수(C_L)를 입력하세요 (C_L, 없으면 0을 입력): ");//양력 계수 입력
    scanf_s("%lf", &coefficients[0]);

    printf("항력 계수(C_D)를 입력하세요 (C_D, 없으면 0을 입력): ");// 항력 계수 입력
    scanf_s("%lf", &coefficients[1]);

    C_forces(rho, velocities, areas, coefficients, results);//양력과 항력 계산

    printf("\n 결과 \n");//결과 출력
    if (coefficients[0] != 0)
    {
        printf("양력 = %.2lf N\n", results[0]);
    }
    else
    {
        printf("양력 계수가 입력되지 않아 양력 계산을 생략했습니다.\n");
    }

    if (coefficients[1] != 0)
    {
        printf("항력 = %.2lf N\n", results[1]);
    }
    else
    {
        printf("항력 계수가 입력되지 않아 항력 계산을 생략했습니다.\n");
    }

    free(rho);//메모리 해제
    free(velocities);
    free(areas);
    free(coefficients);
    free(results);

    return 0;
}