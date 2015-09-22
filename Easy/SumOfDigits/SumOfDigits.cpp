/*SUM OF DIGITS
CHALLENGE DESCRIPTION:


Given a positive integer, find the sum of its constituent digits.

INPUT SAMPLE:

The first argument will be a path to a filename containing positive integers, 
one per line. E.g.

23
496

OUTPUT SAMPLE:

Print to stdout, the sum of the numbers that make up the integer, one per line. E.g.

5
19
*/
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
int main(int arg, char* args[])
{
	vector <string> data;
	ifstream infile(args[1]);
	while (infile)
	{
		string s;
		if (!getline(infile, s)) break;
		data.push_back(s);
		int sum=0;
		for(int i=0;i<s.size();i++)
		{
                sum+=(s[i]-'0');
        }
        cout<<sum<<endl;
	}
	return 0;
}
