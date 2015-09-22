/*
MAGIC NUMBERS
CHALLENGE DESCRIPTION:

There are two wizards, one good and one evil. The evil wizard has captured 
the princess. The only way to defeat the evil wizard is to recite a set of 
magic numbers. The good wizard has given you two numbers, A and B. Find every 
magic number between A and B, inclusive.

A magic number is a number that has two characteristics:

No digits repeat.
Beginning with the leftmost digit, take the value of the digit and move that 
number of digits to the right. Repeat the process again using the value of the
 current digit to move right again. Wrap back to the leftmost digit as necessary.
 A magic number will visit every digit exactly once and end at the leftmost digit.
For example, consider the magic number 6231.

Start with 6. Advance 6 steps to 3, wrapping around once (6→2→3→1→6→2→3).
From 3, advance to 2.
From 2, advance to 1.
From 1, advance to 6.
INPUT SAMPLE:

The input is a file with each line representing a test case. Each test case 
consists of two integers A and B on a line, separated by spaces. For all test 
cases 1 <= A <= B <= 10000.

10 100
8382 8841

OUTPUT SAMPLE:

For each test case print all magic numbers between A and B, inclusive, on one 
line, separated by spaces. If there is no magic number between A and B, print -1.

13 15 17 19 31 35 37 39 51 53 57 59 71 73 75 79 91 93 95 97
-1
CONSTRAINTS:

The number of test cases is 20.

*/

using System;
using System.Collections.Generic;
using System.IO;

namespace Code_Eval_magicNumbers
{
    class Program
    {
        static bool CheckAllDigitsDifferent(int num)
        {
            bool ret = true;
            string strNum = num.ToString();
            int s,s1;
            for (int j = 0; j < strNum.Length-1; j++)
            {
                s = Convert.ToInt32(strNum[j]) - 48;
                for (int k = j + 1; k < strNum.Length; k++)
                {
                    s1 = Convert.ToInt32(strNum[k]) - 48;
                    if (s == s1)
                        ret = false;
                }

            }
            
            return ret;
        }
        static void Main(string[] args)
        {
            TextReader rawText;
            var path = args[0];
            rawText = File.OpenText(path);
            List<int> results = new List<int>();

            for (string line; (line = rawText.ReadLine()) != null;)
            {
                results.Clear();
                string[] wordsInLine = line.Split(' ');
                int A = Convert.ToInt32(wordsInLine[0].Trim());
                int B = Convert.ToInt32(wordsInLine[1].Trim());

                for (int i = A; i <= B; i++)
                {
                    if (CheckAllDigitsDifferent(i))

                    {
                        string strNum = i.ToString();
                        string[] posStatus = new string[strNum.Length];
                        int s = Convert.ToInt32(strNum[0]) - 48;
                        int p = 0;
                        int l = strNum.Length;
                        for (int j = 0; j < l; j++)
                        {
                            if (p + s < l)
                            {
                                p = p + s;
                                s = Convert.ToInt32(strNum[p]) - 48;
                            }

                            else
                            {
                                p = (p + s) % l;
                                s = Convert.ToInt32(strNum[p]) - 48;
                            }

                            if (posStatus[p] == "V")
                            {
                                posStatus[p] = "F";
                                break;
                            }
                            else
                            {
                                posStatus[p] = "V";
                            }
                            if (j == l - 1)
                                posStatus[p] = "E";
                        }
                        bool ok = true;
                        if (posStatus[0] != "E")
                        {
                            ok = false;
                        }
                        else
                        {
                            for (int j = 1; j < l; j++)
                            {
                                if (posStatus[j] != "V")
                                {
                                    ok = false;
                                }
                            }
                        }
                        if (ok)
                            results.Add(i);
                    }
                }

                if(results.Count==0)
                {
                    Console.WriteLine(-1);
                }
                else
                {
                    for(int i=0;i<results.Count;i++)
                    {
                        Console.Write(results[i]);
                        if(i!=results.Count-1)
                        {
                            Console.Write(" ");
                        }
                        else
                        {
                            Console.WriteLine();
                        }
                    }
                }
                
            }

            Console.ReadLine();
        }
    }
}
