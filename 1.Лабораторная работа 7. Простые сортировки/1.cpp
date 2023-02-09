#include <iostream>

using namespace std;

void ins_sort(int a[], int N)
{
    for (int i = 0; i < N; i++)
    {
        int temp = i - 1;
        int value = a[i];
        while (a[temp] > value && temp >= 0)
        {
            a[temp + 1] = a[temp];
            temp--;
        }
        a[temp + 1] = value;
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
    ins_sort(a, N);
    delete[] a;
    return 0;
}
