# 제로
# 스택

import sys
input = sys.stdin.readline
K = int(input())
arr = []
for _ in range(K) :
    inp = int(input())
    if inp == 0 :
        arr.pop()
    else :
        arr.append(inp)
print(sum(arr))