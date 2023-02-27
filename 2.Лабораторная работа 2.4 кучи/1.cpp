#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    int Q, num;
    string text;
    deque <int> arr;
    make_heap(arr.begin(), arr.end(), greater<int>{});
    cin >> Q;
    while (Q--)
    {
        cin >> text;
        if (text == "push")
        {
            cin >> num;
            arr.push_back(num);
            push_heap(arr.begin(), arr.end(), greater<int>{});
        }
        else
        {
            if (arr.size() == 0)
            {
                cout << "Heap is empty" << endl;
            }
            else
            {
                pop_heap(arr.begin(), arr.end(), greater<int>{});
                cout << arr.back() << endl;
                arr.pop_back();
            }
        }
    }
    return 0;
}