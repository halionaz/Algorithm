# 빠른 A+B
# 사칙연산

import sys
T = int(input())
inp = []
for i in range(T) :
    inp.append(sys.stdin.readline().rstrip().split())

for i in range(T) :
    print(int(inp[i][0])+int(inp[i][1]))

