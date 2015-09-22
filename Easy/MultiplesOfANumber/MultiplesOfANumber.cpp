/*
MULTIPLES OF A NUMBER
CHALLENGE DESCRIPTION:


Given numbers x and n, where n is a power of 2, print out the smallest 
multiple of n which is greater than or equal to x. Do not use division 
or modulo operator.

INPUT SAMPLE:

The first argument will be a path to a filename containing a comma 
separated list of two integers, one list per line. E.g.

13,8
17,16
OUTPUT SAMPLE:

Print to stdout, the smallest multiple of n which is greater than or equal 
to x, one per line. E.g.

16
32
*/

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
int main(int arg, char* args[])
{
	vector <vector <string> > data;
	ifstream infile(args[1]);

	while (infile)
	{
		string s;
		if (!getline(infile, s)) break;
		istringstream ss(s);
		vector <string> record;
		while (ss)
		{
			string s;
			if (!getline(ss, s, ',')) break;
			record.push_back(s);
		}
		data.push_back(record);
	}
	int i = 0;
	int j = 0;
	for (int i_a=0;i_a<data.size();i_a++)
	{
        i = 0;
		int num1 = atoi(data[i_a][0].c_str());
		int num2 = atoi(data[i_a][1].c_str());
		bool finished = false;
		while (!finished)
		{
			i++;
			if (i*num2 > num1)
			{
				finished = true;
			}
		}
		cout << i*num2 << endl;
      
	}
	return 0;
}
