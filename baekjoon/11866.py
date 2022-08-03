# 요세푸스 문제 0
# 큐

from collections import deque
N,K = map(int,input().split())
q = deque([])
for i in range(1,N+1) : 
    q.append(i)
ans = []
turn = 1
# deque를 이용해 임의의 원형 배열을 구현함
# q의 가장 왼쪽 요소를 가장 오른쪽에 추가함으로써 순서가 돌아가는걸 구현,
# 순서가 k에 도달하면 ans에 추가하고 q에선 뺌
while len(q) != 0 :
    if turn == K :
        turn = 1
        ans.append(q.popleft())
    else :
        turn += 1
        q.append(q.popleft())
print('<'+', '.join(map(str,ans))+'>')