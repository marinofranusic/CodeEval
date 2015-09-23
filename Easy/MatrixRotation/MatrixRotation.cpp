/*
MATRIX ROTATION
CHALLENGE DESCRIPTION:

You are given a 2D N×N matrix. Each element of the matrix is a letter:
 from ‘a’ to ‘z’. Your task is to rotate the matrix 90° clockwise:

a b c        g d a
d e f  =>    h e b
g h i        i f c
INPUT SAMPLE:

The first argument is a file that contains 2D N×N matrices, presented 
in a serialized form (starting from the upper-left element), one matrix 
per line. The elements of a matrix are separated by spaces.

For example:

a b c d
a b c d e f g h i j k l m n o p
a b c d e f g h i

OUTPUT SAMPLE:

Print to stdout matrices rotated 90° clockwise in a serialized form 
(same as in the input sample).

For example:

c a d b
m i e a n j f b o k g c p l h d
g d a h e b i f c

CONSTRAINTS:

The N size of the matrix can be from 1 to 10
The number of test cases is 100
*/
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
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
			if (!getline(ss, s, ' ')) break;
			record.push_back(s);
		}
		data.push_back(record);
	}
	for(int i=0;i<data.size();i++)
	{
        if(!data[i].empty())
        {
            int N=(int)sqrt(data[i].size()+1);
            for(int j=0;j<N;j++)
            {
                for(int k=0;k<N;k++)
                {
                    cout<<data[i][(N*(N-1))+j-k*N]<<" ";    
                }    
            }   
            cout<<endl;             
        }   
    }
	return 0;
}
