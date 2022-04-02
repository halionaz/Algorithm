# 스택
# 스택

import sys
input = sys.stdin.readline
N = int(input())
stack = []
for _ in range(N) :
    inp = input().split()
    if inp[0] == 'push' :
        stack.append(inp[1])
    elif inp[0] == 'pop' :
        if len(stack) == 0 :
            print(-1)
        else :
            print(stack.pop())
    elif inp[0] == 'size' :
        print(len(stack))
    elif inp[0] == 'empty' :
        if len(stack) == 0 :
            print(1)
        else :
            print(0)
    else :
        if len(stack) == 0 :
            print(-1)
        else :
            print(stack[-1])