#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define X 2001

int main()
{
	int M, T, N, K;
	int** c = (int**)malloc(X * sizeof(int*));
	scanf("%d %d", &M, &T);
	c[0] = (int*)malloc(sizeof(int));
	c[1] = (int*)malloc(2 * sizeof(int));
	c[0][0] = 1;
	c[1][0] = 1;
	c[1][1] = 1;
	for (int i = 2; i < X; i++)
	{
		c[i] = (int*)malloc((i + 1) * sizeof(int));
		c[i][0] = 1;
		c[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % M;
		}
	}
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d", &N, &K);
		if (K < 0 || N < K)
		{
			printf("0\n");
			continue;
		}
		printf("%d\n", c[N][K]);
	}
	free(c);
	return 0;
}