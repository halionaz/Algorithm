# 카드2
# 큐

from collections import deque
N = int(input())
queue = deque([])
if N == 1:
    print(1)
else :
    for i in range(2,N+1) : queue.append(i)
    while len(queue) != 1 :
        queue.append(queue.popleft())
        queue.popleft()
    print(queue[0])