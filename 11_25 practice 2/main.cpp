#include <stdio.h>

int main(void)
{
	int i;
	char sentence1[100];
	char sentence2[100];
	char sentence3[100];
	char sentence4[100];//�Է� �޴� ���ڿ����� 4�� �̹Ƿ� ������ 4���� ����
	int change = 0;

	printf("���� �Է� :");
	scanf_s("%s %s %s %s", sentence1, sizeof(sentence1), sentence2, sizeof(sentence2), sentence3, sizeof(sentence3), sentence4, sizeof(sentence4));//������ ��ü �Է�

	for (i = 0; sentence1[i] != '\0'; i++)
	{
		if ((sentence1[i]>= 'A')&&(sentence1[i] <= 'Z'))
		{
			sentence1[i] += ('a' - 'A');
			change++;
		}// ù��° ������ DON'T�� don't�� ��ȯ
	}
	for (i = 0; sentence2[i] != '\0'; i++)
	{
		if ((sentence2[i] >= 'A') && (sentence2[i] <= 'Z'))
		{
			sentence2[i] += ('a' - 'A');
			change++;
		}// �ι�° ������ Worry�� worry�� ��ȯ
	}
	for (i = 0; sentence3[i] != '\0'; i++)
	{
		if ((sentence3[i] >= 'A') && (sentence3[i] <= 'Z'))
		{
			sentence3[i] += ('a' - 'A');
			change++;
		}// ����° ������ Be�� be�� ��ȯ
	}
	for (i = 0; sentence4[i] != '\0'; i++)
	{
		if ((sentence4[i] >= 'A') && (sentence4[i] <= 'Z'))
		{
			sentence4[i] += ('a' - 'A');
			change++;// ���忡�� �빮�ڿ��� �ҹ��ڷ� ���ϸ� 1�� ���ϱ�
		}// �׹�° ������ Happy�� happy�� ��ȯ
	}
	printf("�ٲ� ���� :%s %s %s %s\n",sentence1, sentence2, sentence3, sentence4);
	printf("�ٲ� ���� �� : %d\n", change);

	return 0;
}