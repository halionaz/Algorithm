# 유기농 배추
# 너비 우선 탐색 & 깊이 우선 탐색

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000)
T = int(input())
def dfs(i,j,N,M) :
    ground[i][j] += 1
    if i+1 < N and ground[i+1][j] == 1:
        dfs(i+1,j,N,M)
    if i-1 >= 0 and ground[i-1][j] == 1:
        dfs(i-1,j,N,M)
    if j+1 < M and ground[i][j+1] == 1:
        dfs(i,j+1,N,M)
    if j-1 >= 0 and ground[i][j-1] == 1:
        dfs(i,j-1,N,M)

def bfs(i,j,N,M) :
    queue = [(i,j)]
    ground[i][j] = 2
    while len(queue) > 0 :
        (y,x) = queue.pop(0)
        if y+1 < N and ground[y+1][x] == 1:
            ground[y+1][x] = 2
            queue.append((y+1,x))
        if y-1 >= 0 and ground[y-1][x] == 1:
            ground[y-1][x] = 2
            queue.append((y-1,x))
        if x+1 < M and ground[y][x+1] == 1:
            ground[y][x+1] = 2
            queue.append((y,x+1))
        if x-1 >= 0 and ground[y][x-1] == 1:
            ground[y][x-1] = 2
            queue.append((y,x-1))

for _ in range(T) :
    # DFS
    # M,N,K = map(int,input().split())
    # ground = [[0]*M for _ in range(N)]
    # for _ in range(K) :
    #     x,y = map(int,input().split())
    #     ground[y][x] = 1
    # ans = 0
    # for i in range(N) :
    #     for j in range(M) :
    #         if ground[i][j] == 1 :
    #             dfs(i,j,N,M)
    #             ans += 1
    # print(ans)

    # BFS
    M,N,K = map(int,input().split())
    ground = [[0]*M for _ in range(N)]
    for _ in range(K) :
        x,y = map(int,input().split())
        ground[y][x] = 1
    ans = 0
    for i in range(N) :
        for j in range(M) :
            if ground[i][j] == 1 :
                bfs(i,j,N,M)
                ans += 1
    print(ans)