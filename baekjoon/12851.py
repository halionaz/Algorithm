# 숨바꼭질 2
# 너비 우선 탐색

from collections import deque
N,K = map(int,input().split())
world = [0]*100001
world[N] = 1
minimum = 0
ans = 0
queue = deque([[N,0]])
while len(queue) :
    pos,time = queue.popleft()
    world[pos] = 1
    if minimum and pos == K and minimum == time :
        # 답이 한번 더 나왔으므로, 답 개수에 추가
        ans += 1
    if not minimum and pos == K :
        # 첫 답
        ans += 1
        minimum = time
    if pos-1 > -1 and world[pos-1] == 0:
        queue.append([pos-1,time+1])
    if pos*2 < 100001 and world[pos*2] == 0:
        # 순간이동
        queue.append([pos*2,time+1])
    if pos+1 < 100001 and world[pos+1] == 0:
        queue.append([pos+1,time+1])
print(minimum)
print(ans)