/*
PRIME PALINDROME
CHALLENGE DESCRIPTION:


Write a program which determines the largest prime palindrome less than 1000.

INPUT SAMPLE:

There is no input for this program.

OUTPUT SAMPLE:

Print to stdout the largest prime palindrome less than 1000.

929
*/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeEval_PrimePalindrome
{
    class Program
    {
        static int BigPrimePalindrome(int start)
        {
            bool isPrime = true;
            for (int i = start; i > 0; i--)
            {
                if (!(i % 2 == 0))
                {
                    isPrime = true;
                    for (int j = 3; j < i / 2; j++)
                    {
                        if (i % j == 0)
                        {
                            isPrime = false;
                            break;
                        }
                    }
                    if (isPrime == true)
                    {
                        string primNo = i.ToString();
                        bool isPalindrome = true;
                        for (int k = 0; k <= primNo.Length / 2; k++)
                        {
                            if (primNo[k] != primNo[primNo.Length - k-1])
                            {
                                isPalindrome = false;
                            }
                        }
                        if (isPalindrome == true)
                        {
                            return i;
                        }
                    }

                }
            }
            return 0;
        }
        static void Main(string[] args)
        {
            Console.WriteLine(BigPrimePalindrome(1000).ToString());
            Console.ReadLine();
        }
    }
}
