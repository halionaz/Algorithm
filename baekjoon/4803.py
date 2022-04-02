# 트리
# 트리 & 그래프 탐색 

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
                    return False
                else :
                    queue.append((i,x))
    return True
ind = 1
while True :
    T = 0
    n,m = map(int,input().split())
    if n == 0 and m == 0 :
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
                T += 1
    print('Case {}:'.format(ind),end=' ')
    if T == 1:
        print('There is one tree.')
    elif T :
        print('A forest of {} trees.'.format(T))
    else :
        print('No trees.')
    ind+=1