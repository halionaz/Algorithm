# 숨바꼭질 2
# 너비 우선 탐색

from collections import deque
N,K = map(int,input().split())
world = [0]*100001
world[N] = 1
min = 0
ans = 0
queue = deque([[N,0]])
while len(queue) :
    pos,time = queue.popleft()
    world[pos] = 1
    if min and pos == K and min == time :
        ans += 1
    if not min and pos == K :
        ans += 1
        min = time
    if pos-1 > -1 and world[pos-1] == 0:
        queue.append([pos-1,time+1])
    if pos*2 < 100001 and world[pos*2] == 0:
        queue.append([pos*2,time+1])
    if pos+1 < 100001 and world[pos+1] == 0:
        queue.append([pos+1,time+1])
print(min)
print(ans)