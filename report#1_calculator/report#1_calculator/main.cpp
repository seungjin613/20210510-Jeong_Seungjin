#include <stdio.h>

int main(void)
{
	int inserted = 0;
	int price = 0;
	int money_1000 = 0;
	int money_500 = 0;
	int money_100 = 0;
	int change = 0; // ��� ����� �����̹Ƿ� int�� �Ͽ� 0���� �Ҵ��Ͽ����ϴ�.
	
	printf("������ �ݾ��� �Է��ϼ���:");
	scanf_s("%d", &inserted);
	printf("���� ������ �Է��ϼ���:");
	scanf_s("%d", &price);

	change = inserted - price;// ������ ���ݰ� ���ǰ��� ����մϴ�.
	printf("�Ž������� %d�Դϴ�.", change);

	money_1000 = change / 1000;//1000�� ���� ���� ���� ����ϱ� ���Ͽ� ������ �����Դϴ�.
	change = change % 1000;
	money_500 = change / 500;//500�� ������ ���� ������ ����ϱ� ���Ͽ� ������ �����Դϴ�.
	change = change % 500;
	money_100 = change / 100;//100�� ������ ���� ������ ����ϱ� ���Ͽ� ������ �����Դϴ�.
	change = change % 100;
	printf("1000�� ���� : %d���Դϴ�.", money_1000);
	printf("500�� ���� : %d���Դϴ�.", money_500);
	printf("100�� ���� : %d���Դϴ�.", money_100);

	return 0;
}