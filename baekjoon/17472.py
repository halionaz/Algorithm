# 다리 만들기 2
# 브루트포스 알고리즘 & 최소 스패닝 트리 & 너비 우선 탐색
# 크루스칼 알고리즘

import sys
import math
from collections import deque
sys.setrecursionlimit(10**6)

input = sys.stdin.readline
dx = [1,-1,0,0]
dy = [0,0,1,-1]
N,M = map(int,input().split())
world = [list(map(int,input().split())) for _ in range(N)]

def BFS(i,j,cnt) :
    queue = deque([[i,j]])
    world[i][j] = cnt
    while len(queue) :
        x,y = queue.popleft()
        for k in range(4):
            newX = x+dx[k]
            newY = y+dy[k]
            if 0<=newX<N and 0<=newY<M and world[newX][newY]==1:
                world[newX][newY] = cnt
                queue.append([newX,newY])

# 섬 index
cnt = 2

# BFS로 섬 개수 세기
for i in range(N) :
    for j in range(M) :
        if world[i][j] == 1:
            BFS(i,j,cnt)
            cnt += 1

#2~cnt-1 섬 번호
line = [[math.inf]*cnt for _ in range(cnt)]

# 섬을 잇는 다리 후보들 탐색
for i in range(N) :
    for j in range(M) :
        if world[i][j] :
            startContinent = world[i][j]
            endContinent = 1

            #왼쪽
            bridge = False
            endpos = -1
            for x in range(j) :
                if j-x-1 <0 :
                    break
                if not bridge and world[i][j-x-1]==0 :
                    bridge = True
                    startPos = j-x-1
                if bridge and world[i][j-x-1] :
                    endpos = j-x-1
                    endContinent = world[i][j-x-1]
                    break
            if bridge and endpos != -1:
                length = min(line[startContinent][endContinent],startPos-endpos)
                if length != 1 : 
                    line[startContinent][endContinent] = length
                    line[endContinent][startContinent] = length
            #오른쪽
            bridge = False
            endpos = -1
            for x in range(M-j-1) :
                if j+x+1 >= M :
                    break
                if not bridge and world[i][j+x+1]==0:
                    bridge = True
                    startPos = j+x+1
                if bridge and world[i][j+x+1] :
                    endpos = j+x+1
                    endContinent = world[i][j+x+1]
                    break
            if bridge and endpos != -1:
                length = min(line[startContinent][endContinent],endpos-startPos)
                if length != 1 : 
                    line[startContinent][endContinent] = length
                    line[endContinent][startContinent] = length
            #위쪽
            bridge = False
            endpos = -1
            for x in range(i) :
                if i-x-1 < 0 :
                    break
                if not bridge and world[i-x-1][j] == 0:
                    bridge = True
                    startPos = i-x-1
                if bridge and world[i-x-1][j] :
                    endpos = i-x-1
                    endContinent = world[i-x-1][j]
                    break
            if bridge and endpos != -1:
                length = min(line[startContinent][endContinent],startPos-endpos)
                if length != 1 : 
                    line[startContinent][endContinent] = length
                    line[endContinent][startContinent] = length
            #아래쪽
            bridge = False
            endpos = -1
            for x in range(N-i-1) :
                if i+x+1 >= N :
                    break
                if not bridge and world[i+x+1][j] == 0:
                    bridge = True
                    startPos = i+x+1
                if bridge and world[i+x+1][j] :
                    endpos = i+x+1
                    endContinent = world[i+x+1][j]
                    break
            if bridge and endpos != -1:
                length = min(line[startContinent][endContinent],endpos-startPos)
                if length != 1 : 
                    line[startContinent][endContinent] = length
                    line[endContinent][startContinent] = length

# 간선 길이 순서대로 다리 후보들 정렬
bridge = []
for i in range(2,cnt-1) :
    for j in range(i+1,cnt) :
        if line[i][j] != math.inf :
            bridge.append([line[i][j],i-2,j-2])
bridge.sort()

# 크루스칼 알고리즘을 통한 최소 스패닝 트리 계산
parent = [0]*(cnt-2)
for i in range(cnt-2) :
    parent[i] = i
def findParent(x) :
    if parent[x] == x :
        return x
    else :
        parent[x] = findParent(parent[x])
        return parent[x]
def union(a,b) :
    x = parent[a]
    y = parent[b]
    if x != y :
        if x<y :
            parent[y] = x
        else :
            parent[x] = y
ans = 0
for d,a,b in bridge :
    if findParent(a) != findParent(b) :
        ans += d
        union(a,b)
isDone = True
for i in range(cnt-2) :
    if findParent(0) != findParent(i) :
        isDone = False
        break
if isDone :
    print(ans)
else :
    print(-1)