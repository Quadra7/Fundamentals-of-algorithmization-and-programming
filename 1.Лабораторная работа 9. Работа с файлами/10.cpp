#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

void fast_sort(int* a, int r)
{
    int i = 0;
    int j = r - 1;
    int num = a[r / 2];
    do
    {
        while (a[i] < num) i++;
        while (a[j] > num) j--;
        if (i <= j) swap(a[i++], a[j--]);
    } while (i <= j);
    if (j > 0) fast_sort(a, j + 1);
    if (r > i) fast_sort(&a[i], r - i);
}
int main()
{
    int N;
    FILE* input, * output;
    input = fopen("input.bin", "rb");
    fread(&N, sizeof(int), 1, input);
    int* a = new int[N];
    for (int i = 0; i < N; i++)
    {
        fread(&a[i], sizeof(int), 1, input);
    }
    fclose(input);
    fast_sort(a, N);
    output = fopen("output.bin", "wb");
    for (int i = 0; i < N; i++)
    {
        fwrite(&a[i], sizeof(int), 1, output);
    }
    fclose(output);
    free(a);
    return 0;
}