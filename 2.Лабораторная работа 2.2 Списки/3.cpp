#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;
public:
    Node(int data)
    {
        this->data = data;
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
    void push_back(int data)
    {
        Node* node = new Node(data);
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
    void erase(Node* node)
    {
        if (node == tail)
        {
            tail = node->prev;
            tail->next = NULL;
        }
        else
        {
            Node* left = node->prev;
            Node* right = node->next;
            left->next = node->next;
            right->prev = node->prev;
        }
        delete node;
    }
};

int main()
{
    FILE* in;
    int temp;
    OneLinkedList lst;
    in = fopen("input.txt", "rt");
    while (fscanf(in, "%d ", &temp) == 1)
    {
        lst.push_back(temp);
    }
    fclose(in);
    for (Node* node = (lst.tail)->prev; node != NULL; node = node->prev)
    {
        if (node->data == node->next->data)
        {
            lst.erase(node->next);
        }
    }
    for (Node* node = lst.head; node != NULL; node = node->next)
    {
        cout << node->data << " ";
    }
    return 0;
}