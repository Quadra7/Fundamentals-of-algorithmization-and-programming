#include <iostream> 
#include <fstream> 
#include <string> 
#include <locale.h> 
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	ifstream input;
	ofstream output;
	string text;
	int count[256];
	for (int i = 0; i < 256; i++)
	{
		count[i] = 0;
	}
	input.open("input.txt");
	while (getline(input, text))
	{
		for (int i = 0; i < text.length(); i++)
		{
			count[(unsigned char)text[i]] += 1;
		}
	}
	input.close();
	output.open("output.txt");
	for (int i = 32; i < 256; i++)
	{
		if (count[i] != 0)
		{
			output << (char)i << " ";
			for (int j = 0; j < count[i]; j++)
			{
				output << "#";
			}
			output << endl;
		}
	}
	output.close();
	return 0;
}