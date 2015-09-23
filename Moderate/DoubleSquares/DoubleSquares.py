##DOUBLE SQUARES
##CHALLENGE DESCRIPTION:
##
##Credits: This challenge appeared in the Facebook Hacker Cup 2011.
##A double-square number is an integer X which can be expressed as
##the sum of two perfect squares. For example, 10 is a double-square
##because 10 = 3^2 + 1^2. Your task in this problem is, given X,
##determine the number of ways in which it can be written as the
##sum of two squares.
##
##For example, 10 can only be written as 3^2 + 1^2 (we don't count
##1^2 + 3^2 as being different). On the other hand, 25 can be written
##as 5^2 + 0^2 or as 4^2 + 3^2. 
##NOTE: Do NOT attempt a brute force approach. It will not work. The
##following constraints hold: 
##0 <= X <= 2147483647 
##1 <= N <= 100
##
##INPUT SAMPLE:
##
##Your program should accept as its first argument a path to a filename.
##You should first read an integer N, the number of test cases. The next
##N lines will contain N values of X.
##
##5
##10
##25
##3
##0
##1
##
##OUTPUT SAMPLE:
##
##E.g.
##
##1
##2
##0
##1
##1

from math import sqrt
import sys;
import argparse;

def SumOfSquares(n):
    x, y = int(sqrt(n)), 1
    counter=0
    while x >= y:
        if x*x + y*y < n: y = y + 1
        elif x*x + y*y > n: x = x - 1
        else: 
            counter+=1
            y+=1
    return counter

def main(argv=None):
  with open(sys.argv[1]) as f:
        lines = [line.rstrip('\n') for line in f]
  num=0;
  for line in lines:
      if num!=0:
        a=int(line)
        print(SumOfSquares(a))
      num+=1
main()
