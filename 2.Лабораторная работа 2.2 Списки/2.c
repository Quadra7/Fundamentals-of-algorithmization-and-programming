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

void add_after(Tlist* prev, int data)
{
    Tlist* cur = new_el(data);
    if (cur)
    {
        cur->next = prev->next;
        prev->next = cur;
    }
}

int main()
{
    int temp, average = 0, count = 0;
    FILE* input, *output;
    input = fopen("input.txt", "rt");
    fscanf(input, "%d ", &temp);
    Tlist* prev, *head = (Tlist*)malloc(sizeof(Tlist));
    head->data = temp;
    head->next = NULL;
    while (fscanf(input, "%d ", &temp) == 1)
    {
        prev = head;
        while (prev->next)
        {
            prev = prev->next;
        }
        add_after(prev, temp);
    }
    fclose(input);
    prev = head;
    while (prev)
    {
        //printf("%d ", prev->data);
        count++;
        average += prev->data;
        prev = prev->next;
    }
    output = fopen("output.txt", "wt");
    fprintf(output, "%d", average / count);
    fclose(output);
    return 0;
}