# 우주신과의 교감
# 최소 스패닝 트리

#크루스칼 알고리즘
import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
N,M = map(int,input().split())
location = []
for _ in range(N) :
    location.append(list(map(int,input().split())))
parent = [0]*N
for i in range(N):
    parent[i] = i
def findParent(x) :
    if parent[x] == x :
        return x
    else :
        parent[x] = findParent(parent[x])
        return parent[x]
def union(a,b):
    x = findParent(a)
    y = findParent(b)
    if x != y :
        if x < y :
            parent[y] = x
        else :
            parent[x] = y
for _ in range(M) :
    a,b = map(int,input().split())
    if findParent(a-1) != findParent(b-1) :
        union(a-1,b-1)
line = []
for i in range(N-1) :
    for j in range(i+1,N) :
        dist = ((location[i][0]-location[j][0])**2+(location[i][1]-location[j][1])**2)**0.5
        line.append([dist,i,j])
line.sort()
ans = 0
for d,a,b in line :
    if findParent(a) != findParent(b) :
        union(a,b)
        ans += d
print(format(ans,".2f"))