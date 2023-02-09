#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>

void f(int x)
{
	switch (x)
	{
	case 10:
		printf("a"); break;
	case 11:
		printf("b"); break;
	case 12:
		printf("c"); break;
	case 13:
		printf("d"); break;
	case 14:
		printf("e"); break;
	case 15:
		printf("f"); break;
	}
}

int check(char symbol)
{
	switch (symbol)
	{
	case '1':
		return 1; break;
	case '2':
		return 2; break;
	case '3':
		return 3; break;
	case '4':
		return 4; break;
	case '5':
		return 5; break;
	case '6':
		return 6; break;
	case '7':
		return 7; break;
	case '8':
		return 8; break;
	case '9':
		return 9; break;
	case 'a':
		return 10; break;
	case 'b':
		return 11; break;
	case 'c':
		return 12; break;
	case 'd':
		return 13; break;
	case 'e':
		return 14; break;
	case 'f':
		return 15; break;
	default:
		return 0; break;
	}
}

int main()
{
	long double sum = 0;
	int b1, b2, k;
	scanf("%d %d %d", &b1, &b2, &k);
	char N1[100];
	scanf("%s", N1);
	int isDot = 0;
	int N1_before = 0, N1_after = 0;
	for (int i = 0; i < strlen(N1); i++)
	{
		if (check(N1[i]) >= b1)
		{
			printf("NO");
			return 0;
		}
		if (isDot > 1)
		{
			printf("NO");
			return 0;
		}
		if (N1[i] == '.')
		{
			isDot++;
			continue;
		}
		if (isDot == 0) N1_before++;
		if (isDot == 1) N1_after++;
	}
	if (N1_after <= 0) isDot = 1;
	for (int i = 0; i < strlen(N1); i++)
	{
		if (N1[i] == '.')
		{
			isDot = 0;
			continue;
		}
		if (isDot == 0)
		{
			sum += check(N1[i]) * pow(b1, N1_before - i);
			continue;
		}
		sum += check(N1[i]) * pow(b1, N1_before - i - 1);
	}
	int N2_before = (int)sum;
	long double N2_after = sum - N2_before;
	char N[1000];
	int q = 0;
	char j = N2_before % b2;
	N[0] = j;
	while (N2_before / b2 != 0)
	{
		q++;
		N2_before /= b2;
		j = N2_before % b2;
		N[q] = j;
	}
	for (int i = q; i >= 0; i--)
	{
		N[i] > 9 ? f(N[i]) : printf("%d", N[i]);
	}
	if (N1_after > 0 && N2_after > 0)
	{
		printf(".");
		int arrResult[100];
		for (int i = 0; i < k; i++) 
		{
			N2_after *= b2;
			arrResult[i] = (int)(N2_after + 0.00001);
			if (N2_after == 0)
			{
				k = i;
				break;
			}
			if (N2_after > 0) N2_after -= arrResult[i];
		}
		while (arrResult[k-1] == 0)
		{
			k--;
		}
		for (int i = 0; i < k; i++)
		{
			arrResult[i] > 9 ? f(arrResult[i]) : printf("%d", arrResult[i]);
		}
	}
	return 0;
}