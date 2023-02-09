#include <iostream>

using namespace std;

void shake_sort(int a[], int N)
{
    int l = 0;
    int r = N - 1;
    int check = 1;
    while ((l < r) && check)
    {
        check = 0;
        for (int i = l; i < r; i++)
        {
            if (a[i] > a[i + 1])
            {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                check = 1;
            }
        }
        r--;
        for (int i = r; i > l; i--)
        {
            if (a[i - 1] > a[i])
            {
                int temp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = temp;
                check = 1;
            }
        }
        l++;
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
  shake_sort(a, N);
  return 0;
}