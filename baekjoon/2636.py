# 치즈
# 너비 우선 탐색 & 시뮬레이션

import sys
from collections import deque
input = sys.stdin.readline
dx = [1,-1,0,0]
dy = [0,0,1,-1]
N,M = map(int,input().split())
world = []
for _ in range(N) :
    world.append(list(map(int,input().split())))
contect = deque()
cheese = 0
for i in range(N) :
    for j in range(M) :
        if world[i][j] == 1 :
            cheese += 1
def bfs(node) :
    q = deque([[node[0],node[1]]])
    world[node[0]][node[1]] = 2
    while len(q) :
        x,y = q.popleft()
        isContect = False
        for d in range(4) :
            newX = x + dx[d]
            newY = y + dy[d]
            if 0<=newX<N and 0<=newY<M :
                if world[newX][newY] == 0:
                    q.append([newX,newY])
                    world[newX][newY] = 2
                elif world[newX][newY] == 1:
                    isContect = True
        if isContect :
            contect.append([x,y])
bfs([0,0])
ans = 0
prev = cheese
while cheese :
    prev = cheese
    ans += 1;
    copy = deque()
    for i in range(len(contect)) :
        copy.append(contect.popleft())
    while len(copy) :
        x,y = copy.popleft()
        for d in range(4) :
            newX = x + dx[d]
            newY = y + dy[d]
            if 0<=newX<N and 0<=newY<M :
                if world[newX][newY] == 1:
                    world[newX][newY] = 2
                    cheese -= 1
                    bfs([newX,newY])
print(ans)
print(prev)