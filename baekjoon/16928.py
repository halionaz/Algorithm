# 뱀과 사다리 게임
# 그래프 탐색 & 다이나믹 프로그래밍 & 깊이 우선 탐색
# bottom-up

import sys
import math
input = sys.stdin.readline
N,M = map(int,input().split())
ladder = [0]*101
snake = [0]*101
for _ in range(N) :
    x,y = map(int,input().split())
    ladder[x] = y
for _ in range(M) :
    u,v = map(int,input().split())
    snake[u] = v

# DFS 
memo = [math.inf]*101
def dfs(x,turn) :
    if x > 100 :
        return
    else :
        if memo[x] <= turn :
            return
        else :
            memo[x] = turn
            if x == 100 :
                return
            if ladder[x] != 0 :
                dfs(ladder[x],turn)
            elif snake[x] != 0 :
                dfs(snake[x],turn)
            else :
                for i in range(1,7) :
                    dfs(x+i,turn+1)
dfs(1,0)
print(memo[100])

