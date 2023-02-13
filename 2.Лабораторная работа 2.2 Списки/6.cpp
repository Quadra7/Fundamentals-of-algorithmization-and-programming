#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int n, k;

typedef struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
}TList;

TList* addNode(int newNum)
{
    TList* p = (TList*)malloc(sizeof(TList));
    if (p)
    {
        p->data = newNum;
        p->prev = NULL;
        p->next = NULL;
    }
    return p;
}

void addToTail(TList* head, TList* prev, int data)
{
    TList* cur = addNode(data);
    if (cur)
    {
        if (cur->data == n)
        {
            cur->next = head;
            cur->prev = prev;
            prev->next = cur;
            head->prev = cur;
        }
        else
        {
            cur->next = prev->next;
            cur->prev = prev;
            prev->next = cur;
        }
    }
}

void deleteNode(TList* p)
{
    (p->prev)->next = p->next;
    (p->next)->prev = p->prev;
}

int main()
{
    FILE* in, * out;
    in = fopen("input.txt","rt");
    fscanf(in, "%d %d", &n, &k);
    fclose(in);
    TList* head = (TList*)malloc(sizeof(TList));
    head->data = 1;
    head->next = NULL;
    head->prev = NULL;
    TList* prev;
    for (int i = 1; i < n; i++)
    {
        prev = head;
        while (prev->next)
        {
            prev = prev->next;
        }
        addToTail(head, prev, i + 1);
    }
    prev = head;
    while (n != 1)
    {
        for (int i = 1; i < k; i++)
        {
            prev = prev->next;
        }
        deleteNode(prev);
        prev = prev->next;
        n--;
    }
    cout << prev->data;
    return 0;
}