using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Code_Eval_TextDollar
{
    class Program
    {
        static string NumToText(int number)
        {
            string ret = "";
            switch(number)
            {
                case 1:
                    ret = "One";
                    break;
                case 2:
                    ret = "Two";
                    break;
                case 3:
                    ret = "Three";
                    break;
                case 4:
                    ret = "Four";
                    break;
                case 5:
                    ret = "Five";
                    break;
                case 6:
                    ret = "Six";
                    break;
                case 7:
                    ret = "Seven";
                    break;
                case 8:
                    ret = "Eight";
                    break;
                case 9:
                    ret = "Nine";
                    break;
                case 10:
                    ret = "Ten";
                    break;
                case 11:
                    ret = "Eleven";
                    break;
                case 12:
                    ret = "Twelve";
                    break;
                case 13:
                    ret = "Thirteen";
                    break;
                case 14:
                    ret = "Fourteen";
                    break;
                case 15:
                    ret = "Fifteen";
                    break;
                case 16:
                    ret = "Sixteen";
                    break;
                case 17:
                    ret = "Seventeen";
                    break;
                case 18:
                    ret = "Eighteen";
                    break;
                case 19:
                    ret = "Nineteen";
                    break;
                case 20:
                    ret = "Twenty";
                    break;
                case 30:
                    ret = "Thirty";
                    break;
                case 40:
                    ret = "Forty";
                    break;
                case 50:
                    ret = "Fifty";
                    break;
                case 60:
                    ret = "Sixty";
                    break;
                case 70:
                    ret = "Seventy";
                    break;
                case 80:
                    ret = "Eighty";
                    break;
                case 90:
                    ret = "Ninety";
                    break;

            }
            
            
            return ret;
        }

        static string ProcessThreeDigitNumber(int number)
        {
            string ret = "";
            int temp2 = number / 100;
            if (temp2 != 0)
            {
                ret += NumToText(temp2);
                ret += "Hundred";
            }

            temp2 = number % 100;
            if (temp2 != 0)
            {
                if (temp2 < 20)
                {
                    ret += NumToText(temp2);
                }
                else
                {
                    int temp3 = temp2 / 10;
                    ret += NumToText(temp3 * 10);
                    ret += NumToText(temp2 % 10);
                }
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
                    int givenNum = Convert.ToInt32(line);
                    string result = "";
                    //millions
                    int temp1 = givenNum / 1000000;
                    result+=ProcessThreeDigitNumber(temp1);
                    if(temp1>0)
                    {
                        result += "Million";
                    }
                    //thousands
                    temp1 = (givenNum % 1000000) / 1000;
                    result += ProcessThreeDigitNumber(temp1);
                    if (temp1 > 0)
                    {
                        result += "Thousand";
                    }
                    //hundreds
                    temp1 = (givenNum % 1000000) % 1000;
                    result += ProcessThreeDigitNumber(temp1);
                    result += "Dollars";
                    Console.WriteLine(result);
                }
            }
            Console.ReadLine();
        }
    }
}
