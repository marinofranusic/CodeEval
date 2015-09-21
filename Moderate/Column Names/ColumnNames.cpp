/*
COLUMN NAMES
SPONSORING COMPANY:

  

CHALLENGE DESCRIPTION:

Microsoft Excel uses a special convention to name its column 
headers. The first 26 columns use the letters 'A' to 'Z'. Then,
 Excel names its column headers using two letters, so that the
 27th and 28th column are 'AA' and 'AB'. After 'ZZ', Excel uses
 three letters.

Write a function that takes as input the number of the column,
 and returns its header. The input will not ask for a column 
 that would be greater than 'ZZZ'.

INPUT SAMPLE:

The first argument is a path to a file. Each line of the input 
file contains one test case represented by one integer.

1
2
52
3702

OUTPUT SAMPLE:

For each test case your program must print one line containing 
the Excel column heading corresponding to the integer in the input.

1
2
AZ
ELJ
CONSTRAINTS:

The number of test cases is 40.
The input will not ask for a column that would be greater than 'ZZZ'.

*/

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

string ExcelColumn(int num)
{
    string ret="";
    int result=num;
    int temp=0;
    int tempDiv=0;
    while(result!=0)
    {
        temp=result/26;
        tempDiv=result%26;
        if(tempDiv==0)
        {
            tempDiv=26;
            temp--;
        }
        char c=64+tempDiv;
        ret.insert(0,1,c);
        result=temp;
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
	    cout<<ExcelColumn(atoi(s.c_str()))<<endl;	
	}
	
	return 0;
}
