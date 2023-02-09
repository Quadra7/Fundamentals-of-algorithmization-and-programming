#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>

int f(char symbol)
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
		case 'g':
			return 16; break;
		case 'h': 
			return 17; break;
		case 'i':
			return 18; break;
		case 'j':
			return 19; break;
		case 'k':
			return 20; break;
		case 'l':
			return 21; break;
		case 'm':
			return 22; break;
		case 'n':
			return 23; break;
		case 'o':
			return 24; break;
		case 'p':
			return 25; break;
		case 'q':
			return 26; break;
		case 'r':
			return 27; break;
		case 's':
			return 28; break;
		case 't':
			return 29; break;
		case 'u':
			return 30; break;
		case 'v':
			return 31; break;
		case 'w':
			return 32; break;
		case 'x':
			return 33; break;
		case 'y':
			return 34; break;
		case 'z':
			return 35; break;
		default:
		    return 0; break;
	}
}

void f1(char symbol)
{
	switch (symbol)
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
		case 16:
			printf("g"); break;
		case 17:
			printf("h"); break;
		case 18:
			printf("i"); break;
		case 19:
			printf("j"); break;
		case 20:
			printf("k"); break;
		case 21:
			printf("l"); break;
		case 22:
			printf("m"); break;
		case 23:
			printf("n"); break;
		case 24:
			printf("o"); break;
		case 25:
			printf("p"); break;
		case 26:
			printf("q"); break;
		case 27:
			printf("r"); break;
		case 28:
			printf("s"); break;
		case 29:
			printf("t"); break;
		case 30:
			printf("u"); break;
		case 31:
			printf("v"); break;
		case 32:
			printf("w"); break;
		case 33:
			printf("x"); break;
		case 34:
			printf("y"); break;
		case 35:
			printf("z"); break;
	}
}


int main()
{
    int b1, b2;
    int sum = 0;
    char N1[100];
    char N2[100];
    scanf("%d %d %s", &b1, &b2, N1);
    int K = strlen(N1);
    int T = K - 1;
    for (int i = 0;i < K;i++)
    {
        sum += f(N1[i]) * pow(b1, T);
        T--;
    }
    T = 0;
    char j = sum % b2;
	N2[0] = j;
	while (sum / b2 != 0)
	{
		T++;
		sum /= b2;
		j = sum % b2;
		N2[T] = j;
	}
	for (int i = T; i >= 0; i--)
	{
		N2[i] > 9 ? f1(N2[i]) : printf("%d", N2[i]);
	}
    return 0;
}