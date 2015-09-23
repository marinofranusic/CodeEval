/*
BIG DIGITS
CHALLENGE DESCRIPTION:

In this challenge you're presented with a situation in which you need to 
output big symbols on devices which only support ASCII characters and single,
 fixed-width fonts. To do this you're going to use pseudo-graphics to ‘draw’ 
 these big symbols.

Here is an example of the font with digits from 0 to 9:


-**----*--***--***---*---****--**--****--**---**--
*--*--**-----*----*-*--*-*----*-------*-*--*-*--*-
*--*---*---**---**--****-***--***----*---**---***-
*--*---*--*-------*----*----*-*--*--*---*--*----*-
-**---***-****-***-----*-***---**---*----**---**--
--------------------------------------------------
Each pixel is marked either with asterisk ‘*’ or with minus ‘-’. Size of a 
digit is 5×6 pixels.

Your task is to write a program, which outputs the numbers given to you with
 the font as in the example.

INPUT SAMPLE:

The first argument is a file that contains the lines with digits sequences 
you need to magnify. E.g.:


3.1415926
1.41421356
01-01-1970
2.7182818284
4 8 15 16 23 42
OUTPUT SAMPLE:

Print to stdout the magnified digits:


***----*---*-----*--****--**--***---**--
---*--**--*--*--**--*----*--*----*-*----
-**----*--****---*--***---***--**--***--
---*---*-----*---*-----*----*-*----*--*-
***---***----*--***-***---**--****--**--
----------------------------------------
--*---*-----*---*---***----*--***--****--**--
-**--*--*--**--*--*----*--**-----*-*----*----
--*--****---*--****--**----*---**--***--***--
--*-----*---*-----*-*------*-----*----*-*--*-
-***----*--***----*-****--***-***--***---**--
---------------------------------------------
-**----*---**----*----*---**--****--**--
*--*--**--*--*--**---**--*--*----*-*--*-
*--*---*--*--*---*----*---***---*--*--*-
*--*---*--*--*---*----*-----*--*---*--*-
-**---***--**---***--***--**---*----**--
----------------------------------------
***--****---*---**--***---**----*---**--***---**---*---
---*----*--**--*--*----*-*--*--**--*--*----*-*--*-*--*-
-**----*----*---**---**---**----*---**---**---**--****-
*-----*-----*--*--*-*----*--*---*--*--*-*----*--*----*-
****--*----***--**--****--**---***--**--****--**-----*-
-------------------------------------------------------
-*----**----*--****---*---**--***--***---*---***--
*--*-*--*--**--*-----**--*-------*----*-*--*----*-
****--**----*--***----*--***---**---**--****--**--
---*-*--*---*-----*---*--*--*-*-------*----*-*----
---*--**---***-***---***--**--****-***-----*-****-
--------------------------------------------------
CONSTRAINTS:

Input lines are up to 16 symbols long.
Input can contain some other symbols, which should be ignored (i.e. points, 
hyphens, spaces); only numbers must be printed out.
*/
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
using namespace std;
void printDigit(int num,int line)
{
     if(line==0)
     {
         if(num==0 || num==6 || num==8 || num==9)
            cout<<"-**--";
         if(num==1)
            cout<<"--*--";
         if(num==2 || num==3)
            cout<<"***--";
         if(num==4)
            cout<<"-*---";
         if(num==5 || num==7)
            cout<<"****-";   
     }
     if(line==1)
     {
         if(num==0 || num==4 || num==8 || num==9)
            cout<<"*--*-";
         if(num==1)
            cout<<"-**--";
         if(num==2 || num==3 || num==7)
            cout<<"---*-";
         if(num==5 || num==6)
            cout<<"*----";
            
     }
     if(line==2)
     {
         if(num==0)
            cout<<"*--*-";
         if(num==1 || num==7)
            cout<<"--*--";
         if(num==2 || num==3 || num==8)
            cout<<"-**--";
         if(num==4 )
            cout<<"****-";
         if(num==5 || num==6)
            cout<<"***--";
         if(num==9)
            cout<<"-***-";   
     }
     if(line==3)
     {
         if(num==0 || num==6 || num==8)
            cout<<"*--*-";
         if(num==1)
            cout<<"--*--";
         if(num==2)
            cout<<"*----";
         if(num==3 || num==4 || num==5 || num==9)
            cout<<"---*-";
         if(num==7)
            cout<<"-*---";
     }
     if(line==4)
     {
         if(num==0 || num==6 || num==8 || num==9)
            cout<<"-**--";
         if(num==1)
            cout<<"-***-";
         if(num==2)
            cout<<"****-";
         if(num==3 || num==5)
            cout<<"***--";
         if(num==4)
            cout<<"---*-";
         if(num==7)
            cout<<"-*---";
     }
     if(line==5)
     {
         cout<<"-----";
     }
}
int main(int arg, char* args[])
{
	vector <vector <string> > data;
	ifstream infile(args[1]);

	while (infile)
	{
		string s;
		if (!getline(infile, s)) break;
		if(s!="")
		{
            string cleanStr="";
            for(int i=0;i<s.size();i++)
            {
                 int a=s[i];
                 if(a>=48 && a<=57)
                     cleanStr+=s[i];
            }
            for(int i=0;i<6;i++)
            {
                for(int j=0;j<cleanStr.size();j++)
                {
                        printDigit(cleanStr[j]-48,i);
                }
                cout<<endl;
            }
        }
	}
	return 0;
}
