##SPIRAL PRINTING
##CHALLENGE DESCRIPTION:
##
##Write a program to print a 2D array (n x m) in spiral
##order (clockwise)
##
##INPUT SAMPLE:
##
##Your program should accept as its first argument a path
##to a filename. The input file contains several lines.
##Each line is one test case. Each line contains three
##items (semicolon delimited). The first is 'n'(rows),
##the second is 'm'(columns) and the third is a single
##space separated list of characters/numbers in row major
##order. E.g.
##
##3;3;1 2 3 4 5 6 7 8 9
##OUTPUT SAMPLE:
##
##Print out the matrix in clockwise fashion, one per line,
##space delimited. E.g.
##
##1 2 3 6 9 8 7 4 5
import sys;
import argparse;

def GiveSubMatrix(matrix,startRow,startColumn,endRow,endColumn):
    counter=0
    ret=[]
    for i in range(startRow,endRow+1):
        for j in range(startColumn,endColumn+1):
            ret.append( matrix[i][j])
            counter+=1
    return ret

def PrintNormalMatrix(matrix):
    for i in range(len(matrix)):
        for j in range (len(matrix[i])):
            print(str(matrix[i][j])+" " ,end='')
        print()

def CreateMatrix(M,N,items):
    arr=items.split(' ')
    row=0
    col=-1
    mat = [[0 for j in range(N)] for i in range(M)]
    for i in range(len(arr)):
        col+=1
        if col==N:
            col=0
            row+=1
        mat[row][col]=arr[i]
    return mat

def PrintItems(itemList):
    counter=0
    for i in range(len(itemList)):
        print(str(itemList[i])+" ",end='')
        counter+=1
    return counter

def PrintItemsReverse(itemList):
    counter=0
    for i in range(len(itemList)-1,-1,-1):
        print(str(itemList[i])+" ",end='')
        counter+=1
    return counter

def HelperValuesOut(rb,re,cb,ce,c):
    print("Row begin: %d, Row end: %d, Column begin: %d, Column end: %d, Counter: %d" % (rb,re,cb,ce,c))

def main(argv=None):
  with open(sys.argv[1]) as f:
        lines = [line.rstrip('\n') for line in f]
  for line in lines:
      if len(line)>1:
          items=line.split(';')
          M=int(items[0])
          N=int(items[1])
          if (M==1) & (N==1):
              print(items[2])
          else:
              mat=CreateMatrix(M,N,items[2])
              #PrintNormalMatrix(mat)
              row_begin=0
              col_begin=0
              row_end=M-1
              col_end=N-1
              counter=0
              while counter<M*N:
                  #Left->right
                  counter+=PrintItems(GiveSubMatrix(mat,row_begin,col_begin,row_begin,col_end))
                  row_begin+=1
                  #HelperValuesOut(row_begin,row_end,col_begin,col_end,counter)
                  if counter>=M*N: break
                  #Up->down
                  counter+=PrintItems(GiveSubMatrix(mat,row_begin,col_end,row_end,col_end))
                  col_end-=1
                  #HelperValuesOut(row_begin,row_end,col_begin,col_end,counter)
                  if counter>=M*N: break
                  #Right->left
                  counter+=PrintItemsReverse(GiveSubMatrix(mat,row_end,col_begin,row_end,col_end))
                  row_end-=1
                  #HelperValuesOut(row_begin,row_end,col_begin,col_end,counter)
                  if counter>=M*N: break
                  #Down->up
                  counter+=PrintItemsReverse(GiveSubMatrix(mat,row_begin,col_begin,row_end,col_begin))
                  col_begin+=1
                  #HelperValuesOut(row_begin,row_end,col_begin,col_end,counter)
          print()
      
          
  
main()
