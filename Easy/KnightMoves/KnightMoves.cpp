/*
KNIGHT MOVES
CHALLENGE DESCRIPTION:

In chess, the knight moves to any of the closest squares that are 
not on the same rank, file, or diagonal. Thus the move is in the 
“L” form: two squares vertically and one square horizontally, or 
two squares horizontally and one square vertically:


Your task is to find all possible positions for the next move of 
the knight on the empty chessboard.

INPUT SAMPLE:

The first argument is a filename that contains positions of the 
knight on the chessboard in the CN form, where:

C is a letter from “a” to “h” and denotes a column.
N is a number from 1 to 8 and denotes a row.
Each position is indicated in a new line.

For example:

g2
a1
d6
e5
b1

OUTPUT SAMPLE:

Print to stdout all possible positions for the next move of the 
knight ordered alphabetically.

For example:

e1 e3 f4 h4
b3 c2
b5 b7 c4 c8 e4 e8 f5 f7
c4 c6 d3 d7 f3 f7 g4 g6
a3 c3 d2

CONSTRAINTS:

The number of test cases is 40.
*/

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int arg, char* args[])
{
	ifstream infile(args[1]);

	while (infile)
	{
		string s;
		string move;
		vector<string> moves;
		if (!getline(infile, s)) break;
		if(s!="")
		{
            int col=s[0]-96;
            int row=s[1]-48;
            if(row+2<=8 && col+1<=8)
            {
                move="";
                move+=(char)(col+1+96);
                move+=(char)(row+2+48);
                moves.push_back(move);
            }
            if(row+1<=8 && col+2<=8)
            {
                move="";
                move+=(char)(col+2+96);
                move+=(char)(row+1+48);
                moves.push_back(move);
            }
            if(row-1>=1 && col+2<=8)
            {
                move="";
                move+=(char)(col+2+96);
                move+=(char)(row-1+48);
                moves.push_back(move);
            }
            if(row-2>=1 && col+1<=8)
            {
                move="";
                move+=(char)(col+1+96);
                move+=(char)(row-2+48);
                moves.push_back(move);
            }
            if(row-2>=1 && col-1>=1)
            {
                move="";
                move+=(char)(col-1+96);
                move+=(char)(row-2+48);
                moves.push_back(move);
            }
            if(row-1>=1 && col-2>=1)
            {
                move="";
                move+=(char)(col-2+96);
                move+=(char)(row-1+48);
                moves.push_back(move);
            }
            if(row+1<=8 && col-2>=1)
            {
                move="";
                move+=(char)(col-2+96);
                move+=(char)(row+1+48);
                moves.push_back(move);
            }
            if(row+2<=8 && col-1>=1)
            {
                move="";
                move+=(char)(col-1+96);
                move+=(char)(row+2+48);
                moves.push_back(move);
            }
            sort(moves.begin(),moves.end());
            for(int i=0;i<moves.size();i++)
               cout<<moves[i]<<" ";
            cout<<endl;
        }
      }
	
	return 0;
}
