#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int invtab_to_permut(int b[], int a[], int N)
{
    int num = 1;
    for (int i = 0 ; i < N; i++)
    {
        int pos = 0;
        for (int j = 0; j < N; j++)
        {
            if (pos == b[i] && a[j] == 0)
            {
                pos = j;
                break;
            }
            if (a[j] == 0) pos++;
        }
        a[pos] = num;
        num++;
    }
    for (int i = 0; i < N; i++)
    {
        if (a[i] == 0) return 0;
    }
    for (int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
    return 1;
}

int main()
{
    int N;
    int num = 1;
    scanf("%d", &N);
    int* a = (int*)malloc(N * sizeof(int));
    int* b = (int*)malloc(N * sizeof(int));
    for (int i = 0 ; i < N; i++)
    {
        scanf("%d", &b[i]);
        a[i] = 0;
    }
    if (invtab_to_permut(b,a,N) == 0) printf("NO");
    free(a);
    free(b);
    return 0;
}