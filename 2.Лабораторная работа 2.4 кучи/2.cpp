#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

void function(int a[], int l, int r)
{
    int left = (2 * l) + 1;
    int right = left + 1;
    int index = l;
    if (left < r && a[index] < a[left])
    {
        index = left;
    }
    if (right < r && a[index] < a[right])
    {
        index = right;
    }

    if (index != l)
    {
        swap(a[l], a[index]);
        function(a, index, r);
    }
}

void heap_sort(int* a, int N)
{
    for (int i = (N / 2) - 1; i >= 0; i--)
    {
        function(a, i, N);
    }
    for (int i = N - 1; i >= 1; i--)
    {
        swap(a[0], a[i]);
        function(a, 0, i);
    }
}
 
int main () 
{
    int N;
    FILE * input, *output;
    input = fopen("input.bin", "rb");
    fread(&N, sizeof (int), 1, input);
    int *a = new int[N];
    for (int i = 0; i < N; i++)
    {
        fread(&a[i], sizeof (int), 1, input);
    } 
    fclose(input);
    heap_sort(a, N);
    output = fopen ("output.bin", "wb");
    for (int i = 0; i < N; i++)
    {
        fwrite(&a[i], sizeof (int), 1, output);
    } 
    fclose(output);
    free(a);
    return 0;
}