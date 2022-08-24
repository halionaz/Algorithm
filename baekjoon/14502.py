# 연구소
# 브루트포스 알고리즘 & 너비 우선 탐색

import sys
from collections import deque
input = sys.stdin.readline
N,M = map(int,input().split())
lab = []
for _ in range(N) :
    lab.append(list(map(int,input().split())))
dx = [1,0,0,-1]
dy = [0,-1,1,0]
ans = 0
def bfs() :
    # 안전지대 체크
    global ans
    AS = [[0]*M for _ in range(N)]
    queue = deque([])
    for i in range(N) :
        for j in range(M) :
            AS[i][j] = temp[i][j]
            if AS[i][j] == 2 :
                queue.append([i,j])
    while len(queue) :
        x,y = queue.popleft()
        for d in range(4) :
            newX = x+dx[d]
            newY = y+dy[d]
            if 0<=newX<N and 0<=newY<M :
                if AS[newX][newY] == 0 :
                    queue.append([newX,newY])
                    AS[newX][newY] = 2
    clean = 0
    for i in range(N) :
        for j in range(M) :
            if AS[i][j] == 0 :
                clean += 1
    ans = max(ans,clean)
def makeWall(num,sx,sy) :
    if num == 3 :
        bfs()
        return
    else :
        for i in range(N) :
            for j in range(M) :
                if not(i < sx and j < sy) and temp[i][j] == 0 :
                    temp[i][j] = 1
                    makeWall(num+1,i,j)
                    temp[i][j] = 0
temp = [[0]*M for _ in range(N)]
for i in range(N) :
    for j in range(M) :
        if lab[i][j] == 0 :
            for x in range(N) :
                for y in range(M) :
                    temp[x][y] = lab[x][y]
            temp[i][j] = 1
            makeWall(1,i,j)
print(ans)