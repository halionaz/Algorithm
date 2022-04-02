# 요세푸스 문제 0
# 큐

from collections import deque
N,K = map(int,input().split())
q = deque([])
for i in range(1,N+1) : q.append(i)
ans = []
turn = 1
while len(q) != 0 :
    if turn == K :
        turn = 1
        ans.append(q.popleft())
    else :
        turn += 1
        q.append(q.popleft())
print('<'+', '.join(map(str,ans))+'>')