# 별자리 만들기
# 최소 스패닝 트리

# 크루스칼 알고리즘
import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
n = int(input())
location = []
for _ in range(n) :
    location.append(tuple(map(float,input().split())))
line = []
for i in range(n-1) :
    for j in range(i+1,n) :
        dist = ((location[i][0]-location[j][0])**2+(location[i][1]-location[j][1])**2)**0.5
        line.append((dist,i,j))
line.sort()
parent = [0]*n
for i in range(n):
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
ans = 0
for d,a,b in line :
    if findParent(a) != findParent(b) :
        union(a,b)
        ans += d
print(ans)

# 프림 알고리즘
# import sys
# INF = 9999999999999
# input = sys.stdin.readline
# n = int(input())
# location = []
# for _ in range(n) :
#     location.append(tuple(map(float,input().split())))
# line = [[] for _ in range(n)]
# for i in range(n-1) :
#     for j in range(i+1,n) :
#         dist = ((location[i][0]-location[j][0])**2+(location[i][1]-location[j][1])**2)**0.5
#         line[i].append((dist,j))
#         line[j].append((dist,i))
# node = [0]
# ans = 0
# while len(node) != n :
#     minimumDist = INF
#     minimumInd = -1
#     for i in node :
#         for dist,j in line[i] :
#             if j not in node :
#                 if dist < minimumDist :
#                     minimumInd = j
#                     minimumDist = dist
#     node.append(minimumInd)
#     ans += minimumDist
# print(ans)