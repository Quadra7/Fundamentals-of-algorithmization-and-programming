#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void f(char symbol)
{
	switch (symbol)
	{
		case 10:
			printf("a");
			break;
		case 11:
			printf("b");
			break;
		case 12:
			printf("c");
			break;
		case 13:
			printf("d");
			break;
		case 14:
			printf("e");
			break;
		case 15:
			printf("f");
			break;
	}
}
int main()
{
	int N, b;
	int K = 0;
	char text[1000];
	scanf("%d", &b);
	scanf("%d", &N);
	char j = N % b;
	text[0] = j;
	while (N / b != 0)
	{
		K++;
		N = N / b;
		j = N % b;
		text[K] = j;
	}
	for (int i = K; i >= 0; i--)
	{
		text[i] > 9 ? f(text[i]) : printf("%d", text[i]);
	}
	return 0;
}
