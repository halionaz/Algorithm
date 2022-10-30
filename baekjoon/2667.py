# 단지번호붙이기 
# 너비 우선 탐색 & 깊이 우선 탐색

import sys
input = sys.stdin.readline
N = int(input())
world = [list(map(int,input().rstrip())) for _ in range(N)]
num = [[2,0]]

# DFS
# def dfs(i,j) :
#     world[i][j] = num[-1][0]
#     num[-1][1] += 1
#     if i+1 < N and 0<world[i+1][j] < num[-1][0] :
#         dfs(i+1,j)
#     if i-1 >= 0 and 0<world[i-1][j] < num[-1][0] :
#         dfs(i-1,j)
#     if j+1 < N and 0<world[i][j+1] <num[-1][0] :
#         dfs(i,j+1)
#     if j-1 >= 0 and 0<world[i][j-1] <num[-1][0] :
#         dfs(i,j-1)
# for i in range(N) :
#     for j in range(N):
#         if world[i][j] == 1 :
#             dfs(i,j)
#             num.append([num[-1][0]+1,0])
# num = sorted(num,key=lambda l:l[1])[1:]
# print(len(num))
# for i in num :
#     print(i[1])

# BFS
def bfs(i,j) :
    queue = [(i,j)]
    world[i][j] = num[-1][0]
    num[-1][1] += 1
    while len(queue) > 0 :
        (x,y) = queue.pop(0)
        if x+1 < N and 0<world[x+1][y] < num[-1][0] :
            queue.append((x+1,y))
            world[x+1][y] = num[-1][0]
            num[-1][1] += 1
        if x-1 >= 0 and 0<world[x-1][y] < num[-1][0] :
            queue.append((x-1,y))
            world[x-1][y] = num[-1][0]
            num[-1][1] += 1
        if y+1 < N and 0<world[x][y+1] <num[-1][0] :
            queue.append((x,y+1))
            world[x][y+1] = num[-1][0]
            num[-1][1] += 1
        if y-1 >= 0 and 0<world[x][y-1] <num[-1][0] :
            queue.append((x,y-1))
            world[x][y-1] = num[-1][0]
            num[-1][1] += 1
for i in range(N) :
    for j in range(N):
        if world[i][j] == 1 :
            bfs(i,j)
            num.append([num[-1][0]+1,0])

num = sorted(num,key=lambda l:l[1])[1:]

print(len(num))
for i in num :
    print(i[1])