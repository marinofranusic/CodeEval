/*

FIRST NON-REPEATED CHARACTER
CHALLENGE DESCRIPTION:


Write a program which finds the first non-repeated character in a string.

INPUT SAMPLE:

The first argument is a path to a file. The file contains strings.

For example:

yellow
tooth

OUTPUT SAMPLE:

Print to stdout the first non-repeated character, one per line.

For example:

y
h
*/

using System;
using System.Collections.Generic;
using System.IO;

namespace Code_Eval_nonRepChar
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
                string word = line.Trim();
                bool ok = true;
                for (int i = 0; i < word.Length; i++)
                {
                    ok = true;
                    for (int j = 0; j < word.Length; j++)
                    {
                        if(word[i]==word[j] && i!=j)
                        {
                            ok = false;
                            break;
                        }
                    }
                    if(ok)
                    {
                        Console.WriteLine(word[i]);
                        break;
                    }
                }
                
            }

            Console.ReadLine();
        }
    }
}
