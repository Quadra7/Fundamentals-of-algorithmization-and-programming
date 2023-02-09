#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#define N 1024

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int count[N];
	for (int i = 0; i < N; i++)
	{
		count[i] = 0;
	}
	string text;
	ifstream input;
	input.open("input.txt");
	while (input >> text)
	{
		count[text.length()]++;
	}
	input.close();
	ofstream output;
	output.open("output.txt");
	for (int i = 0; i < N; i++)
	{
		if (count[i] != 0) output << i << " - " << count[i] << endl;
	}
	output.close();
	return 0;
}