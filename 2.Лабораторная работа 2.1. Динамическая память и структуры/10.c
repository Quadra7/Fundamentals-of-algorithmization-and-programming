#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

union
{
    long long l;
    double d;
} u;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int P, Q;
        long long int M;
        scanf("%d/%d xor %llx", &P, &Q, &M);
        double X = (double)P / Q;
        u.d = X;
        u.l ^= M;
        printf("%0.15g\n", u.d);
    }
    return 0;
}