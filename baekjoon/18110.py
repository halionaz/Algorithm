# solved.ac
# 구현

import sys
input = sys.stdin.readline
def round(n): return int(n)+1 if n-int(n)>=0.5 else int(n)
N = int(input())
splice = round(N*15/100)
arr = []
for _ in range(N) :
    arr.append(int(input()))
if N == 0:
    print(0)
else :
    splicedArr = sorted(arr)[splice:N-splice]
    print(round(sum(splicedArr)/(N-splice*2)))