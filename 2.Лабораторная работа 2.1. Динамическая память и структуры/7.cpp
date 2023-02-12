#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 
#include <string.h> 

using namespace std;

typedef struct Tokens_s 
{
	int num;
	char** arr;
} Tokens;

void tokensSplit(Tokens* tokens, const char* str, const char* delims)
{
	int length = strlen(str), k = 0, temp = 0;
	if (tokens->arr == NULL)
	{
		for (int i = 0; i < length; i++) 
		{
			if (strchr(delims, str[i]) == NULL)
			{
				temp++;
			}
			else 
			{
				if (temp)
				{
					tokens->num++;
				}
				temp = 0;
			}
		}
		if (temp)
		{
			tokens->num++;
		}
	}
	else 
	{
		for (int i = 0; i < length; i++)
		{
			if (strchr(delims, str[i]) == NULL)
			{
				temp++;
			}
			else 
			{
				if (temp) 
				{
					tokens->arr[k] = (char*)malloc(temp + 2);
					strncpy(tokens->arr[k], str + i - temp, temp);
					tokens->arr[k][temp] = '\0';
					k++;
				}
				temp = 0;
			}
		}
		if (temp) 
		{
			tokens->arr[k] = (char*)malloc(temp + 2);
			strncpy(tokens->arr[k], str + length - temp, temp);
			tokens->arr[k][temp] = '\0';
			k++;
		}
	}
}

void tokensFree(Tokens* tokens) 
{
	if (tokens->arr != NULL) 
	{
		for (int i = 0; i < tokens->num; i++)
		{
			free(tokens->arr[i]);
		}
		free(tokens->arr);
	}
}



int main() 
{
	Tokens tokens = { 0,NULL };
	char* str = (char*)malloc(1000002);
	cin >> str;
	tokensSplit(&tokens, str, ":;.,");
	tokens.arr = (char**)malloc(tokens.num * sizeof(char*));
	tokensSplit(&tokens, str, ":;.,");
	cout << tokens.num << endl;
	for (int i = 0; i < tokens.num; i++)
	{
		cout << tokens.arr[i] << endl;
	}
	tokensFree(&tokens);
}