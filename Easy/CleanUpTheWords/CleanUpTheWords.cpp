/*
CLEAN UP THE WORDS
CHALLENGE DESCRIPTION:

You have a list of words. Letters of these words are mixed with extra 
symbols, so it is hard to define the beginning and end of each word. 
Write a program that will clean up the words from extra numbers and 
symbols.

INPUT SAMPLE:

The first argument is a path to a file. Each line includes a test case 
with a list of words: letters are both lowercase and uppercase, and are
 mixed with extra symbols.

For example:

(--9Hello----World...--)
Can 0$9 ---you~
13What213are;11you-123+138doing7

OUTPUT SAMPLE:

Print the cleaned up words separated by spaces in lowercase letters.

For example:

hello world
can you
what are you doing

CONSTRAINTS:

Print the words separated by spaces in lowercase letters.
The length of a test case together with extra symbols can be in a range 
from 10 to 100 symbols.
The number of test cases is 40.
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

	while (infile)
	{
		string s;
		if (!getline(infile, s)) break;
		for(int i=0;i<s.size();i++)
		{
            int a=(int)s[i];
            if(a>=97 && a<=122)
            {    
                 cout<<s[i];    
            }
            else if(a>=65 && a<=90)
            {    
                 cout<<(char)(a+32);    
            }
            else
            {
                if(i>0)
                {
                       int b=(int)s[i-1];
                       if((b>=97 && b<=122) || (b>=65 && b<=90))
                          cout<<" ";
                }
            }
        }
        if(s!="")
                 cout<<endl;
	}
	
	return 0;
}
