# 텀 프로젝트
# 깊이 우선 탐색

import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
T = int(input())
def dfs(x) :
    global result
    visited[x] = 1
    cycle.append(x)
    next = point[x]
    if visited[next] :
        if next in cycle :
            result += cycle[cycle.index(next):]
        return
    else :
        dfs(next)
for _ in range(T) :
    n = int(input())
    point = [0] + list(map(int,input().split()))
    visited = [0]*(n+1)
    result = []
    for i in range(1,n+1) :
        if not visited[i] :
            cycle = []
            dfs(i)
    print(n-len(result))

# import sys
# sys.setrecursionlimit(10**6)
# input = sys.stdin.readline
# T = int(input())
# temp = 0
# def dfs(x,origin) :
#     global temp,cur
#     if x == origin :
#         visited[x] = cur
#     if select[x] == origin :
#         return True
#     else :
#         if visited[select[x]] :
#             if visited[select[x]] == cur :
#                 temp = select[x]
#             else :
#                 visited[x] = 0
#             return False
#         else : 
#             visited[select[x]] = cur
#             if not dfs(select[x],origin) :
#                 if temp :
#                     if x == temp :
#                         temp = 0
#                         cur += 1
#                 else :
#                     visited[x] = 0
#                 return False
#             else :
#                 return True
# for _ in range(T) :
#     n = int(input())
#     select = [-1] + list(map(int,input().split()))
#     visited = [0]*(n+1)
#     ans = 0
#     cur = 1
#     for i in range(1,n+1) :
#         if not visited[i] :
#             if not dfs(i,i) :
#                 ans += 1
#             else :
#                 cur += 1
#     print(ans)
