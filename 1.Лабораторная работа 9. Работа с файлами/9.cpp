#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

void merge_sort(int* a, int left, int right) 
{
    if (right - left == 0) return;
    if (right - left == 1) 
    {
        if (a[right] < a[left])
        {
            int num = a[right];
            a[right] = a[left];
            a[left] = num;
        }
        return;
    }
    int mid = (right + left) / 2;
    merge_sort(a, left, mid);
    merge_sort(a, mid + 1, right);
    int* temp = new int[right - left + 1];
    int left_1 = left;
    int right_1 = mid + 1;
    for (int i = 0; i < right - left + 1; i++)
    {
        if (left_1 > mid) temp[i] = a[right_1++];
        else if (right_1 > right) temp[i] = a[left_1++];
        else if (a[left_1] < a[right_1]) temp[i] = a[left_1++];
        else temp[i] = a[right_1++];
    }
    int x = left;
    int y = 0;
    while (x <= right)
    {
        a[x++] = temp[y++];
    }
    delete[] temp;
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
    if (N > 1) merge_sort(a, 0, N - 1);
    output = fopen("output.bin", "wb");
    for (int i = 0; i < N; i++)
    {
        fwrite(&a[i], sizeof(int), 1, output);
    }
    fclose(output);
    delete[] a;
    return 0;
}