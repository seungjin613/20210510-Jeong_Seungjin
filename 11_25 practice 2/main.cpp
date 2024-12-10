#include <stdio.h>

int main(void)
{
	int i;
	char sentence1[100];
	char sentence2[100];
	char sentence3[100];
	char sentence4[100];//입력 받는 문자열수가 4개 이므로 변수를 4개를 지정
	int change = 0;

	printf("문장 입력 :");
	scanf_s("%s %s %s %s", sentence1, sizeof(sentence1), sentence2, sizeof(sentence2), sentence3, sizeof(sentence3), sentence4, sizeof(sentence4));//문장을 전체 입력

	for (i = 0; sentence1[i] != '\0'; i++)
	{
		if ((sentence1[i]>= 'A')&&(sentence1[i] <= 'Z'))
		{
			sentence1[i] += ('a' - 'A');
			change++;
		}// 첫번째 문장인 DON'T를 don't로 변환
	}
	for (i = 0; sentence2[i] != '\0'; i++)
	{
		if ((sentence2[i] >= 'A') && (sentence2[i] <= 'Z'))
		{
			sentence2[i] += ('a' - 'A');
			change++;
		}// 두번째 문장인 Worry를 worry로 변환
	}
	for (i = 0; sentence3[i] != '\0'; i++)
	{
		if ((sentence3[i] >= 'A') && (sentence3[i] <= 'Z'))
		{
			sentence3[i] += ('a' - 'A');
			change++;
		}// 세번째 문장인 Be를 be로 변환
	}
	for (i = 0; sentence4[i] != '\0'; i++)
	{
		if ((sentence4[i] >= 'A') && (sentence4[i] <= 'Z'))
		{
			sentence4[i] += ('a' - 'A');
			change++;// 문장에서 대문자에서 소문자로 변하면 1씩 더하기
		}// 네번째 문장인 Happy를 happy로 변환
	}
	printf("바뀐 문장 :%s %s %s %s\n",sentence1, sentence2, sentence3, sentence4);
	printf("바뀐 문자 수 : %d\n", change);

	return 0;
}