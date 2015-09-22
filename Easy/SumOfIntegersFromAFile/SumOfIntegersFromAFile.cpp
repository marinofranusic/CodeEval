/*
SUM OF INTEGERS FROM FILE
CHALLENGE DESCRIPTION:


Print out the sum of integers read from a file.

INPUT SAMPLE:

The first argument to the program will be a path to a filename containing
 a positive integer, one per line. E.g.

5
12

OUTPUT SAMPLE:

Print out the sum of all the integers read from the file. E.g.

17
*/

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main(int arg, char* args[])
{
	ifstream infile(args[1]);
	int sum=0;
    while (infile)
	{
		string s;
		if (!getline(infile, s)) break;
		sum+=atoi(s.c_str());
	}
	cout<<sum<<endl;
	return 0;
}
