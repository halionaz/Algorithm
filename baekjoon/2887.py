# 행성 터널
# 정렬 & 최소 스패닝 트리

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)
N = int(input())
location = []
for i in range(N) :
    location.append(list(map(int,input().split()))+[i])
cost = []
for j in range(3):
    location.sort(key=lambda x:x[j])
    before = location[0][3]
    for i in range(1,N) :
        current = location[i][3]
        cost.append([abs(location[i][j]-location[i-1][j]),before,current])
        before = current
cost.sort()
parent = [0]*N
for i in range(N) :
    parent[i] = i
def findParent(x) :
    if parent[x] == x :
        return x
    else :
        parent[x] = findParent(parent[x])
        return parent[x]
def union(a,b) :
    x = findParent(a)
    y = findParent(b)
    if x != y :
        if x<y :
            parent[y] = x
        else :
            parent[x] = y
ans = 0
for c,i,j in cost :
    if findParent(i) != findParent(j) :
        union(i,j)
        ans += c
print(ans)