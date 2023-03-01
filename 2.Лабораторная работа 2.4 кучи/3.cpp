#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>

using namespace std;

int main() 
{
    int N;
    int L = 0, R = 0;
    char command;
    FILE* in = fopen("input.txt", "rt");
    fscanf(in, "%d\n", &N);
    //Without FILE* use;
    //cin >> N;
    deque<int> w;
    deque<int> a(N);
    FILE* out = fopen("output.txt", "wt");
    for (int i = 0; i < N; i++)
    {
        fscanf(in, "%d ", &a[i]);
        //Without FILE* use:
        //cin >> a[i];
    }
    for (int i = 0; i < 2 * N - 1; i++) 
    {
        fscanf(in, "%c", &command);
        //Without FILE* use:
        //cin >> command;
        if (command == 'L') 
        {
            L++;
        }
        else 
        {
            R++;
            while (!w.empty() && w.front() < L) 
            {
                w.pop_front();
            }
            while (!w.empty() && a[w.back()] <= a[R - 1]) 
            {
                w.pop_back();
            }
            w.push_back(R - 1);
        }
        if (!w.empty() && w.front() < L)
        {
            w.pop_front();
        }
        fprintf(out, "%d\n", a[w.front()]);
        //Without FILE* use:
        //cout << a[w.front()] << endl;
    }
    fclose(in);
    fclose(out);
    return 0;
}