/*
SUM OF PRIMES
CHALLENGE DESCRIPTION:

Write a program which determines the sum of the first 1000 prime numbers.

INPUT SAMPLE:

There is no input for this program.

OUTPUT SAMPLE:

Print to stdout the sum of the first 1000 prime numbers.

3682913
*/

using System;
using System.Collections.Generic;

namespace CodeEval_SumOfPrimes
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> primes=new List<int>();
            primes.Add(2);
            int number = 3;
            bool isPrime = true;
            while(primes.Count<1000)
            {
                if(!(number%2==0))
                {
                    isPrime = true;
                    for(int i=1;i<primes.Count;i++)
                    {
                        if(number%primes[i]==0)
                        {
                            isPrime = false;
                            break;
                        }
                    }
                    if(isPrime==true)
                    {
                        primes.Add(number);
                    }
                    
                }
                number++;
            }
            int sum = 0;
            for (int i = 0; i < primes.Count; i++)
            {
                sum += primes[i];
            }
            Console.WriteLine(sum);
            Console.ReadLine();
        }
    }
}
