# 치즈
# 너비 우선 탐색 & 시뮬레이션

import sys
from collections import deque
input = sys.stdin.readline
dx = [1,-1,0,0]
dy = [0,0,1,-1]
N,M = map(int,input().split())
mapping = []
for _ in range(N) :
    mapping.append(list(map(int,input().split())))
contect = deque()
cheese = 0
world = [[[0]*2 for _ in range(M)] for _ in range(N)]
for i in range(N) :
    for j in range(M) :
        if mapping[i][j] == 1 :
            cheese += 1
        world[i][j] = [mapping[i][j],0] # 두번째 요소는 현재 이 요소가 맞닿고 있는 공기 개수
def bfs(node) :
    q = deque([[node[0],node[1]]])
    world[node[0]][node[1]][0] = 2
    while len(q) :
        x,y = q.popleft()
        isContect = False
        for d in range(4) :
            newX = x + dx[d]
            newY = y + dy[d]
            if 0<=newX<N and 0<=newY<M :
                if world[newX][newY][0] == 0:
                    q.append([newX,newY])
                    world[newX][newY][0] = 2
                elif world[newX][newY][0] == 1:
                    isContect = True
        if isContect :
            contect.append([x,y])
bfs([0,0])
ans = 0
while cheese :
    ans += 1
    copy = deque()
    for i in range(len(contect)) :
        copy.append(contect.popleft())
    while len(copy) :
        x,y = copy.popleft()
        for d in range(4) :
            newX = x + dx[d]
            newY = y + dy[d]
            if 0 <= newX < N and 0 <= newY < M :
                if world[newX][newY][0] == 1:
                    if world[newX][newY][1] > 0 : # 이미 공기층과 맞닿은 치즈인 경우
                        world[newX][newY][0] = 2
                        cheese -= 1
                        bfs([newX,newY])
                    else : 
                        world[newX][newY][1] += 1
print(ans)