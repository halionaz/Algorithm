# 적록색약
# 너비 우선 탐색

import sys
from collections import deque
input = sys.stdin.readline
di = [1,0,-1,0]
dj = [0,1,0,-1]
N = int(input())
paint = []
visited = [[0]*N for _ in range(N)]
def bfs(x,y,color) :
    q = deque()
    q.append([x,y])
    visited[x][y] = 1
    while q :
        i,j = q.popleft()
        for d in range(4) :
            newI = i + di[d]
            newJ = j + dj[d]
            if 0<=newI<N and 0<=newJ<N :
                if not visited[newI][newJ] and paint[newI][newJ] == color :
                    visited[newI][newJ] = 1
                    q.append([newI,newJ])
for i in range(N) :
    paint.append(list(input().rstrip()))
norAns = ans = 0
for i in range(N) :
    for j in range(N) :
        if not visited[i][j] :
            norAns += 1
            bfs(i,j,paint[i][j])
        if paint[i][j] == 'G' :
            paint[i][j] = 'R'
visited = [[0]*N for _ in range(N)]
for i in range(N) :
    for j in range(N) :
        if not visited[i][j] :
            ans += 1
            bfs(i,j,paint[i][j])
print(norAns,ans)
            