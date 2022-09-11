# 이분 그래프
# 너비 우선 탐색 & 이분 그래프

from collections import deque
import sys
input = sys.stdin.readline

def bfs(start) :
    graph[start] = 1
    queue = deque([start])
    while len(queue) :
        i = queue.popleft()
        for j in line[i] :
            if graph[j] == 0 :
                graph[j] = -graph[i]
                queue.append(j)
            else :
                if graph[i] == graph[j] :
                    return False
    return True

K = int(input())

for _ in range(K) :
    V,E = map(int,input().split())
    line = [[] for _ in range(V+1)]
    graph = [0]*(V+1)
    for _ in range(E) :
        x,y = map(int,input().split())
        line[x].append(y)
        line[y].append(x)
    isBG = True
    for i in range(1,V+1) :
        if graph[i] == 0 :
            if not bfs(i) :
                isBG = False
                break
    if isBG :
        print('YES')
    else :
        print('NO')