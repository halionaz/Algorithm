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

# 전체 간선을 모두 정리하기엔 시간적 비용이 너무 많이 드므로,
# 각 좌표에 대한 정렬을 통해 의미없는 간선(자명한 최솟값이 다른 행성을 경유했을 때, 나오는 경우)를 제외함

# 예를 들어 x좌표를 기준으로 정렬했을 때, (A, B, C) 순이라면
# A-C를 x좌표 기준으로 생각한 간선은 의미가 없음

for j in range(3):

    # 각각 x좌표, y좌표, z좌표로 차례대로 정렬해봄
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