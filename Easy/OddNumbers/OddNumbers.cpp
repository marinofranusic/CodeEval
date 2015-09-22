/*
ODD NUMBERS
CHALLENGE DESCRIPTION:


Print the odd numbers from 1 to 99.

INPUT SAMPLE:

There is no input for this program.

OUTPUT SAMPLE:

Print the odd numbers from 1 to 99, one number per line. 
*/

#include <iostream>
using namespace std;
int main(int arg, char* args[])
{
	for(int i=0;i<=99;i++)
	{
        if(i%2!=0)
            cout<<i<<endl;
    }
	return 0;
}
