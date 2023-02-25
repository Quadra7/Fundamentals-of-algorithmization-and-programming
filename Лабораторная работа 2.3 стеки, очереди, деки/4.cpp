#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Queue 
{
public:
    int* arr;
    int front;
    int rear;
    int capacity;
    int count;
public:
    Queue(int value);
    void enqueueFront(int value);
    void enqueueBack(int value);
    int dequeueFront();
    int dequeueBack();
    int empty();
    int full();
};
Queue::Queue(int value)
{
    arr = new int[value];
    capacity = value;
    front = 0;
    rear = -1;
    count = 0;
}
void Queue::enqueueFront(int value)
{
    front--;
    if (front < 0)
    {
        front = capacity - 1;
    }
    arr[front] = value;
    count++;
}
void Queue::enqueueBack(int value)
{
    rear = (rear + 1) % capacity;
    arr[rear] = value;
    count++;
}
int Queue::dequeueFront()
{
    if (empty() == 1)
    {
        return 0;
    }
    int value = arr[front];
    front = (front + 1) % capacity;
    count--;
    return value;
}
int Queue::dequeueBack()
{
    if (empty() == 1)
    {
        return 0;
    }
    int value = arr[rear];
    rear--;
    if (rear < 0)
    {
        rear = capacity - 1;
    }
    count--;
    return value;
}
int Queue::empty()
{
    return count == 0;
}

int Queue::full()
{
    return count == capacity;
}

int ConvertToInt(char symb) 
{
    switch (symb)
    {
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    case 'B': return 11;
    case 'C': return 12;
    case 'D': return 13;
    case 'E': return 14;
    }
}

int main()
{
    int N, M;
    FILE* in = fopen("input.txt", "rt");
    fscanf(in, "%d %d\n", &N, &M);
    Queue l(N + N + 1);
    Queue r(N + N + 1);
    for (int i = 1; i < N + 1; i++) 
    {
        l.enqueueBack(i);
        r.enqueueBack(~i + 1);
    }
    char symb, nothing[4] = { '0','5','A','F' };
    // TR == 1 ? take right : take left;
    // TD == 1 ? take down : take up;
    // PR == 1 ? put right : put left;
    // PD == 1 ? put down : put up;
    int command, TR, TD, PR, PD, temp;
    for (int i = 0; i < M; i++) 
    {
        symb = fgetc(in);
        if (strchr(nothing, symb) != NULL)
        {
            continue;
        }
        command = ConvertToInt(symb);
        PD = (command & 1) ? 1 : 0;
        command >>= 1;
        PR = (command & 1) ? 1 : 0;
        command >>= 1;
        TD = (command & 1) ? 1 : 0;
        command >>= 1;
        TR = (command & 1) ? 1 : 0;
        temp = TR ? (TD ? r.dequeueBack() : r.dequeueFront()) : (TD ? l.dequeueBack() : l.dequeueFront());
        if (temp == 0)
        {
            continue;
        }
        PR ? (PD ? r.enqueueBack(temp) : r.enqueueFront(temp)) : (PD ? l.enqueueBack(temp) : l.enqueueFront(temp));
    }
    fclose(in);
    FILE* out = fopen("output.txt", "wt");
    temp = l.front;
    fprintf(out, "%d  ", l.count);
    for (int i = 0; i < l.count; i++) 
    {
        fprintf(out, "%d ", l.arr[temp]);
        temp = (temp + 1)% l.capacity;
    }
    fprintf(out,"\n");
    temp = r.front;
    fprintf(out, "%d  ", r.count);
    for (int i = 0; i < r.count; i++)
    {
        fprintf(out, "%d ", r.arr[temp]);
        temp = (temp + 1) % r.capacity;
    }
    fprintf(out,"\n");
    fclose(out);
    return 0;
}