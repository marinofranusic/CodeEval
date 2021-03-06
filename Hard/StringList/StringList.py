##STRING LIST
##CHALLENGE DESCRIPTION:
##
##Credits: Challenge contributed by Max Demian. 
##
##You are given a number N and a string S. Print all of the possible ways to write a string of length N from the characters in string S, comma delimited in alphabetical order.
##
##INPUT SAMPLE:
##
##The first argument will be the path to the input filename containing
## the test data. Each line in this file is a separate test case. 
##Each line is in the format: N,S i.e. a positive integer, followed by 
##a string (comma separated). E.g.
##
##1,aa
##2,ab
##3,pop
##OUTPUT SAMPLE:
##
##Print all of the possible ways to write a string of length N from the 
##characters in string S comma delimited in alphabetical order, with no 
##duplicates. E.g.
##
##a
##aa,ab,ba,bb
##ooo,oop,opo,opp,poo,pop,ppo,ppp

import sys;
import argparse;
from itertools import product;
def main(argv=None):
  with open(sys.argv[1]) as f:
        lines = [line.rstrip('\n') for line in f]
  for line in lines:
      if line!="":
          item=line.split(",")
          l=int(item[0])
          keywords = [''.join(i) for i in product(item[1], repeat = l)]
          uKeys=list(set(keywords))
          uKeys=sorted(uKeys)
          for i in range(len(uKeys)):
              if i!=len(uKeys)-1:
                print(uKeys[i]+",",end="")
              else:
                print(uKeys[i])
main()
