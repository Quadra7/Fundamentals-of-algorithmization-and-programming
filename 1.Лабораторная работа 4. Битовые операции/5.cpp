#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	int N, M;
	int num;
	int value, position;
	int type;
	cin >> N >> M;
	bitset<32>* bin_num = (bitset<32>*)malloc(N * sizeof(bitset<32>));
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		bin_num[i] = bitset<32>(num);
	}
	for (int i = 0; i < M; i++)
	{
		cin >> value >> position;
		type = position / 32;
		if (type != 0) position -= type * 32;
		bin_num[type].set(31 - position, value);
	}
	for (int i = 0; i < N; i++)
	{
		cout << (int)bin_num[i].to_ulong() << " ";
	}
	free(bin_num);
	return 0;
}