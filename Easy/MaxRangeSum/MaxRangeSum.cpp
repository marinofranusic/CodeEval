/*
MAX RANGE SUM
CHALLENGE DESCRIPTION:

Bob is developing a new strategy to get rich in the stock market. 
He wishes to invest his portfolio for 1 or more days, then sell it
 at the right time to maximize his earnings. Bob has painstakingly 
 tracked how much his portfolio would have gained or lost for each 
 of the last N days. Now he has hired you to figure out what would 
 have been the largest total gain his portfolio could have achieved.

For example:

Bob kept track of the last 10 days in the stock market. On each day, 
the gains/losses are as follows:

7 -3 -10 4 2 8 -2 4 -5 -2
If Bob entered the stock market on day 4 and exited on day 8 
(5 days in total), his gains would have been

16 (4 + 2 + 8 + -2 + 4)

INPUT SAMPLE:

The input contains N, the number of days (0 < N < 10000), followed by 
N (separated by symbol ";") integers D (-10000 < D < 10000) indicating
 the gain or loss on that day.

For example:

5;7 -3 -10 4 2 8 -2 4 -5 -2
6;-4 3 -10 5 3 -7 -3 7 -6 3
3;-7 0 -45 34 -24 7

OUTPUT SAMPLE:

Print out the maximum possible gain over the period. If no gain is 
possible, print 0.

For example:

16
0
17

CONSTRAINTS:

Gain or loss on that day is (-100 < D < 100).
Number of days (0 < N < 100).
Number of test cases is 20.
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
			if (!getline(ss, s, ';')) break;
			record.push_back(s);
		}
		data.push_back(record);
	}
	
	for (int i=0;i<data.size();i++)
	{
        if(!data[i].empty())
        {
            int days=atoi(data[i][0].c_str());                
            istringstream ss(data[i][1]);
            vector <int> gainLoss;
            int sum=0;
            int maxSum=0;
            while (ss){
                string s;
                if (!getline(ss, s, ' ')) break;
			    gainLoss.push_back(atoi(s.c_str()));
            }
            for(int j=0;j<=gainLoss.size()-days;j++)
            {
               sum=0;
               for(int k=0;k<days;k++)
               {
                   sum+=gainLoss[j+k];
               }
               if(sum>maxSum)
                    maxSum=sum;
            }
            cout<<maxSum<<endl;
        }
  	}
	return 0;
}
