/*
COMPARE POINTS
CHALLENGE DESCRIPTION:

Bob's hiking club is lost in the mountains on the way to a scenic 
overlook. Fortunately, Bob has a GPS device, so that he can see 
the coordinates where the group is currently at. The GPS gives the
 current X/Y coordinates as O, P, and the scenic overlook is located 
 at Q, R. Bob now just needs to tell the group which way to go so they
 can get to the overlook in time for s'mores.

INPUT SAMPLE:

The input is a file with each line representing a test case. Each test
 case consists of four integers O, P, Q, R on a line, separated by spaces.

0 0 1 5
12 13 12 13
0 1 0 5

OUTPUT SAMPLE:

For each test case print a line containing one of the following:
 N, NE, E, SE, S, SW, W, NW, here if the coordinates Q, R are 
 (respectively) north, northeast, east, southeast, south, southwest,
 west, northwest, or already at ("here") the coordinates O, P. 
 Note that N, S, E and W mean directly North, South, East or West 
 respectively, i.e. X or Y coordinates of two points are exactly 
 the same. In all other cases your output should be one of the 
 NW, NE, SW, SE or here.

NE
here
N

CONSTRAINTS:

All coordinates -10000 < |O,P,Q,R| < 10000
Number of test cases is 40
*/
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
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
	
	for (int i=0;i<data.size();i++)
	{
        if(!data[i].empty())
        {
            string s="";
            if(data[i][0]==data[i][2] && data[i][1]==data[i][3])
            {
                 s="here";
            }
            else
            {
                if(atoi(data[i][1].c_str())<atoi(data[i][3].c_str()))
                {
                     s="N";
                }
                else if(atoi(data[i][1].c_str())>atoi(data[i][3].c_str()))
                {
                     s="S";
                }
                if(atoi(data[i][0].c_str())<atoi(data[i][2].c_str()))
                {
                     s=s+"E";
                }
                else if(atoi(data[i][0].c_str())>atoi(data[i][2].c_str()))
                {
                     s=s+"W";
                }
            }
            cout<<s<<endl;
        }
  	}
	return 0;
}
