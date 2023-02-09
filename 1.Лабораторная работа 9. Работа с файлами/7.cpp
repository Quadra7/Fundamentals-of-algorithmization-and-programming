#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int merge(const int* a, int ak, const int* b, int bk, int* res)
{
    int pos_a = 0, pos_b = 0;
    for (int i = 0; i < (ak + bk); i++)
    {
        if ((a[pos_a] < b[pos_b] && pos_a < ak) || pos_b == bk)
        {
            res[i] = a[pos_a];
            pos_a++;
        }
        else 
        {
            res[i] = b[pos_b];
            pos_b++;
        }
    }
    return (ak + bk);
}
int main()
{
    int N, M;
    FILE* input, * output;
    input = fopen("input.bin", "rb");
    fread(&N, sizeof(int), 1, input);
    int* a = new int[N];
    fread(&M, sizeof(int), 1, input);
    int* b = new int[M];
    int* res = new int[N + M];
    fread(a, sizeof(int), N, input);
    fread(b, sizeof(int), M, input);
    fclose(input);
    merge(a, N, b, M, res);
    output = fopen("output.bin", "wb");
    fwrite(res, sizeof(int), (N + M), output);
    fclose(output);
    free(a);
    free(b);
    free(res);
    return 0;
}