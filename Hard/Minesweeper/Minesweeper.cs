/*
MINESWEEPER
CHALLENGE DESCRIPTION:

You will be given an M*N matrix. Each item in this matrix is either 
a '*' or a '.'. A '*' indicates a mine whereas a '.' does not. The 
objective of the challenge is to output a M*N matrix where each element
 contains a number (except the positions which actually contain a mine 
 which will remain as '*') which indicates the number of mines adjacent 
 to it. Notice that each position has at most 8 adjacent positions e.g. 
 left, top left, top, top right, right, ...

INPUT SAMPLE:

Your program should accept as its first argument a path to a filename. 
Each line in this file contains M,N, a semicolon and the M*N matrix in 
row major form. E.g.

3,5;**.........*...
4,4;*........*......
OUTPUT SAMPLE:

Print out the new M*N matrix (in row major form) with each position(except
 the ones with the mines) indicating how many adjacent mines are there. E.g.

**100332001*100
*10022101*101110
*/
using System;
using System.Collections.Generic;
using System.IO;

namespace Code_Eval_minesweeper
{
    class Program
    {
        
        static string ProcessLine(string line)
        {
            string[] parts = line.Split(';');
            string[] matrixSizes = parts[0].Split(',');
            int M = Convert.ToInt32(matrixSizes[0]);
            int N = Convert.ToInt32(matrixSizes[1]);
            string givenMatrix = parts[1];
            string retVal = "";
            int counter;
            for (int i = 0; i < givenMatrix.Length; i++)
            {
                counter = 0;
                if(givenMatrix[i]!='*')
                {
                    try
                    {//all positions to the left - first check if they exist
                        if (i % N != 0)
                        {
                            //upper left
                            if (i - N - 1 >= 0 && givenMatrix[i - N - 1] == '*') counter++;
                            //same row left
                            if (i - 1 >= 0 && givenMatrix[i - 1] == '*') counter++;
                            //lower left
                            if (i + N - 1 < M * N && givenMatrix[i + N - 1] == '*') counter++;
                        }
                        //all positions to the right - first check if they exist
                        if ((i + 1) % N != 0)
                        {
                            //upper right
                            if (i - N + 1 >= 0 && givenMatrix[i - N + 1] == '*') counter++;
                            //same row right
                            if (i + 1 < M * N && givenMatrix[i + 1] == '*') counter++;
                            //lower right
                            if (i + N + 1 < M * N && givenMatrix[i + N + 1] == '*') counter++;
                        }
                        //up
                        if (i - N >= 0 && givenMatrix[i - N] == '*') counter++;
                        //down
                        if (i + N < M * N && givenMatrix[i + N] == '*') counter++;
                        
                    }
                    catch(Exception ex)
                    {
                        counter = -1;
                    }
                    retVal += counter.ToString();
                }
                else
                {
                    retVal += "*";
                }
            }
            return retVal;
        }

        static void Main(string[] args)
        {
            TextReader rawText;
            var path = args[0];
            rawText = File.OpenText(path);
            List<int> inputNumbers = new List<int>();
            List<double> distances = new List<double>();
            for (string line; (line = rawText.ReadLine()) != null;)
                if (line.Length > 0)
                    Console.WriteLine(ProcessLine(line));
            Console.ReadLine();
        }
    }
}
