#include <iostream>

using namespace std;

void select_sort(int a[], int N)
{
    int l;
    for (int i = 0; i < N - 1; i++)
    {
        l = i;
        for (int j = i + 1; j < N; j++)
        {
            if (a[j] < a[l]) l = j;
        }
        if (i != l)
        {
            int temp = a[i];
            a[i] = a[l];
            a[l] = temp;
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout << a[i] << " ";
    }
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
    select_sort(a, N);
    delete[] a;
    return 0;
}