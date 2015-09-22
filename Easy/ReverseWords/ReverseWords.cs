/*
REVERSE WORDS
CHALLENGE DESCRIPTION:


Write a program which reverses the words in an input sentence.

INPUT SAMPLE:

The first argument is a file that contains multiple sentences, 
one per line. Empty lines are also possible.

For example:

Hello World
Hello CodeEval

OUTPUT SAMPLE:

Print to stdout each sentence with the reversed words in it, one per line.
 Empty lines in the input should be ignored. Ensure that there are no 
 trailing empty spaces in each line you print.

For example:


World Hello
CodeEval Hello
*/

using System;
using System.Collections.Generic;
using System.IO;

namespace CodeEval_ReverseWords
{
    class Program
    {
        static void Main(string[] args)
        {
            TextReader rawText;
            var path = args[0];
            rawText = File.OpenText(path);
            List<string> inputWords = new List<string>();

            for (string line; (line = rawText.ReadLine()) != null;)
            {
                string[] wordsInLine = line.Split(' ');
                for (int i = wordsInLine.Length - 1; i >= 0; i--)
                {
                    Console.Write(wordsInLine[i]);
                    if(i!=0)
                    {
                        Console.Write(" ");
                    }
                }
                Console.WriteLine();
            }

            Console.ReadLine();
        }
    }
}
