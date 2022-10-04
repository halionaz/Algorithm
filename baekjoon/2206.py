# 벽 부수고 이동하기
# 너비 우선 탐색

import sys
from collections import deque
input = sys.stdin.readline

N,M = map(int,input().split())
maze = []
vi = (1,-1,0,0)
vj = (0,0,1,-1)
for _ in range(N) :
    maze.append(list(map(int,input().rstrip())))
visited = [[[0]*2 for _ in range(M)] for _ in range(N)]
# visited[i][j][0] :: 벽 부수기 스킬을 이미 썼을 때, (i,j)까지 가는 최단 경로 
# visited[i][j][1] :: 벽 부수기 스킬을 쓰지 않았을 때, (i,j)까지 가는 최단 경로 
visited[0][0] = [0,1] 
queue = deque([(0,0,1)])
while len(queue) > 0 :
    i,j,dash = queue.popleft()
    for x in range(4) :
        newi = i + vi[x]
        newj = j + vj[x]
        if 0<=newi<N and 0<=newj<M :
            if maze[newi][newj] == 0 :
                if dash == 1 and visited[newi][newj][1] == 0 :
                    queue.append((newi,newj,1))
                    visited[newi][newj][1] = visited[i][j][1]+1
                elif dash == 0 and visited[newi][newj][0] == 0 :
                    queue.append((newi,newj,0))
                    visited[newi][newj][0] = visited[i][j][0]+1
            else :
                if dash == 1 and visited[newi][newj][0] == 0 :
                    queue.append((newi,newj,0))
                    visited[newi][newj][0] = visited[i][j][1]+1
ans = 10000001
for i in visited[N-1][M-1] :
    if i != 0 and i<ans :
        ans = i
if ans == 10000001 :
    print(-1)
else :
    print(ans)
