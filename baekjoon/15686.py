# 치킨 배달
# 브루트포스 알고리즘 & 백트래킹

import sys
input = sys.stdin.readline
N,M = map(int,input().split())
world = []
for _ in range(N) :
    world.append(list(map(int,input().split())))
home = []
chicken = []
for i in range(N) :
    for j in range(N) :
        if world[i][j] == 1 :
            home.append([i,j])
        elif world[i][j] == 2 :
            chicken.append([i,j])
lc = len(chicken)
ans = float('inf')
remain = [-1]*M
def selectChicken(last,depth) :
    global ans
    if depth == M :
        temp = 0
        for i,j in home :
            chickenDist = float('inf')
            for x in range(lc) :
                if x in remain :
                    chickenDist = min(chickenDist,abs(chicken[x][0]-i)+abs(chicken[x][1]-j))
            temp += chickenDist
        ans = min(ans,temp)
    else :
        for i in range(last+1,lc) :
            remain[depth] = i
            selectChicken(i,depth+1)
selectChicken(-1,0)
print(ans)