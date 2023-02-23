#include <iostream>
#include <stack>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
    stack<char> s;
    char text[1001];
    cin >> text;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            cout << text[i];
            continue;
        }
        else
        {
            if (text[i] == ')')
            {
                while (s.top() != '(')
                {
                    cout << s.top();
                    s.pop();
                }
                s.pop();
                continue;
            }
            else if (text[i] == '*' || text[i] == '/')
            {
                while ((s.empty() != 1) && (s.top() == '*' || s.top() == '/'))
                {
                    cout << s.top();
                    s.pop();
                }
                s.push(text[i]);
            }
            else if (text[i] == '+' || text[i] == '-')
            {
                while ((s.empty() != 1) && (s.top() == '*' || s.top() == '/' || s.top() == '+' || s.top() == '-'))
                {
                    cout << s.top();
                    s.pop();
                }
                s.push(text[i]);
            }
            else
            {
                s.push(text[i]);
            }
        }
    }
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    return 0;
}