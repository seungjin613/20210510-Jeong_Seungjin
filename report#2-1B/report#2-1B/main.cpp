#include <stdio.h>

int main(void)
{
	int num = 0;//�Է� �޴� ���� �����̹Ƿ� int�� Ȱ���Ͽ� ��������
	printf("������ �Է��ϼ���:\n");
	scanf_s("%d", &num);

	switch (num % 2)//�Է� ���� ������ 2�� ������.
	{
	case 0://������ 2�� �������� �������� 0�̸� ¦���� ���
	{
		printf("�Է��Ͻ� ������ ¦���Դϴ�.");
		break;
	}
	default ://������ 2�� �������� �������� 0�� �ƴϸ� Ȧ���� ���
	{
		printf("�Է��Ͻ� ������ Ȧ���Դϴ�.");
		break;
	}
	}
	return 0;
}