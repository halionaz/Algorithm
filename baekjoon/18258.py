# 큐 2
# 큐

# import sys
# input = sys.stdin.readline
# N = int(input())
# queue = []
# for _ in range(N) :
#     inp = input().split()
#     if inp[0] == 'push' :
#         queue.append(inp[1])
#     elif inp[0] == 'pop' :
#         if len(queue) == 0 :
#             print(-1)
#         else :
#             print(queue.pop(0))
#     elif inp[0] =='size' :
#         print(len(queue))
#     elif inp[0] == 'empty' :
#         if len(queue) == 0:
#             print(1)
#         else :
#             print(0)
#     elif inp[0] == 'front' :
#         if len(queue) == 0 :
#             print(-1)
#         else :
#             print(queue[0])
#     else :
#         if len(queue) == 0 :
#             print(-1)
#         else :
#             print(queue[-1])

#큐 2
import sys
from collections import deque
input = sys.stdin.readline
N = int(input())
queue = deque([])
for _ in range(N) :
    inp = input().split()
    if inp[0] == 'push' :
        queue.append(inp[1])
    elif inp[0] == 'pop' :
        if len(queue) == 0 :
            print(-1)
        else :
            print(queue.popleft())
    elif inp[0] =='size' :
        print(len(queue))
    elif inp[0] == 'empty' :
        if len(queue) == 0 :
            print(1)
        else :
            print(0)
    elif inp[0] == 'front' :
        if len(queue) == 0 :
            print(-1)
        else :
            print(queue[0])
    else :
        if len(queue) == 0 :
            print(-1)
        else :
            print(queue[-1])