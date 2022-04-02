# DFS와 BFS
# 너비 우선 탐색 & 깊이 우선 탐색

import sys
input = sys.stdin.readline
N,M,V = map(int,input().split())
line = [[0]*(N+1) for _ in range(N+1)]
for _ in range(M) :
    x,y = map(int,input().split())
    line[x][y],line[y][x] = 1,1
memo = [0]*(N+1)
def dfs(x):
    memo[x] = 1
    print(x, end=' ')
    for i in range(1,N+1) :
        if line[x][i] and not memo[i] :
            dfs(i)
def bfs(x):
    queue = [x]
    memo[x] = 0
    while len(queue) > 0 :
        i = queue.pop(0)
        print(i, end=' ')
        for j in range(1,N+1) :
            if memo[j] == 1 and line[i][j] :
                queue.append(j)
                memo[j] = 0
    
dfs(V)
print()
bfs(V)