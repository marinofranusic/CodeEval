/*
TEXT TO NUMBER
CHALLENGE DESCRIPTION:

You have a sting which contains a number represented as English text. 
Your task is to translate these numbers into their integer representation.
 The numbers can range from negative 999,999,999 to positive 999,999,999. 
 The following is an exhaustive list of English words that your program must 
 account for:

negative,
zero, one, two, three, four, five, six, seven, eight, nine,
ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen,
twenty, thirty, forty, fifty, sixty, seventy, eighty, ninety,
hundred,
thousand,
million
INPUT SAMPLE:

Your program should accept as its first argument a path to a filename. Input 
example is the following

fifteen
negative six hundred thirty eight
zero
two million one hundred seven
- Negative numbers will be preceded by the word negative. 
- The word "hundred" is not used when "thousand" could be. E.g. 1500 is written 
"one thousand five hundred", not "fifteen hundred".

OUTPUT SAMPLE:

Print results in the following way.

15
-638
0
2000107

*/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.IO;

namespace Code_Eval_TextNum
{
    class Program
    {
        static int TextToNum(string text)
        {
            int ret = 0;
            if (text == "negative")
            {
                ret = -1;
            }
            else if (text == "zero")
            {
                ret = 0;
            }
            else if (text == "one")
            {
                ret = 1;
            }
            else if (text == "two")
            {
                ret = 2;
            }
            else if (text == "three")
            {
                ret = 3;
            }
            else if (text == "four")
            {
                ret = 4;
            }
            else if (text == "five")
            {
                ret = 5;
            }
            else if (text == "six")
            {
                ret = 6;
            }
            else if (text == "seven")
            {
                ret = 7;
            }
            else if (text == "eight")
            {
                ret = 8;
            }
            else if (text == "nine")
            {
                ret = 9;
            }
            else if (text == "ten")
            {
                ret = 10;
            }
            else if (text == "eleven")
            {
                ret = 11;
            }
            else if (text == "twelve")
            {
                ret = 12;
            }
            else if (text == "thirteen")
            {
                ret = 13;
            }
            else if (text == "fourteen")
            {
                ret = 14;
            }
            else if (text == "fifteen")
            {
                ret = 15;
            }
            else if (text == "sixteen")
            {
                ret = 16;
            }
            else if (text == "seventeen")
            {
                ret = 17;
            }
            else if (text == "eighteen")
            {
                ret = 18;
            }
            else if (text == "nineteen")
            {
                ret = 19;
            }
            else if (text == "twenty")
            {
                ret = 20;
            }
            else if (text == "thirty")
            {
                ret = 30;
            }
            else if (text == "forty")
            {
                ret = 40;
            }
            else if (text == "fifty")
            {
                ret = 50;
            }
            else if (text == "sixty")
            {
                ret = 60;
            }
            else if (text == "seventy")
            {
                ret = 70;
            }
            else if (text == "eighty")
            {
                ret = 80;
            }
            else if (text == "ninety")
            {
                ret = 90;
            }
            else if (text == "hundred")
            {
                ret = 100;
            }
            else if (text == "thousand")
            {
                ret = 1000;
            }
            else if (text == "million")
            {
                ret = 1000000;
            }

            return ret;
        }

        static void Main(string[] args)
        {
            TextReader rawText;
            var path = args[0];
            rawText = File.OpenText(path);
            for (string line; (line = rawText.ReadLine()) != null;)
            {
                if (line != "")
                {
                    string[] words = line.Split(' ');
                    int endNum = 0;
                    int tempNum = 0;
                    int multi = 0;
                    bool negative = false;
                    foreach (string word in words)
                    {
                        tempNum = TextToNum(word);
                        if (tempNum == 1000000 || tempNum==1000)
                        {
                            endNum += multi * tempNum;
                            multi = 0;

                        }
                        else if (tempNum == 100)
                        {
                            multi = multi * tempNum;
                        }
                        else if (tempNum == -1)
                        {
                            negative = true;
                        }
                        else
                        {
                            multi += TextToNum(word);
                        }
                    }
                    endNum += multi;
                    if (negative)
                    {
                        endNum *= -1;
                    }
                    Console.WriteLine(endNum);
                }
            }
            Console.ReadLine();
        }
    }
}
