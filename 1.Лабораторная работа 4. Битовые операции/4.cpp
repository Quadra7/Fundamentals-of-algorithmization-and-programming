#include <iostream>
#include <bitset>

using namespace std;

typedef bitset<32> bitword;
bitword* arr = new bitword;

void bitsetZero(int num)
{
	arr = new bitset<32>[num / 16 + 1];
}


int bitsetGet(int idx)
{
	int pos = idx / 32;
	if (pos > 0) idx -= pos * 32;
	return arr[pos].test(idx);
}

void bitsetSet(int idx, int newval)
{
	int pos = idx / 32;
	if (pos != 0) idx -= pos * 32;
	arr[pos].set(idx, newval);
}

int bitsetAny(int left, int right)
{
	int maxright = right / 32;
	int maxleft = left / 32;
	right -= maxright * 32;
	left -= maxleft * 32;

	for (int i = maxleft; i <= maxright; i++)
	{
		int j = 0, n = 32;
		if (i == maxleft) j = left;
		if (i == maxright) n = right;
		while (j < n)
		{
			if (arr[i] == 0) break;
			if (arr[i].test(j)) return 1;
			j++;
		}
	}
	return 0;
}
int main()
{
	int count;
	int t, val1, val2;
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> t >> val1;
		if (t == 0)
		{
			delete[] arr;
			bitsetZero(val1);
		}
		if (t == 1) cout << bitsetGet(val1) << endl;
		if (t == 2)
		{
			int newval;
			cin >> newval;
			bitsetSet(val1, newval);
		}
		if (t == 3)
		{
			cin >> val2;
			bitsetAny(val1, val2) ? cout << "some" << endl : cout << "none" << endl;
		}
	}
	return 0;
}