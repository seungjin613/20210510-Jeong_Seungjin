#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int RandomNumber() //무작위 숫자 생성 함수
{
    return rand();
}

void playGame(int Count) // 게임을 실행하는 함수
{
    int targetNum = RandomNumber();  // 정답
    int guess, attempts = 0;

    printf("0에서 부터 생성되는 랜덤의 숫자를 맞추세요! 기회는 %d번입니다.\n", Count);

    while (attempts < Count) // 최대 횟수만큼 반복
    {
        printf("남은 기회: %d번\n", Count - attempts);
        printf("숫자를 정확하게 입력하세요.: ");
        scanf_s("%d", &guess);

        attempts++;  // 시도 횟수

        if (guess < targetNum)
        {
            printf("업! 입력한 숫자보다 더 큰 숫자입니다.\n");
        }
        else if (guess > targetNum)
        {
            printf("다운! 입력한 숫자보다 더 작은 숫자입니다.\n");
        }
        else
        {
            printf("정답! %d번 만에 맞추셨습니다.\n", attempts);
            return;
        }
    }
    printf("게임 오버! 정답은 %d였습니다.\n", targetNum); // 기회가 다 끝났을 경우
}

int main()
{
    int Count = 10; //게임 횟수는 10번

    srand(time(NULL)); // 랜덤 시드 초기화

    playGame(Count); // 게임 시작

    return 0;
}