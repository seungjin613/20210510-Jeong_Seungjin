#include <stdio.h>

int main(void)
{
	int num = 0;
	int i = 0;
	int j = 0;
	printf("원하는 단을 입력하세요\n그러나 2단부터 9단까지 전부 보고 싶으면 1을 입력하세요.\n");
	scanf_s("%d", &num);

	switch (num)
	{
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	{
		for (i = 1; i <= 9; i++)
		{
			printf("%d * %d = %d\n", num, i, num * i);
		}
	break;
	}
	case 1:
	{
		for (i = 2; i <= 9; i++)
		{
			for (j = 1; j <= 9; j++)
			{
				printf("%d * %d = %d\n", i, j, i * j);
			}
		}
		break;
	}
	}
	printf("입력하신 구구단은 이렇게 나옵니다.");
	return 0;
}