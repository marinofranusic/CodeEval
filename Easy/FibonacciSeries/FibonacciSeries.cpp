/*
FIBONACCI SERIES
CHALLENGE DESCRIPTION:


The Fibonacci series is defined as: F(0) = 0; 
F(1) = 1; F(n) = F(n–1) + F(n–2) when n>1. 
Given an integer n≥0, print out the F(n).

INPUT SAMPLE:

The first argument will be a path to a filename containing 
integer numbers, one per line. E.g.

5
12
OUTPUT SAMPLE:

Print to stdout, the fibonacci number, F(n). E.g.

5
144
*/

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int fib(int n)
{
    if(n==0)
    {
         return 0;
    }
    else if(n==1)
    {
         return 1;
    }
    else
    {
        return fib(n-1)+fib(n-2);
    }
}

int main(int arg, char* args[])
{
	vector <string> data;
	ifstream infile(args[1]);
	while (infile)
	{
		string s;
		if (!getline(infile, s)) break;
		data.push_back(s);
		int num=atoi(s.c_str());
		cout<<fib(num)<<endl;
	}
	return 0;
}
