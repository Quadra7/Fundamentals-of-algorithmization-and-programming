#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double C(int N, int K)
{
	double x = 1;
	for (int i = 1; i <= K; i++)
	{
		x = x * (N - K + i) / i;
	}
	return x;
}

int main()
{
	int Q;
	int N, K;
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++)
	{
		scanf("%d %d", &N, &K);
		printf("%0.10g\n", C(N, K));
	}
	return 0;
}