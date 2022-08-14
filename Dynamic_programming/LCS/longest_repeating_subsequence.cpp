//Longest repeating subsequence

eg - AABEBCDD
output - ABD

If we observe, we can do it by findind LCS betweeb s and s, when i != j

eg - A A B E B C D D
     A A B E B C D D

we will find LCS when i != j

so just add, if(str[i-1] == p[i-1] && i != j)