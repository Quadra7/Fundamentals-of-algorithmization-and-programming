#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>

int type(char X)
{
	switch (X)
	{
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	case 'a':
		return 10;
	case 'b':
		return 11;
	case 'c':
		return 12;
	case 'd':
		return 13;
	case 'e':
		return 14;
	case 'f':
		return 15;
	default:
		return 0;
	}
}

int main()
{
	int b;
	char N[1000];
	long long sum = 0;
	int T = 0;
	scanf("%d", &b);
	scanf("%s", N);
	int K = strlen(N);
	do
	{
		int X = type(N[K - 1]);
		sum += X * pow(b, T++);
		K--;
	} while (K != 0);
	printf("%lld", sum);
}