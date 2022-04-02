# 회전하는 큐
# 덱

from collections import deque
N,M = map(int,input().split())
arr = list(map(int,input().split()))
q = deque([])
for i in range(1,N+1) : q.append(i)
ans = 0
for i in arr :
    if q[0] == i :
        q.popleft()
    else :
        countLeft = countRight = 1
        while q[countLeft] != i and q[-countRight] != i :
            countRight += 1
            countLeft += 1
        if q[countLeft] == i :
            while q[0] != i :
                q.append(q.popleft())
                ans += 1
            q.popleft()
        else :
            while q[0] != i :
                q.appendleft(q.pop())
                ans += 1
            q.popleft()
print(ans)