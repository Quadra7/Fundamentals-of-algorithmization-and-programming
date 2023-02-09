#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	unsigned int N;
	int b = 2;
	int K = 0;
	char text[100];
	scanf("%ud", &N);
	char j = N % b;
	text[0] = j;
	while (N / b != 0)
	{
		K++;
		N /= b;
		j = N % b;
		text[K] = j;
	}
	int sum = 0;
	int temp = 0;
	for (int i = K; i >= 0; i--)
	{
		if (text[i] == 1) temp++;
		else
		{
			if (sum < temp) sum = temp;
			temp = 0;
		}
	}
	if (temp > sum) sum = temp;
	printf("%d", sum);
	return 0;
}
