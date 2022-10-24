# 바이러스
# 그래프 탐색 & 너비 우선 탐색 & 깊이 우선 탐색

import sys
input = sys.stdin.readline
N = int(input())
M = int(input())
network = [[0]*(N+1) for _ in range(N+1)]
for _ in range(M) :
    x,y = map(int,input().split())
    network[x][y],network[y][x] = 1,1

# # 깊이 우선 탐색 - DFS

# visited = [0]*(N+1)
# ans = 0
# def dfs(start) :
#     global ans 
#     ans += 1
#     visited[start] = 1
#     for i in range(2,N+1) :
#         if not visited[i] and network[start][i] :
#             dfs(i)
# dfs(1)
# print(ans-1)

# 너비 우선 탐색 - BFS

visited = [0]*(N+1)
ans = 0
queue = [1]
while len(queue) > 0 :
    i = queue.pop(0)
    for j in range(2,N+1) :
        if not visited[j] and network[i][j] :
            visited[j] = 1
            ans+=1
            queue.append(j)
print(ans)