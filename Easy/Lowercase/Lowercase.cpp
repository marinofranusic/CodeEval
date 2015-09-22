/*
LOWERCASE
CHALLENGE DESCRIPTION:


Given a string write a program to convert it into lowercase.

INPUT SAMPLE:

The first argument will be a path to a filename containing sentences, one per line.
 You can assume all characters are from the english language. E.g.

HELLO CODEEVAL
This is some text

OUTPUT SAMPLE:

Print to stdout, the lowercase version of the sentence, each on a new line. E.g.

hello codeeval
this is some text
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
	}
	for (int i_a=0;i_a<data.size();i_a++)
	{
        for(int i=0;i<data[i_a].size();i++)
        {       
                char a=data[i_a][i];
                if(int(a)>=65 && int(a)<=90)
                {
                      a+=32;
                }
                cout<<a;   
        }
        cout<<endl;
	}
	return 0;
}
