##DISTINCT SUBSEQUENCES
##CHALLENGE DESCRIPTION:
##
##A subsequence of a given sequence S consists of S with zero or
##more elements deleted. Formally, a sequence Z = z1z2..zk is a
##subsequence of X = x1x2...xm, if there exists a strictly increasing
##sequence of indicies of X such that for all j=1,2,...k we have
##Xij = Zj. E.g. Z=bcdb is a subsequence of X=abcbdab with corresponding
##index sequence <2,3,5,7>
##
##INPUT SAMPLE:
##
##Your program should accept as its first argument a path to a filename.
##Each line in this file contains two comma separated strings. The first
##is the sequence X and the second is the subsequence Z. E.g.
##
##
##
##babgbag,bag
##rabbbit,rabbit
##OUTPUT SAMPLE:
##
##Print out the number of distinct occurrences of Z in X as a subsequence
##E.g.
##
##
##5
##3


import sys;
import argparse;

def numDistinct(word1, word2):
    a=len(word1)
    b=len(word2)
    dp = [[0 for x in range(b+1)] for x in range(a+1)]
    for i in range(a+1):
        dp[i][0]=1
    for i in range(1,a+1,1):
        for j in range(1,b+1,1):
            dp[i][j]=dp[i-1][j]
            if word1[i-1]==word2[j-1]:
                dp[i][j]+=dp[i-1][j-1]
    return dp[a][b]
            
def main(argv=None):
  with open(sys.argv[1]) as f:
        lines = [line.rstrip('\n') for line in f]
  
  for line in lines:
      if len(line)>1:
          words=line.split(',')
          letPositions=dict()
          print(numDistinct(words[0],words[1]))
  
  
main()
