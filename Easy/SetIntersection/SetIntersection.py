##SET INTERSECTION
##CHALLENGE DESCRIPTION:
##
##
##You are given two sorted list of numbers (ascending order).
##The lists themselves are comma delimited and the two lists
##are semicolon delimited. Print out the intersection of these
##two sets.
##
##INPUT SAMPLE:
##
##File containing two lists of ascending order sorted integers,
##comma delimited, one per line. E.g. 
##1,2,3,4;4,5,6
##20,21,22;45,46,47
##7,8,9;8,9,10,11,12
##
##OUTPUT SAMPLE:
##
##Print out the ascending order sorted intersection of the two
##lists, one per line. Print empty new line in case the lists
##have no intersection. E.g. 
##
##4
##
##8,9

import sys;
import argparse;
from time import strftime
def main(argv=None):
  with open(sys.argv[1]) as f:
        lines = [line.rstrip('\n') for line in f]
  for line in lines:
      lists=line.split(';')
      numbers1=lists[0].split(',')
      numbers2=lists[1].split(',')
      a=set(numbers1).intersection(numbers2)
      a=sorted(a,key=int)
      for i in range(len(a)):
        print(a[i],end="")
        if i!=len(a)-1:
            print(",",end="")
      print()
main()
