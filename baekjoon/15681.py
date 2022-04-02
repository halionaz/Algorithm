# 트리와 쿼리
# 트리

import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
N,R,Q = map(int,input().split())
line = [[] for _ in range(N+1)]
for _ in range(N-1) :
    U,V = map(int,input().split())
    line[U].append(V)
    line[V].append(U)
children = [[] for _ in range(N+1)]
size = [0]*(N+1)
def makeTree(cur,parent) :
    for node in line[cur] :
        if node != parent :
            children[cur].append(node)
            makeTree(node,cur)
def cntSubNodes(cur) :
    size[cur] = 1
    for node in children[cur] :
        cntSubNodes(node)
        size[cur] += size[node]
makeTree(R,0)
cntSubNodes(R)
for _ in range(Q) :
    print(size[int(input())])