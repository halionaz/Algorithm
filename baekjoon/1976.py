# 여행 가자
# 분리 집합

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)
N = int(input())
M = int(input())
parents = [0]*N
for i in range(N) :
    parents[i] = i
def find(x) :
    if x == parents[x] :
        return x
    else :
        parents[x] = find(parents[x])
        return parents[x]
def union(a,b) :
    x = find(a)
    y = find(b)
    if x != y :
        if x<y :
            parents[y] = x
        else :
            parents[x] = y
for i in range(N) :
    line = list(map(int,input().split()))
    for j in range(N) :
        if line[j] :
            union(i,j)
plan = list(map(int,input().split()))
canTravel = True
for i in range(1,M) :
    if find(plan[i-1]-1) != find(plan[i]-1) :
        canTravel = False
        break
print('YES' if canTravel else 'NO')