/*
BIT POSITIONS
CHALLENGE DESCRIPTION:


Given a number n and two integers p1,p2 determine if the bits in position 
p1 and p2 are the same or not. Positions p1 and p2 are 1 based.

INPUT SAMPLE:

The first argument will be a path to a filename containing a comma separated 
list of 3 integers, one list per line. E.g.

86,2,3
125,1,2

OUTPUT SAMPLE:

Print to stdout, 'true'(lowercase) if the bits are the same, else 
	'false'(lowercase). E.g.

true
false
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
        int test_num = atoi(data[i_a][0].c_str());
		int num1 = atoi(data[i_a][1].c_str());
		int num2 = atoi(data[i_a][2].c_str());
		int a=test_num>>(num1-1);
		a&=1;
		int b=test_num>>(num2-1);
		b&=1;
		if(a==b)
        {
            cout<<"true"<<endl;
        }
        else
        { 
            cout<<"false"<<endl;
        }
              
	}
	return 0;
}
