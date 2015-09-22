##PLAY WITH DNA
##CHALLENGE DESCRIPTION:
##
##This challenge is related to bioinformatics. To help in a DNA research,
##you have to write an algorithm that finds all the occurrences of a DNA
##segment in a given DNA string. But, it would be too easy for you.
##So, write an algorithm with the maximum N number of allowed mismatches.
##By mismatch we mean the minimum of the total number of substitutions,
##deletions, and insertions that must be performed on a DNA slice to
##completely match a given segment. You need to compare the DNA slices
##with the same length as a given pattern (for example, the segments
##'AGTTATC' -> 'AGTATGC' have only 2 mismatches).
##
##For the DNA string 'CGCCCGAATCCAG' and the segment 'CCC', the first
##match with the maximum 1 allowed mismatch is 'CGC', the second one
##is 'GCC', the third one is 'CCC', and so on.
##
##CCC -> CGC # One mismatch
##CCC -> GCC # One mismatch
##CCC -> CCC # 0 mismatch
##For the given segment 'CCC', the DNA string 'CGCCCGAATCCAG', and the
##maximum allowed mismatch '1', the list of the matches is
##'CGC GCC CCC CCG TCC CCA'.
##
##INPUT SAMPLE:
##
##Your program should accept a path to a filename as its first argument.
##Each line in the file contains a segment of DNA, the maximum number
##of allowed mismatches N, and a DNA string separated by a single space.
##
##
##
##CCC 1 CGCCCGAATCCAG
##GCGAG 2 CCACGGCCTATGTATTTGCAAGGATCTGGGCCAGCTAAATCAGCACCCCTGGAACGGCAAGGTT
##CATTTTGTTGCGCGCATAG
##CGGCGCC 1 ACCCCCGCAGCCATATGTCCCCAGCTATTTAATGAGGGCCCCGAACACGGGGAGTCTTACAC
##GATCTGCCCTGGAATCGC
##OUTPUT SAMPLE:
##
##Print out all the occurrences of a segment S in a DNA string in the order
##from the best match (separated by a single space) taking into account the
##number of allowed mismatches. In case of several segments with the equal
##number of matches, print them in alphabetical order. If there is no such
##a case, print out 'No match'.
##
##
##
##CCC CCA CCG CGC GCC TCC
##GCAAG GCAAG GCCAG GCGCG GCGCA GCTAA
##No match
##CONSTRAINTS:
##
##The length of a DNA string is in a range from 100 to 300.
##N is in a range from 0 to 40.
##The length of a segment S is in a range from 3 to 50.

import sys;
import argparse;
from operator import itemgetter,attrgetter

def Levenshtein(s1, s2):
    previous_row = range(len(s2) + 1)
    for i, c1 in enumerate(s1):
        current_row = [i + 1]
        for j, c2 in enumerate(s2):
            insertions = previous_row[j + 1] + 1 # j+1 instead of j since previous_row and current_row are one character longer
            deletions = current_row[j] + 1       # than s2
            substitutions = previous_row[j] + (c1 != c2)
            current_row.append(min(insertions, deletions, substitutions))
        previous_row = current_row
    
    return previous_row[-1]

def BuildSegments(segment,miss,DNA):
    ret=list()
    for i in range(len(DNA)-len(segment)+1):
        m=Levenshtein(segment,DNA[i:i+len(segment)])
        if m<=miss:
            ret.append((DNA[i:i+len(segment)],m))
    return ret

def main(argv=None):
  with open(sys.argv[1]) as f:
        lines = [line.rstrip('\n') for line in f]
  for line in lines:
      if line!="":
          item=line.split(" ")
          a=BuildSegments(item[0],int(item[1]),item[2])
          a=sorted(a,key=itemgetter(1,0))
          if len(a)>0:
              for g in a:
                  print(g[0]+" ",end="")
          else:
              print("No match",end="")
          print()
  
main()
