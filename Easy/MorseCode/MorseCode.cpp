/*
MORSE CODE
CHALLENGE DESCRIPTION:


You have received a text encoded with Morse code and want to decode it.

INPUT SAMPLE:

Your program should accept as its first argument a path to a filename. 
Input example is the following:

.- ...- ..--- .-- .... .. . -.-. -..-  ....- .....
-... .... ...--
Each letter is separated by space char, each word is separated by 2 space chars.

OUTPUT SAMPLE:

Print out decoded words. E.g.

AV2WHIECX 45
BH3
You program has to support letters and digits only.
*/
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

char MorseLetter(string *str)
{
	char retChar=' ';
	if (*str == ".-")
	{
		retChar = 'A';
	}
	else if (*str == "-...")
	{
		retChar = 'B';
	}
	else if (*str == "-.-.")
	{
		retChar = 'C';
	}
	else if (*str == "-..")
	{
		retChar = 'D';
	}
	else if (*str == ".")
	{
		retChar = 'E';
	}
	else if (*str == "..-.")
	{
		retChar = 'F';
	}
	else if (*str == "--.")
	{
		retChar = 'G';
	}
	else if (*str == "....")
	{
		retChar = 'H';
	}
	else if (*str == "..")
	{
		retChar = 'I';
	}
	else if (*str == ".---")
	{
		retChar = 'J';
	}
	else if (*str == "-.-")
	{
		retChar = 'K';
	}
	else if (*str == ".-..")
	{
		retChar = 'L';
	}
	else if (*str == "--")
	{
		retChar = 'M';
	}
	else if (*str == "-.")
	{
		retChar = 'N';
	}
	else if (*str == "---")
	{
		retChar = 'O';
	}
	else if (*str == ".--.")
	{
		retChar = 'P';
	}
	else if (*str == "--.-")
	{
		retChar = 'Q';
	}
	else if (*str == ".-.")
	{
		retChar = 'R';
	}
	else if (*str == "...")
	{
		retChar = 'S';
	}
	else if (*str == "-")
	{
		retChar = 'T';
	}
	else if (*str == "..-")
	{
		retChar = 'U';
	}
	else if (*str == "...-")
	{
		retChar = 'V';
	}
	else if (*str == ".--")
	{
		retChar = 'W';
	}
	else if (*str == "-..-")
	{
		retChar = 'X';
	}
	else if (*str == "-.--")
	{
		retChar = 'Y';
	}
	else if (*str == "--..")
	{
		retChar = 'Z';
	}
	else if (*str == ".----")
	{
		retChar = '1';
	}
	else if (*str == "..---")
	{
		retChar = '2';
	}
	else if (*str == "...--")
	{
		retChar = '3';
	}
	else if (*str == "....-")
	{
		retChar = '4';
	}
	else if (*str == ".....")
	{
		retChar = '5';
	}
	else if (*str == "-....")
	{
		retChar = '6';
	}
	else if (*str == "--...")
	{
		retChar = '7';
	}
	else if (*str == "---..")
	{
		retChar = '8';
	}
	else if (*str == "----.")
	{
		retChar = '9';
	}
	else if (*str == "-----")
	{
		retChar = '0';
	}
	return retChar;
}

int main(int arg, char* args[])
{
	ifstream infile(args[1]);
	while (infile)
	{
		string s;
		if (!getline(infile, s)) break;
		int beginPos = 0;
		int lastPos = 0;
		while(lastPos<=s.size() && beginPos<s.size())
		{
			if (s[lastPos] == ' ' || lastPos==s.size())
			{
				string tmpStr=s.substr(beginPos, lastPos - beginPos);
				cout << MorseLetter(&tmpStr);
				beginPos = lastPos + 1;
				lastPos++;
			}
			else
			{
				lastPos++;
			}
		}
		cout << endl;
	}
	return 0;
}

