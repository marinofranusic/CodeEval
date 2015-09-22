##MINIMUM PATH SUM
##CHALLENGE DESCRIPTION:
##
##You are given an n*n matrix of integers. You can move only right
##and down. Calculate the minimal path sum from the top left to the
##bottom right
##
##INPUT SAMPLE:
##
##Your program should accept as its first argument a path to a filename.
##The first line will have the value of n(the size of the square matrix).
##This will be followed by n rows of the matrix. (Integers in these rows
##will be comma delimited). After the n rows, the pattern repeats. E.g.
##
##2
##4,6
##2,8
##3
##1,2,3
##4,5,6
##7,8,9
##OUTPUT SAMPLE:
##
##Print out the minimum path sum for each matrix. E.g.
##
##14
##21

import sys;
import argparse;

def MinSumPath(mat,size):
    dp = [[0 for x in range(size)] for x in range(size)]
    dp[0][0]=mat[0][0]
    for i in range(1,size,1):
        dp[i][0]=int(dp[i-1][0])+int(mat[i][0])
        dp[0][i]=int(dp[0][i-1])+int(mat[0][i])
    for i in range(1,size,1):
        for j in range(1,size,1):
            dp[i][j]=minNumber(dp[i-1][j],dp[i][j-1])+int(mat[i][j])
    return dp[size-1][size-1]
    
def minNumber(a,b):
    if a<b:
        return a
    else:
        return b
def main(argv=None):
  with open(sys.argv[1]) as f:
        lines = [line.rstrip('\n') for line in f]
  counter=0
  size=0
  inputMatrix=[]
  for line in lines:
     
      if counter==0:
        size=int(line)
        counter=size
        inputMatrix = [[0 for x in range(size)] for x in range(size)]
      elif counter!=0:
          numbers=line.split(',')
          for i in range(size):
              inputMatrix[size-counter][i]=numbers[i]
          counter-=1
      if counter==0:
          print(MinSumPath(inputMatrix,size))
      
main()
