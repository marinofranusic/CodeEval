/*
UNIQUE ELEMENTS
CHALLENGE DESCRIPTION:


You are given a sorted list of numbers with duplicates. 
Print out the sorted list with duplicates removed.

INPUT SAMPLE:

File containing a list of sorted integers, comma delimited, one per line. E.g. 

1,1,1,2,2,3,3,4,4
2,3,4,5,5

OUTPUT SAMPLE:

Print out the sorted list with duplicates removed, one per line. 
E.g.

1,2,3,4
2,3,4,5
*/

using System;
using System.Collections.Generic;
using System.IO;

namespace CodeEval_ListDuplicates
{
    class Program
    {
        static void Main(string[] args)
        {
            TextReader rawText;
            var path = args[0];
            rawText = File.OpenText(path);
            List<int> inputNumbers = new List<int>();
            int tempNo;
            for (string line; (line = rawText.ReadLine()) != null;)
            {
                string[] numbers = line.Trim().Split(',');
                foreach(string s in numbers)
                {
                    tempNo = Convert.ToInt32(s);
                    if(!inputNumbers.Contains(tempNo))
                    {
                        inputNumbers.Add(tempNo);
                    }
                }
                inputNumbers.Sort();
                for(int i=0;i<inputNumbers.Count;i++)
                {
                    Console.Write(inputNumbers[i]);
                    if(i!=inputNumbers.Count-1)
                    {
                        Console.Write(",");
                    }
                }
                Console.WriteLine();
                inputNumbers.Clear();
            }
            
        }
    }
}
