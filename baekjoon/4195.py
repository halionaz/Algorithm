# 친구 네트워크
# 분리 집합 & 해시를 사용한 집합과 맵
# 집합과 맵

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)
T = int(input())
def find(x) :
    if parents[x] == x :
        return x
    else :
        parents[x] = find(parents[x])
        return parents[x]
def union(a,b) :
    x = find(a)
    y = find(b)
    if x != y :
        if len(x) < len(y) :
            parents[y] = x
            cnt[x] += cnt[y]
        else :
            parents[x] = y
            cnt[y] += cnt[x]
for _ in range(T) :
    F = int(input())
    parents = {}
    cnt = {}
    for _ in range(F) :
        A,B = input().rstrip().split()
        if A not in parents :
            parents[A] = A
            cnt[A] = 1
        if B not in parents :
            parents[B] = B
            cnt[B] = 1
        union(A,B)
        print(cnt[find(A)])