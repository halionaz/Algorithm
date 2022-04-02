# 트리의 지름
# 트리 & 너비 우선 탐색

import sys
from collections import deque
input = sys.stdin.readline
V = int(input())
line = [[] for _ in range(V+1)]
for _ in range(V) :
    inp = list(map(int,input().split()))
    for i in range((len(inp)-2)//2) :
        line[inp[0]].append((inp[i*2+1],inp[i*2+2]))
# BFS
def bfs(start) :
    queue = deque([])
    queue.append(start)
    dp = [-1]*(V+1)
    dp[start] = 0
    maximum = 0
    maxIndex = start
    while len(queue) :
        x = queue.popleft()
        for i,j in line[x] :
            if j and dp[i] == -1 :
                dp[i] = j + dp[x]
                queue.append(i)
                if dp[i] > maximum :
                    maximum = dp[i]
                    maxIndex = i
    return (maxIndex,maximum)
fE = bfs(1)
sE = bfs(fE[0])
print(sE[1])