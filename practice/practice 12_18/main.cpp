#include <stdio.h>
#include <math.h>

struct Point// 3차원 점을 나타내는 구조체
{
    double x;
    double y;
    double z;
};
typedef struct Point;

double CDistance(Point* p1, Point* p2)// 두 점 사이의 유클리드 거리 계산 함수
{
    return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2) + pow(p2->z - p1->z, 2));// 포인터를 통해 두 점의 좌표에 접근하여 거리 계산
}

int main(void) 
{
    Point point[2];//두 점을 배열로 정의하여 입력

    printf("첫번째 점의 좌표를 입력하세요.\n");
    printf("x_1: ");
    scanf_s("%lf", &point[0].x);
    printf("y_1: ");
    scanf_s("%lf", &point[0].y);
    printf("z_1: ");
    scanf_s("%lf", &point[0].z);

    printf("두번째 점의 좌표를 입력하세요 :\n");
    printf("x_2: ");
    scanf_s("%lf", &point[1].x);
    printf("y_2: ");
    scanf_s("%lf", &point[1].y);
    printf("z_2: ");
    scanf_s("%lf", &point[1].z);

    double Distance = CDistance(&point[0], &point[1]);// 배열의 첫 번째 점과 두 번째 점에 대하여 유클리드 거리 계산

    printf("두 점 사이에 거리는 : %f\n", Distance);// 거리 출력

    return 0;
}