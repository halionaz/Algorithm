# 덱
# 덱

from collections import deque
import sys
input = sys.stdin.readline
q = deque([])
N = int(input())
for _ in range(N) :
    inp = input().split()
    if inp[0] == 'push_front' :
        q.appendleft(inp[1])
    elif inp[0] == 'push_back' :
        q.append(inp[1])
    elif inp[0] == 'pop_front' :
        if len(q) == 0 :
            print(-1)
        else :
            print(q.popleft())
    elif inp[0] == 'pop_back' :
        if len(q) == 0 :
            print(-1)
        else :
            print(q.pop())
    elif inp[0] == 'size' :
        print(len(q))
    elif inp[0] == 'empty' :
        if len(q) == 0:
            print(1)
        else :
            print(0)
    elif inp[0] == 'front' :
        if len(q) == 0 :
            print(-1)
        else :
            print(q[0])
    else :
        if len(q) == 0 :
            print(-1)
        else :
            print(q[-1])