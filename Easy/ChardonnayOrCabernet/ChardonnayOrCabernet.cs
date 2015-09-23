/*
CHARDONNAY OR CABERNET
CHALLENGE DESCRIPTION:

Your good friend Tom is admirer of tasting different types of fine 
wines. What he loves even more is to guess their names. One day, 
he was sipping very extraordinary wine. Tom was sure he had tasted 
it before, but what was its name? The taste of this wine was so 
familiar, so delicious, so pleasant… but what is it exactly? To find 
the answer, Tom decided to taste the wines we had. He opened wine 
bottles one by one, tasted different varieties of wines, but still 
could not find the right one. He was getting crazy, “No, it’s not that!”
 desperately breaking a bottle of wine and opening another one. 
 Tom went off the deep end not knowing what this wine was. Everything
 he could say is just several letters of its name. You can no longer
 look at it and decided to help him. 
Your task is to write a program that will find the wine name, containing
 all letters that Tom remembers.

INPUT SAMPLE:

The first argument is a path to a file. Each line includes a test case, 
which contains names of wines and letters that Tom remembers. Names and
 letters are separated by a vertical bar '|'.

For example:

Cabernet Merlot Noir | ot
Chardonnay Sauvignon | ann
Shiraz Grenache | o

OUTPUT SAMPLE:

You should print wine names, containing all letters that Tom remembered. Letters can be anywhere in wine names. If there is no name with all letters, print False.

For example:

Merlot
Chardonnay Sauvignon
False
CONSTRAINTS:

Wine name length can be from 2 to 15 characters.
Number of letters that Tom remembered does not exceed 5.
Number of wine names in a test case can be from 2 to 10.
If there is no wine name containing all letters, print False.
The number of test cases is 40.
*/

using System;
using System.Collections.Generic;
using System.IO;

namespace Code_Eval_wines
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
                string[] wordsInLine = line.Split('|');
                string result = "False";
                if (wordsInLine.Length > 1)
                {
                    string toFind = wordsInLine[1].Trim();
                    List<string> listOfWines = new List<string>(wordsInLine[0].Trim().Split(' '));
                    List<string> results = new List<string>(); 
                    wordsInLine = null;
                    for (int i = 0; i < listOfWines.Count; i++)
                    {
                        bool ok = true;
                        for (int j = 0; j < toFind.Length; j++)
                        {
                            int c1 = 0;
                            int c2 = 0;
                            if (!listOfWines[i].Contains(toFind[j].ToString()))
                            {
                                ok = false;
                            }
                            else
                            {
                                for(int k=0;k< listOfWines[i].Length;k++)
                                {
                                    if (listOfWines[i][k] == toFind[j])
                                        c1++;
                                }
                                for (int k = 0; k < toFind.Length; k++)
                                {
                                    if (toFind[k] == toFind[j])
                                        c2++;
                                }
                                if (c1 != c2)
                                    ok = false;
                            }
                        }
                        if(ok)
                        {
                            results.Add(listOfWines[i]);
                        }
                        
                        
                    }
                    if (results.Count == 0)
                    {
                        Console.WriteLine("False");
                    }
                    else
                    {
                        for (int j = 0; j < results.Count; j++)
                        {
                            Console.Write(results[j]);
                            if (j != results.Count - 1)
                            {
                                Console.Write(" ");
                            }
                            else
                            {
                                Console.WriteLine();
                            }
                        }
                    }
                    //Console.WriteLine();
                }
            }

            Console.ReadLine();
        }
    }
}