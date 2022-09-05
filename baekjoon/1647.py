# 도시 분할 계획
# 최소 스패닝 트리

# 크루스칼 알고리즘

import sys
input = sys.stdin.readline
N, M = map(int,input().split())
line = []
for _ in range(M) :
    a,b,c = map(int,input().split())
    line.append([c,a,b])

line.sort() # cost 순으로 정렬

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
        # 둘이 같은 그룹이 아니라면, 묶어줌
        union(x,y)
        roadNum += 1
        ans += c
    if roadNum == N-2 :
        # 길의 수가 N-2(마을을 두개로 나눴을 때 최대 길의 수)이면 멈춤
        # 더 이상 볼 필요가 없음
        break
print(ans)