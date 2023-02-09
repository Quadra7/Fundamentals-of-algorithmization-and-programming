#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	long float sum = 0;
	long int number;
	FILE *input, *output;
	input = fopen("input.bin", "rb");
	while (fread(&number, 1, sizeof(int), input))
	{
		sum += number;
	}
	fclose(input);
	number = floor (sum / 2);
	output = fopen("output.bin", "wb");
	fwrite(&number, 1, sizeof(int), output);
	fclose(output);
	return 0;
}