#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>

int f(char symbol)
{
    switch (symbol)
	{
	    case '1':
	        return 1;
	        break;
	    case '2':
	        return 2;
	        break;
	    case '3':
	        return 3;
	        break;
	    case '4':
	        return 4;
	        break;
	    case '5':
	        return 5;
	        break;
	    case '6':
	        return 6;
	        break;
	    case '7':
	        return 7;
	        break;
	    case '8':
	        return 8;
	        break;
	    case '9':
	        return 9;
	        break;
		case 'a':
			return 10;
			break;
		case 'b':
			return 11;
			break;
		case 'c':
			return 12;
			break;
		case 'd':
			return 13;
			break;
		case 'e':
			return 14;
			break;
		case 'f':
			return 15;
			break;
		default:
		    return 0;
		    break;
	}
}

int main()
{
    int b;
    float sum = 0;
    int T = -1;
    char N[100];
    scanf("%d", &b);
    scanf("%s", N);
    int K = strlen(N);
    for (int i = 2; i < K; i++)
    {
        sum += f(N[i]) * pow(b,T--);
    }
    printf("%.5f", sum);
    return 0;
}