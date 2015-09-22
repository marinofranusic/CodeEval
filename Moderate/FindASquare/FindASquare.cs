/*
FIND A SQUARE
CHALLENGE DESCRIPTION:

You have coordinates of four points on a plane. Check whether they make a square.

INPUT SAMPLE:

Your program should accept as its first argument a path to a filename. Input example is the following

(1,6), (6,7), (2,7), (9,1)
(4,1), (3,4), (0,5), (1,2)
(4,6), (5,5), (5,6), (4,5)
All numbers in input are integers between 0 and 10

OUTPUT SAMPLE:

Print results in the following way.

false
false
true
*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;

namespace Code_Eval_FindSquare
{
    class Program
    {
        static void Main(string[] args)
        {
            TextReader rawText;
            var path = args[0];
            rawText = File.OpenText(path);
            List<int> inputNumbers = new List<int>();
            List<double> distances = new List<double>();
            for (string line; (line = rawText.ReadLine()) != null;)
            {
                for (int i=0;i<4;i++)
                {
                    int start = line.IndexOf('(');
                    int end = line.IndexOf(')');
                    string[] point = line.Substring(start + 1, end - (start + 1)).Split(',');
                    foreach (string a in point)
                        inputNumbers.Add(Convert.ToInt32(a));
                    line = line.Substring(end + 1);
                }
                                
                distances.Add(Math.Sqrt(Math.Pow((inputNumbers[0] - inputNumbers[2]), 2) + Math.Pow((inputNumbers[1] - inputNumbers[3]), 2)));
                distances.Add(Math.Sqrt(Math.Pow((inputNumbers[0] - inputNumbers[4]), 2) + Math.Pow((inputNumbers[1] - inputNumbers[5]), 2)));
                distances.Add(Math.Sqrt(Math.Pow((inputNumbers[0] - inputNumbers[6]), 2) + Math.Pow((inputNumbers[1] - inputNumbers[7]), 2)));
                distances.Add(Math.Sqrt(Math.Pow((inputNumbers[2] - inputNumbers[4]), 2) + Math.Pow((inputNumbers[3] - inputNumbers[5]), 2)));
                distances.Add(Math.Sqrt(Math.Pow((inputNumbers[2] - inputNumbers[6]), 2) + Math.Pow((inputNumbers[3] - inputNumbers[7]), 2)));
                distances.Add(Math.Sqrt(Math.Pow((inputNumbers[4] - inputNumbers[6]), 2) + Math.Pow((inputNumbers[5] - inputNumbers[7]), 2)));
                var sorted = from dbl in distances
                             orderby dbl ascending
                             select dbl;
                distances = sorted.ToList();
                if(distances[0]==distances[1] && distances[0]==distances[2] && distances[0] == distances[3] && distances[1] == distances[2] && distances[1] == distances[3] && distances[2] == distances[3] && distances[4] == distances[5] && distances[0]<distances[4])
                {
                    Console.WriteLine("true");
                }
                else
                {
                    Console.WriteLine("false");
                }
                distances.Clear();
                inputNumbers.Clear();
            }
            Console.ReadLine();
        }
    }
}
