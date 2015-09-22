/*
FILE SIZE
CHALLENGE DESCRIPTION:


Print the size of a file in bytes.

INPUT:

The first argument to your program has the path to the file you need to check the size of.

OUTPUT SAMPLE:

Print the size of the file in bytes. E.g.

55
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
    infile.seekg(0,infile.end);
    cout<<infile.tellg()<<endl;
	return 0;
}
