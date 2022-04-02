# 최소 스패닝 트리
# 최소 스패닝 트리 & 분리 집합

# 최소 신장 트리를 처음으로 사용하는 문제
# 크루스칼 알고리즘 (유니온 파인드 이용), 그리디한 방법
# 간선 비용순으로 정렬한 후, 모든 라인을 선회하며, 
# 같은 집합에 들어있지 않으면 비용에 추가

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)
V,E = map(int,input().split())
parent = [0]*10001
for i in range(10001) :
    parent[i] = i
line = []
for _ in range(E) :
    a,b,c = map(int,input().split())
    line.append((c,a,b))
line.sort()
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
for c,a,b in line :
    if findParent(a) != findParent(b) :
        union(a,b)
        ans += c
print(ans)