# 내리막 길
# 깊이 우선 탐색 & 다이나믹 프로그래밍

import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline
M, N = map(int,input().split())
vecX = (1,0,-1,0)
vecY = (0,1,0,-1)
arr = []
for _ in range(M) :
    arr.append(list(map(int,input().split())))
memo = [[-1]*N for _ in range(M)] 
def dfs(x, y) :
    if x == N-1 and y == M-1 :
        return 1
    elif memo[y][x] != -1 :
        return memo[y][x]
    else :
        memo[y][x] = 0
        for i in range(4) :
            newX = x + vecX[i]
            newY = y + vecY[i]
            if 0 <= newX < N and 0 <= newY < M :
                if arr[newY][newX] < arr[y][x] :
                    memo[y][x] += dfs(newX,newY)
        return memo[y][x]
print(dfs(0,0))