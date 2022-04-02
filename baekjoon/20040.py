# 사이클 게임
# 분리 집합

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)
n,m = map(int,input().split())
parent = [0]*n
for i in range(n) :
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
    if x == y :
        return 1
    else :
        if x < y :
            parent[y] = x
        else :
            parent[x] = y
isDone = False
for i in range(m) :
    a,b = map(int,input().split())
    if union(a,b) and not isDone :
        print(i+1)
        isDone = True
if not isDone :
    print(0)