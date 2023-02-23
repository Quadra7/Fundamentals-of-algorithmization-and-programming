#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
    int k = 0;
    stack<int> s;
    char symb, num[2001];
    FILE* in = fopen("input.txt", "rt");
    char delims[5] = { '+', '-', '/', '*' };
    while (fscanf(in, "%c", &symb) == 1)
    {
        if (symb == ' ' && k != 0)
        {
            num[k] = '\0';
            s.push(atoi(num));
            k = 0;
        }
        else if (strchr(delims, symb) != NULL)
        {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            switch (symb)
            {
            case '+':
                s.push(a + b);
                break;
            case '-':
                s.push(a - b);
                break;
            case '/':
                s.push(a / b);
                break;
            case '*':
                s.push(a * b);
                break;
            }
        }
        else if (symb != ' ')
        {
            num[k++] = symb;
        }
    }
    cout << s.top();
    return 0;
}