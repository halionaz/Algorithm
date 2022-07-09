# 숨바꼭질 3
# 너비 우선 탐색 & 0-1 너비 우선 탐색 & 데이크스트라

from queue import PriorityQueue
N,K = map(int,input().split())
world = [1]*100001
world[N] = 0
queue = PriorityQueue()
queue.put((0,N))
while queue :
    y,x = queue.get()
    if x == K :
        break
    if x*2 < 100001 and world[x*2]:
        queue.put((y,x*2))
        world[x*2] = 0
    if x-1 > -1 and world[x-1]:
        queue.put((y+1,x-1))
        world[x-1] = 0
    if x+1 < 100001 and world[x+1]:
        queue.put((y+1,x+1))
        world[x+1] = 0
print(y)