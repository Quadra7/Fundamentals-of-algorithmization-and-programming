#include <iostream>

using namespace std;

int main()
{
    int N, K = 2;
    cin >> N;
    int* a = new int[--N];
    for (int i = 0; i < N; i++)
    {
        a[i] = i + 2;
    }
    for (int i = 0; i < N; i++)
    {
        if (K * K <= N)
        {
            for (int j = i; j < N; j += K)
            {
                if (a[j] != K) a[j] = 0;
            }
        }
        else break;
        K++;
    }
    for (int i = 0; i < N; i++)
    {
        if (a[i] != 0) cout << a[i] << " ";
    }
    delete[] a;
    return 0;
}