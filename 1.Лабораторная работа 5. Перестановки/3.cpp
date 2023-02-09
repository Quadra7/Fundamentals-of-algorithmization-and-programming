#include <iostream>
#include <algorithm>

using namespace std;

void out(int a[], int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << a[i] << " ";
    }
}

void next_permut(int a[], int N)
{
    int pos_1, pos_2;
    int value = 0;
    for (int i = N-1; i > 0; i--)
    {
        if (a[i] > a[i-1])
        {
            pos_1 = i;
            value = a[i-1];
            break;
        }
    }
    if (N == 1)
    {
        cout << "1";
        return;
    }
    else if (value == 0)
    {
        for (int i = N-1; i >= 0; i--)
        {
            cout << a[i] << " ";
        }
        return;
    }
    int min = N+1;
    for (int i = pos_1; i < N; i++)
    {
        if (a[i] < min && a[i] > a[pos_1-1])
        {
            min = a[i];
            pos_2 = i;
        }
    }
    a[pos_1-1] = a[pos_2];
    a[pos_2] = value;
    if (N < 3)
    {
        out(a, N);
        return;
    }
    reverse(a+pos_1, a+N);
    out(a, N);
}

int main()
{
    int N;
    cin >> N;
    int* a = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    next_permut(a, N);
    delete[] a;
    return 0;
}
