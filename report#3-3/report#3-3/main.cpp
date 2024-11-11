#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber() //������ ���� ���� �Լ�
{
    return rand();
}

void playGame(int maxTries) // ������ �����ϴ� �Լ�
{
    int targetNumber = generateRandomNumber();  // ���� ����
    int guess, attempts = 0;

    printf("0���� ���� �����Ǵ� ������ ���ڸ� ���߼���! ��ȸ�� %d���Դϴ�.\n", maxTries);

    while (attempts < maxTries) // �ִ� �õ� Ƚ����ŭ �ݺ�
    {
        printf("���� ��ȸ: %d��\n", maxTries - attempts);
        printf("���ڸ� �����ϼ���: ");
        scanf_s("%d", &guess);

        attempts++;  // �õ� Ƚ�� ����

        if (guess < targetNumber) 
        {
            printf("��! ������ �� ū �����Դϴ�.\n");
        }
        else if (guess > targetNumber) 
        {
            printf("�ٿ�! ������ �� ���� �����Դϴ�.\n");
        }
        else 
        {
            printf("�����Դϴ�! %d�� ���� ���߼̽��ϴ�.\n", attempts);
            return;
        }
    }
    printf("���� ����! ������ %d�����ϴ�.\n", targetNumber); // ��ȸ�� �� ������ ���
}
int main() 
{
    int maxTries = 10;

    srand(time(NULL)); // ���� �õ� �ʱ�ȭ

    playGame(maxTries); // ���� ����

    return 0;
}