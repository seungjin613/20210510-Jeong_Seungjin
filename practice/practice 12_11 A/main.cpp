#include <stdio.h>
#include <string.h>

void reverse(char *first, char *last)
{
    char temp;
    while (first < last)
    {
        temp = *first;
        *first = *last;
        *last = temp;
        first++;
        last--;
    }
}

int main(void) 
{
    char input[100];
    printf("Enter a string : ");
    fgets(input, sizeof(input), stdin);

    printf("Before removing newline : %s", input);

    input[strcspn(input, "\n")] = '\0';

    char* first = input;
    char* temp = input;

    while (*temp)
    {
        if (*temp == ' ') 
        {
            reverse(first, temp - 1);
            first = temp + 1;
        }
        temp++;
    }

    reverse(first, temp - 1);

    printf("After removing newline : %s\n", input);

    return 0;
}