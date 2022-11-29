# 트리
# 트리 & 그래프 탐색 & 너비 우선 탐색

import sys
from collections import deque
input= sys.stdin.readline
def bfs(start) :
    queue = deque([])
    queue.append((start,0))
    while len(queue) :
        x,parent = queue.popleft()
        visited[x] = 1
        for i in line[x] :
            if i != parent :
                if visited[i] :
                    # i 노드는 x 노드의 부모가 아니지만 이미 방문했음
                    # 즉 이 그래프는 트리가 아님
                    return False
                else :
                    queue.append((i,x))
    return True
ind = 1
while True :
    T = 0
    n,m = map(int,input().split())
    if n == 0 and m == 0 :
        # 문제 끝내기
        break
    line = [[] for _ in range(n+1)]
    for _ in range(m) :
        a,b = map(int,input().split())
        line[a].append(b)
        line[b].append(a)
    visited = [0]*(n+1)
    for j in range(1,n+1) :
        if not visited[j] :
            if bfs(j) :
                # 너비 우선 탐색을 통해 j번째 노드에서 시작한 그래프가 트리인지 판별
                T += 1
    print('Case {}:'.format(ind),end=' ')
    if T == 1:
        print('There is one tree.')
    elif T :
        print('A forest of {} trees.'.format(T))
    else :
        print('No trees.')
    ind+=1