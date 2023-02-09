#include <iostream>

using namespace std;

double f(int N)
{
	double x = 1;
	for (int i = 1; i <= N; i++)
	{
		x *= i;
	}
	return x;
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N + 1; i++)
	{
		cout << "1";
		for (int j = 1; j <= i; j++)
		{
			cout << " " << (f(i) / (f(j) * f(i - j)));
		}
		cout << endl;
	}
	return 0;
}