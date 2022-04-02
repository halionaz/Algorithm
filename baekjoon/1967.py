# 트리의 지름 
# 트리 & 너비 우선 탐색

# 1167번이랑 뭐가 다른거지?

import sys
from collections import deque
input = sys.stdin.readline
n = int(input())
line = [[] for _ in range(n+1)]
for _ in range(n-1) :
    a,b,c = map(int,input().split())
    line[a].append((b,c))
    line[b].append((a,c))
# BFS
def bfs(start) :
    queue = deque([])
    queue.append(start)
    dp = [-1]*(n+1)
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