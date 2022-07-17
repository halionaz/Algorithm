# 거짓말
# 분리 집합

import sys
input = sys.stdin.readline
N,M = map(int,input().split())
T = list(map(int,input().split()))
parent = [0]*(N+1)
for i in range(N+1) :
    parent[i] = i
def findParent(x) :
    if x == parent[x] :
        return x
    else :
        parent[x] = findParent(parent[x])
        return parent[x]
def union(a,b) :
    x = findParent(a)
    y = findParent(b)
    if x != y :
        if x < y :
            parent[y] = x
        else :
            parent[x] = y 
P = []
for _ in range(M) :
    p = list(map(int,input().split()))
    P.append(p[1:])
    if p[0] == 1 :
        continue
    for i in range(p[0]-1) :
        # 같은 파티로 묶여있는 사람들 union 시키기
        union(p[1+i],p[2+i])
if T[0] == 0 :
    # 진실을 아는 사람이 없으므로, 모든 파티에서 거짓말 가능
    print(M)
elif T[0] == 1:
    ans = 0
    for i in P :
        if findParent(i[0]) != findParent(T[1]) :
            ans += 1
    print(ans)
else :
    for i in range(T[0]-1) :
        union(T[1+i],T[2+i])
    ans = 0
    for i in P :
        if findParent(i[0]) != findParent(T[1]) :
            ans+=1
    print(ans)