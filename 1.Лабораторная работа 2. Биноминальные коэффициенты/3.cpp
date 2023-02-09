#include <iostream>

using namespace std;

long long C(long N, long K)
{
	if (K == 0 || N == K) return 1;
	return C(N - 1, K - 1) + C(N - 1, K);
}

int main()
{
	int N;
	cin >> N;
	for (long long i = 0; i < N+1; i++)
	{
		cout << "1";
		for (long long j = 1; j <= i; j++)
		{
			cout << " " << C(i, j);
		}
		cout << endl;
	}
	return 0;
}