#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void f(int x)
{
    switch (x)
    {
    case 10:
        printf("a");
        break;
    case 11:
        printf("b");
        break;
    case 12:
        printf("c");
        break;
    case 13:
        printf("d");
        break;
    case 14:
        printf("e");
        break;
    case 15:
        printf("f");
        break;
    }
}

int main()
{
    int b, k;
    double N1;
    scanf("%d %d", &b, &k);
    scanf("%lf", &N1);
    int N2[1000];
    int t = k;
    if (k < 5) k = 5;
    int j;
    for (int i = 0; i < k; i++)
    {
        N1 *= b;
        if (N1 >= 1)
        {
            j = (int)(N1 + 0.00001);
            N1 -= j;
        }
        else
        {
            j = 0;
        }
        N2[i] = j;
    }
    if (t < 5)
    {
        for (int i = k - 1; i > t - 1; i--)
        {
            if (N2[i] >= (b + 1) / 2) N2[i - 1]++;
            if (N2[i] >= b) N2[i] = 0;
        }
    }
    while (N2[t - 1] == 0)
    {
        t--;
    }
    printf("0.");
    for (int i = 0; i < t; i++)
    {
    	N2[i] > 9 ? f(N2[i]) : printf("%d", N2[i]);
    }
}