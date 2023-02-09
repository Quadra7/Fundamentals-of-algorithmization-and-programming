#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int reverse(int num)
{
    int temp;
    char* num_b = (char*)&num;
    char* temp_b = (char*)&temp;
    temp_b[0] = num_b[3];
    temp_b[1] = num_b[2];
    temp_b[2] = num_b[1];
    temp_b[3] = num_b[0];
    return temp;
}
int main()
{
    int n;
    int num, sum = 0;
    bool f = false;
    FILE *input, *output;
    input = fopen("input.bin", "rb");
    fread(&n, sizeof(int), 1, input);
    if (n > 10000)
    {
        n = reverse(n);
        f = true;
    }
    while (fread(&num, sizeof(int), 1, input))
    {
        sum += f ? reverse(num) : num;
    }
    fclose(input);
    sum = f ? reverse(sum) : sum;
    output = fopen("output.bin", "wb");
    fwrite(&sum, sizeof(int), 1, output);
    fclose(output);
    return 0;
}