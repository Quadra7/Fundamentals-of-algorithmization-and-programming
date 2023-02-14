#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    char text[8];
    Node* next;
    Node* prev;
public:
    Node(int data, const char* str)
    {
        this->data = data;
        strcpy(this->text, str);
        this->next = NULL;
        this->prev = NULL;
    }
};

class OneLinkedList
{
public:
    Node* head;
    Node* tail;
public:
    OneLinkedList()
    {
        this->head = this->tail = NULL;
    }
    void push_back(int data, const char* str)
    {
        Node* node = new Node(data, str);
        if (head == NULL)
        {
            head = node;
        }
        if (tail != NULL)
        {
            tail->next = node;
            node->prev = tail;
        }
        tail = node;
    }
};

int main()
{
    FILE* in;
    int key, n;
    char str[8];
    OneLinkedList* lst = new OneLinkedList[1000001];
    in = fopen("input.txt", "rt");
    fscanf(in, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        fscanf(in, "%d %s", &key, str);
        lst[key].push_back(key, str);
    }
    for (int i = 0; i < 1000001; i++)
    {
        if (lst[i].head != NULL && lst[i].tail != NULL)
        {
            for (Node* node = lst[i].head; node != NULL; node = node->next)
            {
                cout << node->data << " " << node->text << endl;
            }
        }
    }
    return 0;
}