/*
REPEATED SUBSTRING
CHALLENGE DESCRIPTION:


You are to find the longest repeated substring in a given text. 
Repeated substrings may not overlap. If more than one substring 
is repeated with the same length, print the first one you find.
(starting from the beginning of the text). 
NOTE: The substrings can't be all spaces.

INPUT SAMPLE:

Your program should accept as its first argument a path to a filename.
 The input file contains several lines. Each line is one test case. 
 Each line contains a test string. E.g.

banana
am so uniqe
OUTPUT SAMPLE:

For each set of input produce a single line of output which is the 
longest repeated substring. If there is none, print out the string NONE. E.g.

an
NONE
*/

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

bool isAllSpaces(char *str,int size)
{
     bool ret=true;
     for(int i=0;i<size;i++)
     {
         if(*(str+i)!=' ')
            ret=false;    
     }
     return ret;
}

int main(int arg, char* args[])
{
	ifstream infile(args[1]);

	while (infile)
	{
		string s;
		if (!getline(infile, s)) break;
		int l=s.size();
		int i=l/2;
		bool rep=false;
		string resStr="NONE";
		
        for(int k=1;k<=l/2;k++)
        {
            for(int j=0;j<l-i-(i-1);j++)
            {
                    
                 string tempStr;   
                 tempStr=s.substr(j,i);
                 for(int p=0;p<=l-j-2*i;p++)
                 {
                     if(!isAllSpaces(&tempStr[0],tempStr.size()) && tempStr==s.substr(j+i+p,i))
                     {
                          rep=true;
                          resStr=tempStr;
                          break;
                     }
                 }
                 if(rep)
                   break;
            }
            if(rep)
               break;    
            i--;
            
        }
        cout<<resStr<<endl;;
	}
	
	return 0;
}
