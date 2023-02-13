#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
}TList;

TList* addNode(int newNum)
{
    TList* p = (TList*)malloc(sizeof(TList));
    if (p)
    {
        p->data = newNum;
        p->next = NULL;
    }
    return p;
}

TList* addToHead(TList* head, int data)
{
    TList* cur = addNode(data);
    if (cur)
    {
        cur->next = head;
        cur->prev = NULL;
        head->prev = cur;
    }
    return cur;
}

TList* deleteNode(TList* head, int data)
{
    TList* curr = head;
    TList* prev = NULL;
    while (curr) 
    {
        if (curr->data == data)
        {
            if (prev == NULL)
            {
                head = curr;
                head->prev = NULL;
            }
            else if (prev->prev == NULL)
            {
                head = curr;
                head->prev = NULL;
            }
            else 
            {
                (prev->prev)->next = curr;
                curr->prev = prev->prev;
                delete prev;
            }
        }
        prev = curr;
        curr = curr->next;
    }
    return head;
}

void printList(TList* head)
{
    TList* curr = head;
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main()
{
    int temp,num;
    FILE* in, out;
    in = fopen("input.txt", "rt");
    fscanf(in, "%d\n", &num);
    fscanf(in, "%d ", &temp);
    TList* head = (TList*)malloc(sizeof(TList));
    head->data = temp;
    head->next = NULL;
    while (fscanf(in, "%d ", &temp) == 1)
    {
        head = addToHead(head, temp);
    }
    head = deleteNode(head, num);
    printList(head);
    return 0;
}