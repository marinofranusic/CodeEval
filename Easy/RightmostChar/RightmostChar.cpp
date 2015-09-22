/*
RIGHTMOST CHAR
CHALLENGE DESCRIPTION:

You are given a string 'S' and a character 't'. Print out the position of the 
rightmost occurrence of 't' (case matters) in 'S' or -1 if there is none. The 
position to be printed out is zero based.

INPUT SAMPLE:

The first argument will ba a path to a filename, containing a string and a character,
 comma delimited, one per line. Ignore all empty lines in the input file. E.g. 
Hello World,r
Hello CodeEval,E

OUTPUT SAMPLE:

Print out the zero based position of the character 't' in string 'S', one per line. 
Do NOT print out empty lines between your output. 
E.g.

8
10
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
	int i;
	for (int i_a=0;i_a<data.size();i_a++)
	{
        i = -1;
        for(int j=data[i_a][0].size()-1;j>=0;j--)
        {
                if(data[i_a][0][j]==data[i_a][1][0])
                {
                    i=j;
                    break;
                }
        }
        cout<<i<<endl;      
	}
	return 0;
}
