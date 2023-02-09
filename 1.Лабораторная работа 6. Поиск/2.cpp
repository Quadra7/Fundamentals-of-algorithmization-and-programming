#include <iostream>
#include <string>

using namespace std;

int F(string P, string T, int* num)
{
    int d[256];
    int j, k, count = 0;
    int N = P.length();
    int M = T.length();
    for (int i = 0; i < 256; i++)
    {
        d[i] = M;
    }
    for (int i = 0; i < M - 1; i++)
    {
        d[(unsigned char)T[i]] = M - i - 1;
    }
    int i = M - 1;
    do {
        j = M - 1;
        k = i;
        while ((j >= 0) && (T[j] == P[k])) 
        {
            k--;
            j--;
        }
        if (j < 0) 
        {
            num[count] = k + 1;
            count++;
        }
        i += d[(unsigned)P[i]];
    } while (i < N);
  return count;
}

int main() 
{
    int num[100000];
    string T, P;
    cin >> T;
    cin >> P;
    int count = F(T, P, num);
    cout << count << endl;
    for (int i = 0; i < count; i++) 
    {
        cout << num[i] << endl;
    }
    return 0;
}