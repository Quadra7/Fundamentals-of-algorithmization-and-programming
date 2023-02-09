#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
    int N, M;
    int k = 2;
    int sum = 0;
    scanf("%d", &N);
    for (int i = 0;i < N; i++)
    {
        scanf("%d", &M);
        while (M % k == 0)
        {
            M /= k;
            sum++;
        }
        printf("%d\n", (int)(pow(2,sum)));
        sum = 0;
    }
    return 0;
}