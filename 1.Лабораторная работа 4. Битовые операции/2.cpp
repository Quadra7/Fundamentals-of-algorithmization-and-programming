#include <iostream>
#include <bitset>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;
    bitset<32> bin_num = bitset<32>(N);
    cout << bin_num << endl;
    string line = bin_num.to_string();
    reverse(line.begin(),line.end());
    bitset<32> bin_num_1 = bitset<32>(line);
    cout << (int)bin_num_1.to_ulong() << endl;
    cout << bin_num_1 << endl;
    return 0;
}