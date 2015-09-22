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