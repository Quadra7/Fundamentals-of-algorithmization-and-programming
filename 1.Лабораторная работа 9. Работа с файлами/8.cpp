#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int partition(int* a, int n, int pivot) 
{
    int j;
    bool f = false;
    int* left = new int[n];
    int lk = 0;
    int* right = new int[n];
    int rk = 0;
    for (int i = 0; i < n; i++) 
    {
        if (a[i] == pivot) 
        {
            !f ? left[lk++] = a[i] : right[rk++] = a[i]; 
            f = !f;
        }
        else if (a[i] < pivot) left[lk++] = a[i];
        else right[rk++] = a[i];
    }
    for (j = 0; j < lk; j++)
    {
        a[j] = left[j];
    }
    while (j < n)
    {
        a[j] = right[j - lk];
        j++;
    }
    return lk;
}

int main()
{
    int N, p;
    FILE* input, * output;
    input = fopen("input.bin", "rb");
    fread(&N, sizeof(int), 1, input);
    int* a = new int[N];
    fread(&p, sizeof(int), 1, input);
    for (int i = 0; i < N; i++)
    {
        fread(&a[i], sizeof(int), 1, input);
    }
    fclose(input);
    int lk = partition(a, N, p);
    output = fopen("output.bin", "wb");
    fwrite(&lk, sizeof(int), 1, output);
    for (int i = 0; i < N; i++)
    {
        fwrite(&a[i], sizeof(int), 1, output);
    }
    fclose(output);
    delete[] a;
    return 0;
}