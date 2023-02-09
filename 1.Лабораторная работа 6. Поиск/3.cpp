#include <iostream>

using namespace std;

int main()
{
    int N, X;
    cin >> N >> X;
    double* a = new double[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    double min = abs(a[0] - X);
    for (int i = 1; i < N; i++)
    {
        if (min > abs(a[i] - X)) min = abs(a[i] - X);
    }
    for (int i = 0; i < N; i++)
    {
        if (abs(a[i] - X) == min) cout << i << " ";
    }
    delete[] a;
    return 0;
}
