#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	ifstream input;
	string text;
	int count = 0;
	input.open("input.txt");
	while (getline(input, text))
	{
		count++;
	}
	input.close();
	cout << count;
	return 0;
}