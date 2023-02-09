#include <iostream>

using namespace std;

int main()
{
    int N, X;
    cin >> N >> X;
    int check = 0;
    int* a = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++)
    {
        if (a[i] == X)
        {
            cout << i;
            check = 1;
        }
    }
    if (!check) cout << -1;
    return 0;
}
