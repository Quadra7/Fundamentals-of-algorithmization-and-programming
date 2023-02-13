#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
} TList;

TList* addNode(int newNum)
{
    TList* p = (TList*)malloc(sizeof(TList));
    if (p)
    {
        p->data = newNum;
        p->next = NULL;
        p->prev = NULL;
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

int main()
{
    FILE* in;
    int n, m, temp;
    in = fopen("input.txt", "rt");
    fscanf(in, "%d %d", &n, &m);
    TList* p, * q;
    // 1 список
    fscanf(in, "%d ", &temp);
    TList* head_1 = (TList*)malloc(sizeof(TList));
    head_1->data = temp;
    head_1->next = NULL;
    head_1->prev = NULL;
    for (int i = 1; i < n; i++)
    {
        fscanf(in, "%d ", &temp);
        head_1 = addToHead(head_1, temp);
    }
    // 2 список
    fscanf(in, "%d ", &temp);
    TList* head_2 = (TList*)malloc(sizeof(TList));
    head_2->data = temp;
    head_2->next = NULL;
    head_2->prev = NULL;
    for (int i = 1; i < m; i++)
    {
        fscanf(in, "%d ", &temp);
        head_2 = addToHead(head_2, temp);
    }
    p = head_1;
    q = head_2;
    while ((n != 0) && (m != 0))
    {
        if ((n != 0) && (m != 0))
        {
            if (p->data == q->data)
            {
                n--; m--;
                cout << p->data << " " << q->data << " ";
                p = p->next;
                q = q->next;
            }
            else if (p->data > q->data)
            {
                n--;
                cout << p->data << " ";
                p = p->next;
            }
            else
            {
                m--;
                cout << q->data << " ";
                q = q->next;
            }
        }
        else if ((n != 0) && (m == 0))
        {
            while (n != 0)
            {
                n--;
                cout << p->data << " ";
                p = p->next;
            }
        }
        else
        {
            while (m != 0)
            {
                m--;
                cout << q->data << " ";
                q = q->next;
            }
        }
    }
    if ((n != 0) && (m == 0))
    {
        while (n != 0)
        {
            n--;
            cout << p->data << " ";
            p = p->next;
        }
    }
    else
    {
        while (m != 0)
        {
            m--;
            cout << q->data << " ";
            q = q->next;
        }
    }
    return 0;
}