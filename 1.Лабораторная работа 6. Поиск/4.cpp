#include <iostream>

using namespace std;

int binsearch(int a[], int l, int r, int x)
{
    int temp = r;
    int middle;
    while (l <= r)
    {
        middle = (l + r) / 2;
        if (x == a[middle]) 
        {
            if (a[temp] == a[middle]) return temp;
            while (a[middle + 1] == x)
            {
                middle++;
            }
            return middle;
        }
        else
        {
            a[middle] < x ? l = middle + 1 : r = middle - 1;
        }
    }
    return -1;
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
    int Q;
    cin >> Q;
    int num, idx = 0;;
    for (int i = 0; i < Q; i++)
    {
        cin >> num;
        idx = binsearch(a, 0, N - 1, num + idx);
        cout << idx << endl;
    }
    delete[] a;
    return 0;
}
