# 사이클 게임
# 분리 집합

# 이미 같은 그룹에 있는 노드 두개를 선택하면 사이클이 생김
# 이를 판별해주는 프로그램

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
for i in range(1,m+1) :
    a,b = map(int,input().split())
    if union(a,b) :
        print(i)
        isDone = True
        break
if not isDone :
    print(0)