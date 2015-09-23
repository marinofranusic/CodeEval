/*
STEPWISE WORD
CHALLENGE DESCRIPTION:

Print the longest word in a stepwise manner.

INPUT SAMPLE:

The first argument is a path to a file. Each line contains a test case
 with a list of words that have different or the same length.

For example:

cat dog hello
stop football play
music is my life

OUTPUT SAMPLE:

Find the longest word in each line and print it in one line in a stepwise
 manner. Separate each new step with a space. If there are several words 
 of the same length and they are the longest, then print the first word 
 from the list.

h *e **l ***l ****o
f *o **o ***t ****b *****a ******l *******l
m *u **s ***i ****c

CONSTRAINTS:

The word length is from 1 to 10 characters.
The number of words in a line is from 5 to 15.
If there are several words of the same length and they are the longest, 
then print the first word from the list.
The number of test cases is 40.
*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Code_Eval_stepwise
{
    class Program
    {
        static void Main(string[] args)
        {
            TextReader rawText;
            var path = args[0];
            rawText = File.OpenText(path);
            int longestPos = 0;
            int longestLen = 0;
            for (string line; (line = rawText.ReadLine()) != null;)
            {
                longestPos = 0;
                longestLen = 0;
                string[] wordsInLine = line.Split(' ');
                for(int i=0;i<wordsInLine.Length;i++)
                {
                    if (wordsInLine[i].Length > longestLen)
                    {
                        longestLen = wordsInLine[i].Length;
                        longestPos = i;
                    }
                }
                for (int i = 0; i < wordsInLine[longestPos].Length; i++)
                {
                    for (int j = 0; j < i; j++)
                    {
                        Console.Write("*");
                    }
                    Console.Write(wordsInLine[longestPos][i]);
                    if (i != longestLen - 1)
                        Console.Write(" ");
                    
                }
                if(line.Length>0)
                    Console.WriteLine();
            }

            Console.ReadLine();
        }
    }
}
