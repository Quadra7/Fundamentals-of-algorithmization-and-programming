#include <iostream>

using namespace std;

void fast_sort(int* a, int r)
{
    int i = 0;
    int j = r - 1;
    int num = a[(i + j) / 2];
    do
    {
        while (a[i] < num) i++;
        while (a[j] > num) j--;
        if (i <= j) swap(a[i++], a[j--]);
    } while (i <= j);
    if (j > 0) fast_sort(a, j + 1);
    if (r > i) fast_sort(&a[i], r - i);
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
    fast_sort(a, N);
    for (int i = 0; i < N; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}