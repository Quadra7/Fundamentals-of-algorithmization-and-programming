#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Tlist;

Tlist* new_el(int newNum)
{
    Tlist* p = (Tlist*)malloc(sizeof(Tlist));
    if (p)
    {
        p->data = newNum;
        p->next = NULL;
    }
    return p;
}

Tlist* add_first(Tlist* head, int data)
{
    Tlist* cur = new_el(data);
    if (cur)
    {
        cur->next = head;
    }
    return cur;
}

int main()
{
    int temp, count = 0;
    FILE* input, * output;
    input = fopen("input.txt", "rt");
    fscanf(input, "%d ", &temp);
    Tlist* head = (Tlist*)malloc(sizeof(Tlist));
    head->data = temp;
    head->next = NULL;
    while (fscanf(input, "%d ", &temp) == 1)
    {
        head = add_first(head, temp);
    }
    fclose(input);
    Tlist* p = head;
    while (p)
    {
        if ((p->data < 0) && (p->data % 7 == 0))
        {
            count++;
        }
        p = p->next;
    }
    output = fopen("output.txt", "wt");
    fprintf(output, "%d", count);
    fclose(output);
    return 0;
}