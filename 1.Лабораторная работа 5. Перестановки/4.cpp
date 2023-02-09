#include <iostream>
#include <algorithm>

using namespace std;

void out(char a[], int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << a[i] << " ";
    }
}

void next_permut(char a[], int N)
{
    int pos_1, pos_2;
    char value = '0';
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
        cout << a[0];
        return;
    }
    else if (value == '0')
    {
        reverse(a, a + N);
        out(a, N);
        return;
    }
    pos_2 = pos_1;
    for (int i = pos_1; i < N; i++)
    {
        if (a[i] > a[pos_1 - 1] && a[i] < a[pos_2]) pos_2 = i;
    }
    swap(a[pos_2], a[pos_1 - 1]);
    if (N < 3)
    {
        out(a, N);
        return;
    }
    reverse(a + pos_1, a + N);
    out(a, N);
}

int main()
{
    int N;
    cin >> N;
    char* a = new char[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    next_permut(a, N);
    delete[] a;
    return 0;
}
