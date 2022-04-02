# 나이순 정렬
# 정렬

import sys

N = int(sys.stdin.readline())
arr = []
for i in range(N) :
    inp = sys.stdin.readline().split()
    arr.append([int(inp[0]),inp[1]])
arr.sort(key = lambda x: x[0])
for i in arr :
    print(i[0],i[1])