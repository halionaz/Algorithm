# 트리의 부모 찾기
# 너비 우선 탐색

import sys
from collections import deque
input= sys.stdin.readline
N = int(input())
line = [[] for _ in range(N+1)]
for _ in range(N-1) :
    a,b = map(int,input().split())
    line[a].append(b)
    line[b].append(a)
parent = [0]*(N+1)
parent[1] = 1

# 깊이 우선 탐색은 재귀를 너무 많이 해야 함

# sys.setrecursionlimit(999999999)
# def dfs(start) :
#     for i in line[start] :
#         if parent[i] == 0 :
#             parent[i] = start
#             dfs(i)
#     return
# dfs(1)

def bfs(start) :
    queue = deque([start])
    while len(queue) :
        i = queue.popleft()
        for j in line[i] :
            if parent[j] == 0 :
                parent[j] = i
                queue.append(j)
bfs(1)

for i in range(2,N+1) :
    print(parent[i])