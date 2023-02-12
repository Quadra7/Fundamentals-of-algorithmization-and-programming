#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

typedef struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
}TList;

TList* initList(int newNum)
{
    TList* p = (TList*)malloc(sizeof(TList));
    p->data = newNum;
    p->next = NULL;
    p->prev = NULL;
    return(p);
}

int main()
{
    int temp;
    FILE* in;
    in = fopen("input.txt", "rt");
    TList* p, * q, * head = (TList*)malloc(sizeof(TList));
    head->data = 0;
    head->prev = NULL;
    head->next = NULL;
    while (fscanf(in, "%d ", &temp) == 1) 
    {
        p = head;
        while (p->next != NULL && p->next->data < temp)
        {
            p = p->next;
        }
        if (p->next != NULL && p->next->data == temp)
        {
            continue;
        }
        q = (TList*)malloc(sizeof(TList));
        q->data = temp;
        q->next = p->next;
        q->prev = p;
        p->next = q;
    }
    fclose(in);
    p = head->next;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    return 0;
}