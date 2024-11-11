#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber() //무작위 숫자 생성 함수
{
    return rand();
}

void playGame(int maxTries) // 게임을 실행하는 함수
{
    int targetNumber = generateRandomNumber();  // 정답 숫자
    int guess, attempts = 0;

    printf("0에서 부터 생성되는 랜덤의 숫자를 맞추세요! 기회는 %d번입니다.\n", maxTries);

    while (attempts < maxTries) // 최대 시도 횟수만큼 반복
    {
        printf("남은 기회: %d번\n", maxTries - attempts);
        printf("숫자를 추측하세요: ");
        scanf_s("%d", &guess);

        attempts++;  // 시도 횟수 증가

        if (guess < targetNumber) 
        {
            printf("업! 정답은 더 큰 숫자입니다.\n");
        }
        else if (guess > targetNumber) 
        {
            printf("다운! 정답은 더 작은 숫자입니다.\n");
        }
        else 
        {
            printf("정답입니다! %d번 만에 맞추셨습니다.\n", attempts);
            return;
        }
    }
    printf("게임 오버! 정답은 %d였습니다.\n", targetNumber); // 기회가 다 끝났을 경우
}
int main() 
{
    int maxTries = 10;

    srand(time(NULL)); // 랜덤 시드 초기화

    playGame(maxTries); // 게임 시작

    return 0;
}