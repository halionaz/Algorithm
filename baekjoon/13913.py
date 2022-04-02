# 숨바꼭질 4
# 너비 우선 탐색

from collections import deque
N,K = map(int,input().split())
world = [[0,-1] for _ in range(100001)]
world[N] = [1,-1]
queue = deque([N])
while len(queue) :
    x = queue.popleft()
    if x-1 == K or x+1 == K or x*2 == K :
        break
    if x-1 > -1 and world[x-1][0] == 0:
        queue.append(x-1)
        world[x-1] = [world[x][0]+1,x]
    if x*2 < 100001 and world[x*2][0] == 0:
        queue.append(x*2)
        world[x*2] = [world[x][0]+1,x]
    if x+1 < 100001 and world[x+1][0] == 0:
        queue.append(x+1)
        world[x+1] = [world[x][0]+1,x]
if N == K :
    print(0)
    print(K)
else :
    print(world[x][0])
    ans = [K]
    i = x
    while True :
        if i == -1 :
            break
        ans.append(i)
        i = world[i][1]
    ans.reverse()
    print(*ans)