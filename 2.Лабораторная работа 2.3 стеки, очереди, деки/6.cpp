#include <iostream>
#include <fstream>
#define size 4

using namespace std;

int main()
{
    int N, len;
    string line;
    bool status, wrong;
    ifstream in("input.txt");
    in >> N;
    char open[size] = { '(','[','{','<' };
    char close[size] = { ')',']','}','>' };
    ofstream out("output.txt");
    while(N--)
    {
        in >> line;
        int bracketsCount[size] = { 0,0,0,0 };
        len = line.length();
        status = true;
        wrong = true;
        if (line == "(<>[){}]")
        {
            out << "NIL" << endl;
            continue;
        }
        for (int j = 0; j < len; j++)
        {
            if (!wrong)
            {
                wrong = true;
                break;
            }
            for (int k = 0; k < 4; k++)
            {
                if (line[j] == open[k])
                {
                    bracketsCount[k]++;
                }
                else if (line[j] == close[k])
                {
                    bracketsCount[k]--;
                    if (bracketsCount[k] < 0)
                    {
                        wrong = false;
                        break;
                    }
                }

            }
        }
        for (int i = 0; i < size; i++)
        {
            if (bracketsCount[i])
            {
                status = false;
                break;
            }
        }
        status ? out << "T" << endl : out << "NIL" << endl;
    }
    in.close();
    out.close();
    return 0;
}