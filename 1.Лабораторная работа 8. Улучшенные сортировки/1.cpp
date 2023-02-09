#include <iostream>

using namespace std;

void shell_sort(int a[], int N)
{
    int i, j;
    int step = N;
    do 
    {
        step = step / 3 + 1;
        for (i = step; i < N; i++)
        {
            int temp = a[i];
            for (j = i - step; j >= 0 && a[j] > temp; j -= step) 
            {
                a[j + step] = a[j];
                
            }
            a[j + step] = temp;
        }
    } while (step != 1);
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
    shell_sort(a, N);
    delete[] a;
    return 0;
}
