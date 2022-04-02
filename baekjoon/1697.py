# 숨바꼭질
# 너비 우선 탐색

from collections import deque
N,K = map(int,input().split())
world = [0]*100001
world[N] = 1
queue = deque([N])
while len(queue) > 0 :
    x = queue.popleft()
    if x-1 == K or x+1 == K or x*2 == K :
        break
    if x-1 > -1 and world[x-1] == 0:
        queue.append(x-1)
        world[x-1] += world[x]+1
    if x*2 < 100001 and world[x*2] == 0:
        queue.append(x*2)
        world[x*2] += world[x]+1
    if x+1 < 100001 and world[x+1] == 0:
        queue.append(x+1)
        world[x+1] += world[x]+1
if N == K :
    print(0)
else :
    print(world[x])