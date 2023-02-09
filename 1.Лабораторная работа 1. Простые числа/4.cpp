#include <iostream>

using namespace std;

int main()
{
	int N, Q, X;
	cin >> N >> Q;
	for (int i = 0; i < Q; i++)
	{
		cin >> X;
		if ((X % 2 == 0) && (X != 2) || (X == 1)) N++;
		else
		{
			N = 0;
			for (int j = 3; j * j <= X; j += 2)
			{
				if (X % j == 0)
				{
					N++;
					break;
				}
			}
		}
		N > 0 ? cout << X << " not" << endl : cout << X << " prime" << endl;
	}
	return 0;
}