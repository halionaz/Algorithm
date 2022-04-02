# 좌표 정렳하기 2
# 정렬

import sys
N = int(sys.stdin.readline())
arr = []
for _ in range(N) :
    inp = list(map(int,sys.stdin.readline().split()))
    arr.append([inp[1],inp[0]])
arr.sort()
for i in arr :
    print(i[1],i[0])