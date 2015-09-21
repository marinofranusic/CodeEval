/*DECRYPTION
SPONSORING COMPANY:

  

CHALLENGE DESCRIPTION:

For this challenge you are given an encrypted
 message and a key. You have to determine the encryption 
 and encoding technique and then print out the corresponding 
 plaintext message. You can assume that the plaintext 
 corresponding to this message, and all messages you must 
 handle, will be comprised of only the characters A-Z and 
 spaces; no digits or punctuation.

INPUT SAMPLE:

There is no input for this program. The encrypted message and key is:

message: "012222 1114142503 0313012513 03141418192102 0113 2419182119021713 06131715070119",
keyed_alphabet: "BHISOECRTMGWYVALUZDNFJKPQX"
OUTPUT SAMPLE:

Print out the plaintext message. (in CAPS)*/

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int main(int arg, char* args[])
{
	ifstream infile(args[1]);
    string key="BHISOECRTMGWYVALUZDNFJKPQX";
    string alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string encMsg="012222 1114142503 0313012513 03141418192102 0113 2419182119021713 06131715070119";
	string decMsg="";
	for(int i=0;i<encMsg.size()-1;i++)
	{
        if(encMsg[i]==' ')
        {
            decMsg+= " ";
            continue;
        }
        string strNum=encMsg.substr(i,2);
        int tempPos=key.find(alphabet[atoi(strNum.c_str())]);
        decMsg+=alphabet[tempPos];
        i++;
    }
    cout<<decMsg<<endl;
	return 0;
}
