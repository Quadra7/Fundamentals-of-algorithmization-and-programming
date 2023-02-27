#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Queue 
{
    int* a;
    int front;
    int rear;
    int count;
    int capacity;
public:
    Queue(int size);
    void enqueue(int data);
    int dequeue();
    int size();
    int empty();
    int full();
};

Queue::Queue(int size)
{
    a = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

void Queue::enqueue(int data)
{
    rear = (rear + 1) % capacity;
    a[rear] = data;
    count++;
}

int Queue::dequeue()
{
    int data = a[front];
    front = (front + 1) % capacity;
    count--;
    return data;
}

int Queue::size()
{
    return count;
}

int Queue::empty()
{
    return (size() == 0);
}

int Queue::full()
{
    return (size() == capacity);
}

int main()
{
    int N, M, R;
    int status, data;
    FILE* in = fopen("input.txt", "rt");
    FILE* out = fopen("output.txt", "wt");
    fscanf(in, "%d %d", &N, &M);
    Queue q(N);
    for (; M > 0;)
    {
        M--;
        status = 1;
        fscanf(in, "%d", &R);
        if (R >= 0)
        {
            M -= R;
            for (int i = 0; i < R; i++)
            {
                fscanf(in, "%d", &data);
                if (q.full() == 1)
                {
                    status = 0;
                }
                else
                {
                    q.enqueue(data);
                }
            }
            if (status == 0)
            {
                fprintf(out, "Memory overflow\n");
            }
        }
        else
        {
            R = ~R + 1;
            int average = 0, count = 0;
            for (int i = 0; i < R; i++)
            {
                if (q.empty() == 1)
                {
                    status = 0;
                    break;
                }
                else
                {
                    average += q.dequeue();
                    count++;
                }
            }
            if (average != 0)
            {
                fprintf(out, "%d\n", average / count);
            }
            if (status == 0)
            {
                fprintf(out, "Empty queue\n");
            }
        }
    }
    fclose(in);
    fclose(out);
    return 0;
}