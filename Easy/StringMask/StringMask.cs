/*
STRING MASK
CHALLENGE DESCRIPTION:

You’ve got a binary code which has to be buried among words in 
order to unconsciously pass the cipher. 
Create a program that would cover the word with a binary mask. 
If, while covering, a letter finds itself as 1, you have to change
 its register to the upper one, if it’s 0, leave it as it is. 
 Words are always in lower case and in the same row with the binary mask.

INPUT SAMPLE:

The first argument is a path to a file. Each row contains a test case
 with a word and a binary code separated with space, inside of it. 
 The length of each word is equal to the length of the binary code.

For example:

hello 11001
world 10000
cba 111

OUTPUT SAMPLE:

Print the encrypted words without binary code.

For example:

HEllO
World
CBA

CONSTRAINTS:

Words are from 1 to 20 letters long.
The number of test cases is 40.
*/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Code_Eval_stringMask
{
    class Program
    {
        static void Main(string[] args)
        {
            TextReader rawText;
            var path = args[0];
            rawText = File.OpenText(path);
            for (string line; (line = rawText.ReadLine()) != null;)
            {
                if (line.Length > 0)
                {
                    string[] wordsInLine = line.Split(' ');
                    for (int i = 0; i < wordsInLine[0].Length; i++)
                    {
                        if(wordsInLine[1][i]=='1')
                        {
                            Console.Write(char.ToUpper(wordsInLine[0][i]));
                        }
                        else
                        {
                            Console.Write(wordsInLine[0][i]);
                        }
                    }
                    Console.WriteLine();
                }
            }

            Console.ReadLine();
        }
    }
}
