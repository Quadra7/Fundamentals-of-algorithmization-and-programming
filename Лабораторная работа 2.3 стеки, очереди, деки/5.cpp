#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Stack 
{
public:
    double data;
    Stack* next;
public:
    Stack(double num);
};
Stack::Stack(double num)
{
    this->data = num;
    this->next = NULL;
}

class StackList
{
public:
    Stack* head;
public:
    StackList();
    double pop();
    void push(double num);
    double top();
    int empty();
};
StackList::StackList()
{
    this->head = NULL;
}
double StackList::pop()
{
    if (head == NULL)
    {
        return 0;
    }
    double temp = head->data;
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return temp;
    }
    Stack* stack = head;
    head = head->next;
    delete stack;
    return temp;
}
void StackList::push(double num)
{
    Stack* stack = new Stack(num);
    stack->next = head;
    head = stack;
}
double StackList::top()
{
    return (head->data);
}
int StackList::empty()
{
    return (head == NULL);
}

int priority(char operation) 
{
    switch (operation) 
    {
    case '*':
    case '/': return 5;
    case '-':
    case '+': return 4;
    case ')': return 2;
    case '(': return 1;
    }
}

double calculate(char operation, double x, double y)
{
    switch (operation) 
    {
    case '+': return x + y;
    case '-': return x - y;
    case '*': return x * y;
    case '/': return x / y;
    }
}

int main() 
{
    StackList numbers;
    StackList operations;
    int i = 0, len;
    int level;
    int temp, unary = 0;
    char* line = (char*)malloc(500001 * sizeof(char));
    char previousChar = '(';
    char nums[10] = { '0','1','2','3','4','5','6','7','8','9' };
    cin.getline(line, 500001);
    len = strlen(line);
    while (i < len) 
    {
        if (line[i] == ' ')
        { 
            i++; 
            continue; 
        }
        if (strchr(nums,line[i]) != NULL)
        {
            sscanf(line + i, "%d", &temp);
            if (unary == 1) 
            {
                temp = ~temp + 1;
                unary = 0;
            }
            numbers.push(temp);
            previousChar = line[i];
            while (strchr(nums, line[i]) != NULL)
            {
                i++;
            }
        }
        else 
        {
            if (line[i] == '-' && previousChar == '(')
            {
                unary = 1;
            }
            else if (line[i] == '(') 
            {
                if (unary == 1) 
                {
                    numbers.push(-1);
                    operations.push('*');
                    unary = 0;
                }
                operations.push(line[i]);
            }
            else if (line[i] == ')') 
            {
                char c = operations.pop();
                while (c != '(')
                {
                    numbers.push(calculate(c, numbers.pop(), numbers.pop()));
                    c = operations.pop();
                }
            }
            else 
            {
                level = priority(line[i]);
                while ((operations.empty() != 1) && (priority(operations.top()) >= level))
                {
                    numbers.push(calculate(operations.pop(), numbers.pop(), numbers.pop()));
                }
                operations.push(line[i]);
            }
            previousChar = line[i];
            i++;
        }
    }
    while (operations.empty() != 1) 
    {
        numbers.push(calculate(operations.pop(), numbers.pop(), numbers.pop()));
    }
    printf("%.20lf", numbers.pop());
    free(line);
    return 0;
}