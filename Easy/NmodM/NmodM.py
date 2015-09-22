##N MOD M
##CHALLENGE DESCRIPTION:
##
##
##Given two integers N and M, calculate N Mod M
##(without using any inbuilt modulus operator).
##
##INPUT SAMPLE:
##
##Your program should accept as its first argument
##a path to a filename. Each line in this file contains
##two comma separated positive integers. E.g.
##
##20,6
##2,3
##You may assume M will never be zero.
##
##OUTPUT SAMPLE:
##
##Print out the value of N Mod M

import sys;
import argparse;
from time import strftime
import math
def main(argv=None):
  with open(sys.argv[1]) as f:
        lines = [line.rstrip('\n') for line in f]
  for line in lines:
      numbers=line.split(',')
      a=math.floor(int(numbers[0])/int(numbers[1]))
      print(int(numbers[0])-int(numbers[1])*a)
      
main()
