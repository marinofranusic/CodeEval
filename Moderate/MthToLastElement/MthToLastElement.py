##MTH TO LAST ELEMENT
##SPONSORING COMPANY:
##
##CHALLENGE DESCRIPTION:
##
##Write a program which determines the Mth to the last element in a list.
##
##INPUT SAMPLE:
##
##The first argument is a path to a file. The file contains the series of
##space delimited characters followed by an integer. The integer represents
##an index in the list (1-based), one per line.
##
##For example:
##
##a b c d 4
##e f g h 2
##
##
##OUTPUT SAMPLE:
##
##Print to stdout the Mth element from the end of the list, one per line.
##If the index is larger than the number of elements in the list, ignore
##that input.
##
##For example:
##
##a
##g

import sys;
import argparse;

def main(argv=None):
  with open(sys.argv[1]) as f:
        lines = [line.rstrip('\n') for line in f]
  for line in lines:
      if len(line)>1:
          items=line.split(' ')
          pos=len(items)-int(items[len(items)-1])-1
          if pos>=0:
              print(items[pos])
  
main()
