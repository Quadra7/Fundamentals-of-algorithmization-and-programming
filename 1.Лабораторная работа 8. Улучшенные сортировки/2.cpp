#include <iostream>

using namespace std;

void function(int a[], int l, int r)
{
	int left = (2 * l) + 1;
	int right = left + 1;
	int index = l;
	if (left < r && a[index] < a[left]) index = left;
	if (right < r && a[index] < a[right]) index = right;
	if (index != l)
	{
		swap(a[l], a[index]);
		function(a, index, r);
	}
}

void heap_sort(int* a, int N)
{
	for (int i = (N / 2) - 1; i >= 0; i--)
	{
		function(a, i, N);
	}
	for (int i = N - 1; i >= 1; i--)
	{
		swap(a[0], a[i]);
		function(a, 0, i);
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
	heap_sort(a, N);
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}