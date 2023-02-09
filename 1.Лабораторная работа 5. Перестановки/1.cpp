#include <iostream>
#include <cstdlib>

using namespace std;

void permut_to_invtab(int a[], int b[], int N)
{
    int num = 1;
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = 0; j < N; j++)
        {
            if (a[j] == num)
            {
                for (int k = 0; k < j; k++)
                {
                    if (a[k] > num) sum++;
                }
                b[num - 1] = sum;
            }
        }
        num++;
    }
}

int main()
{
    int N;
    cin >> N;
    int* a = new int[N];
    int* b = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    permut_to_invtab(a, b, N);
    for (int i = 0; i < N; i++)
    {
        cout << b[i] << " ";
    }
    delete[] a;
    delete[] b;
    return 0;
}