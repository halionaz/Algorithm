# 토마토
# 너비 우선 탐색

import sys
from collections import deque
input = sys.stdin.readline
def main():
    M,N,H = map(int,input().split())
    inven = [] # 3차원 배열
    vx = (1,-1,0,0,0,0)
    vy = (0,0,1,-1,0,0)
    vz = (0,0,0,0,1,-1)
    for _ in range(H) :
        arr = []
        for _ in range(N) :
            arr.append(list(map(int,input().split())))
        inven.append(arr)
    queue = deque([])

    # 처음에 익은 토마토가 자리한 위치 저장
    for i in range(H) :
        for j in range(N) :
            for l in range(M) :
                if inven[i][j][l] == 1:
                    queue.append((i,j,l))
    
    while len(queue) > 0 :
        z, y, x = queue.popleft()
        for i in range(6) :
            newZ = z+vz[i]
            newY = y+vy[i]
            newX = x+vx[i]
            if 0<=newZ<H and 0<=newY<N and 0<=newX<M and inven[newZ][newY][newX] == 0 :
                queue.append((newZ,newY,newX))
                inven[newZ][newY][newX] += inven[z][y][x] + 1
    isDone = True
    ans = -2
    for i in inven :
        for j in i :
            for l in j :
                if l == 0 :
                    isDone = False
                    break
                else :
                    ans = max(ans,l)
    if isDone :
        if ans == 1 :
            print(0)
        else :
            print(ans-1)
    else :
        print(-1)
main()