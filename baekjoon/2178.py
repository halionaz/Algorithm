# 미로 탐색
# 너비 우선 탐색

# 최단경로 탐색이므로 DFS보다 BFS가 효율적임

import sys
input = sys.stdin.readline
N,M = map(int,input().split())
maze = []
for i in range(N) :
    maze.append(list(map(int,input().rstrip())))
queue = [(0,0)]
maze[0][0] = 2
while len(queue) > 0 :
    i,j = queue.pop(0)
    plus = maze[i][j]
    if i == N-1 and j == M-1 :
        break
    if i+1 < N and maze[i+1][j] == 1:
        maze[i+1][j] += plus
        queue.append((i+1,j))
    if i-1 >= 0 and maze[i-1][j] == 1:
        maze[i-1][j] += plus
        queue.append((i-1,j))
    if j+1 < M and maze[i][j+1] == 1:
        maze[i][j+1] += plus
        queue.append((i,j+1))
    if j-1 >= 0 and maze[i][j-1] == 1:
        maze[i][j-1] += plus
        queue.append((i,j-1))
print(maze[N-1][M-1]-1)