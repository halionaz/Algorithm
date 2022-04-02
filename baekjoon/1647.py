# 도시 분할 계획
# 최소 스패닝 트리

import sys
input = sys.stdin.readline
N, M = map(int,input().split())
line = []
for _ in range(M) :
    a,b,c = map(int,input().split())
    line.append([c,a,b])
line.sort()
parent = [0]*(N+1)
for i in range(N+1) :
    parent[i] = i
def findParent(x) :
    if parent[x] == x :
        return x
    else :
        parent[x] = findParent(parent[x])
        return parent[x]
def union(a,b) :
    x = parent[a]
    y = parent[b]
    if x != y :
        if x < y :
            parent[y] = x
        else :
            parent[x] = y
ans = 0
roadNum = 0
for i in range(M-1) :
    c,x,y = line[i]
    if findParent(x) != findParent(y) :
        union(x,y)
        roadNum += 1
        ans += c
    if roadNum == N-2 :
        break
print(ans)