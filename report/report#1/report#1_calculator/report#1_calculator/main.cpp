#include <stdio.h>

int main(void)
{
	int inserted = 0;
	int price = 0;
	int money_1000 = 0;
	int money_500 = 0;
	int money_100 = 0;
	int change = 0; // 모든 비용은 정수이므로 int로 하여 0으로 할당하였습니다.
	
	printf("투입한 금액을 입력하세요:");
	scanf_s("%d", &inserted);
	printf("물건 가격을 입력하세요:");
	scanf_s("%d", &price);

	change = inserted - price;// 투입한 가격과 물건값을 계산합니다.
	printf("거스름돈은 %d입니다.", change);

	money_1000 = change / 1000;//1000원 지폐에 남은 지폐를 계산하기 위하여 설정한 수식입니다.
	change = change % 1000;
	money_500 = change / 500;//500원 동전에 남은 동전을 계산하기 위하여 설정한 수식입니다.
	change = change % 500;
	money_100 = change / 100;//100원 동전에 남은 동전을 계산하기 위하여 설정한 수식입니다.
	change = change % 100;
	printf("1000원 지폐 : %d개입니다.", money_1000);
	printf("500원 동전 : %d개입니다.", money_500);
	printf("100원 동전 : %d개입니다.", money_100);

	return 0;
}