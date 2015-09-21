/*
FIZZ BUZZ
CHALLENGE DESCRIPTION:

Players generally sit in a circle. The first player says 
the number “1”, and each player says next number in turn. 
However, any number divisible by X (for example, three) is
 replaced by the word fizz, and any divisible by Y 
 (for example, five) by the word buzz. Numbers divisible 
 by both become fizz buzz. A player who hesitates, or makes
 a mistake is eliminated from the game.

Write a program that prints out the final series of numbers 
where those divisible by X, Y and both are replaced by “F” 
for fizz, “B” for buzz and “FB” for fizz buzz.

INPUT SAMPLE:

Your program should accept a file as its first argument. 
The file contains multiple separated lines; each line 
contains 3 numbers that are space delimited. The first number
 is the first divider (X), the second number is the second 
 divider (Y), and the third number is how far you should count 
 (N). You may assume that the input file is formatted 
 correctly and the numbers are valid positive integers.

For example:

3 5 10
2 7 15

OUTPUT SAMPLE:

Print out the series 1 through N replacing numbers divisible by X with “F”, numbers divisible by Y with “B” and numbers divisible by both with “FB”. Since the input file contains multiple sets of values, your output should print out one line per set. Ensure that there are no trailing empty spaces in each line you print.

1 2 F 4 B F 7 8 F B
1 F 3 F 5 F B F 9 F 11 F 13 FB 15

CONSTRAINTS:

The number of test cases ≤ 20
"X" is in range [1, 20]
"Y" is in range [1, 20]
"N" is in range [21, 100]
*/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeEval_FizzBuzz
{
    class Program
    {
        static void Main(string[] args)
        {
            TextReader rawText;
            var path = args[0];
            rawText = File.OpenText(path);
            List<int> inputNumbers=new List<int>();

            for (string line; (line = rawText.ReadLine()) != null;)
            {
                string[] numsInLine = line.Split(' ');
                foreach (string s in numsInLine)
                {
                    inputNumbers.Add(Convert.ToInt32(s));
                }
            }
            
            int counter = 0;
            for(int i=0;i<inputNumbers.Count/3;i++)
            {
                int fizz = inputNumbers[counter * 3];
                int buzz = inputNumbers[counter * 3 + 1];
                int howFar = inputNumbers[counter * 3 + 2];
                for(int j=1;j<=howFar;j++)
                {
                    if (j % fizz == 0)
                    {
                        Console.Write("F");
                    }
                    if (j % buzz == 0)
                    {
                        Console.Write("B");
                    }
                    if(j % fizz != 0 && j % buzz != 0)
                    {
                        Console.Write(j.ToString());
                    }
                    if(j!=howFar)
                    {
                        Console.Write(" ");
                    }
                }
                counter++;
                Console.WriteLine();
            }
            
        }
    }
}
