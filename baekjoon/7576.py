# 토마토
# 너비 우선 탐색

import sys
from collections import deque
input = sys.stdin.readline
M,N = map(int,input().split())
inven = [list(map(int,input().split())) for _ in range(N)]
queue = deque([])
for i in range(N) :
    for j in range(M) :
        if inven[i][j] == 1:
            queue.append((i,j))
while len(queue) > 0 :
    y,x = queue.popleft()
    plus = inven[y][x] + 1
    if y+1 < N and inven[y+1][x] == 0 :
        inven[y+1][x] += plus
        queue.append((y+1,x))
    if y-1 >= 0 and inven[y-1][x] == 0 :
        inven[y-1][x] += plus
        queue.append((y-1,x))
    if x+1 < M and inven[y][x+1] == 0:
        inven[y][x+1] += plus
        queue.append((y,x+1))
    if x-1 >= 0 and inven[y][x-1] == 0:
        inven[y][x-1] += plus
        queue.append((y,x-1))
isDone = True
ans = -2
for i in inven :
    for j in i :
        if j == 0 :
            isDone = False
            break
        ans = max(ans,j)
if isDone :
    if ans == 1 :
        print(0)
    else :
        print(ans-1)
else :
    print(-1)

