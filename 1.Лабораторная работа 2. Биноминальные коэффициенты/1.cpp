#include <iostream>
#define X 1000

using namespace std;

int main()
{
	int N;
	cin >> N;
    long long c[X];
	for (int i = 1; i <= N; i++)
	{
		c[i] = 0;
	}
	c[0] = 1;
	cout << "1" << endl;
	for (int i = 1; i <= N; i++) 
    {
    	for (int j = i; j >= 1; j--) 
		{
			c[j] = c[j - 1] + c[j];
			cout << c[j] << " ";
		}
		cout << "1" << endl;
	}
	return 0;
}