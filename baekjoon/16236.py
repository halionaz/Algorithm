# 아기 상어 
# 시뮬레이션 & 그래프 탐색

import sys
import copy
from collections import deque
dx = [-1,0,1,0]
dy = [0,-1,0,1]
input = sys.stdin.readline
N = int(input())
space = []
for _ in range(N) :
    space.append(list(map(int,input().split())))
fishNum = 0
ans = 0
cur = []
for i in range(N) :
    for j in range(N) :
        if space[i][j] == 9 :
            cur = [i,j,0]
            space[i][j] = 0
        elif space[i][j] :
            fishNum += 1
sharkSize = 2
eatCount = 0
while fishNum :
    queue = deque()
    queue.append(cur)
    copySpace = copy.deepcopy(space)
    copySpace[cur[0]][cur[1]] = sharkSize + 10
    doneList = []
    doneDist = 0
    while len(queue) :
        i,j,d = queue.popleft()
        if doneList and doneDist < d+1 :
            break
        for k in range(4) :
            newX = i + dx[k]
            newY = j + dy[k]
            if 0<=newX<N and 0<=newY<N :
                if 0 < copySpace[newX][newY] < sharkSize :
                    doneList.append([newX,newY])
                    copySpace[newX][newY] = sharkSize + 10
                    if not doneDist :
                        doneDist = d+1
                elif copySpace[newX][newY] > sharkSize :
                    continue
                else :
                    copySpace[newX][newY] = sharkSize + 10
                    queue.append([newX,newY,d+1])
    if doneList :
        doneList.sort()
        i,j = doneList[0]
        space[i][j] = 0
        fishNum -= 1
        ans += doneDist
        eatCount += 1
        if eatCount == sharkSize :
            sharkSize += 1
            eatCount = 0
        cur = [i,j,0]
    else :
        break
print(ans)
