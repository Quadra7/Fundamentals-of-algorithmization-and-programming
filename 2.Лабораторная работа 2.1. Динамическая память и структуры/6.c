#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void reverse(char* start, int len)
{
    char* end = start + len - 1;
    while (start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    char start[100];
    for (int i = 0; i < N; i++)
    {
        scanf("%s", start);
        reverse(start, strlen(start));
        printf("%s\n", start);
    }
    return 0;
}