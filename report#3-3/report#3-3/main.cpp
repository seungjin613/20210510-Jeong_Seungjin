#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int RandomNumber() //������ ���� ���� �Լ�
{
    return rand();
}

void playGame(int Count) // ������ �����ϴ� �Լ�
{
    int targetNum = RandomNumber();  // ����
    int guess, attempts = 0;

    printf("0���� ���� �����Ǵ� ������ ���ڸ� ���߼���! ��ȸ�� %d���Դϴ�.\n", Count);

    while (attempts < Count) // �ִ� Ƚ����ŭ �ݺ�
    {
        printf("���� ��ȸ: %d��\n", Count - attempts);
        printf("���ڸ� ��Ȯ�ϰ� �Է��ϼ���.: ");
        scanf_s("%d", &guess);

        attempts++;  // �õ� Ƚ��

        if (guess < targetNum)
        {
            printf("��! �Է��� ���ں��� �� ū �����Դϴ�.\n");
        }
        else if (guess > targetNum)
        {
            printf("�ٿ�! �Է��� ���ں��� �� ���� �����Դϴ�.\n");
        }
        else
        {
            printf("����! %d�� ���� ���߼̽��ϴ�.\n", attempts);
            return;
        }
    }
    printf("���� ����! ������ %d�����ϴ�.\n", targetNum); // ��ȸ�� �� ������ ���
}

int main()
{
    int Count = 10; //���� Ƚ���� 10��

    srand(time(NULL)); // ���� �õ� �ʱ�ȭ

    playGame(Count); // ���� ����

    return 0;
}