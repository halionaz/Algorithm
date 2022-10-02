# 선분 그룹
# 선분 교차 판정 & 분리 집합
# ccw 알고리즘

import sys
input = sys.stdin.readline
N = int(input())
line = []
for _ in range(N) :
    line.append(list(map(int,input().split())))
parent = [0]*N
cnt = [1]*N # 각 그룹에 속한 선분 개수
for i in range(N) :
    parent[i] = i

def ccw(ax,ay,bx,by,cx,cy) :
    result = (bx-ax)*(cy-ay)-(cx-ax)*(by-ay)
    if result > 0 :
        return 1
    elif result < 0 :
        return -1
    else :
        return 0

def findParent(x):
    if parent[x] == x :
        return x
    else :
        parent[x] = findParent(parent[x])
        return parent[x]

def union(a,b) :
    x = findParent(a)
    y = findParent(b)
    if x != y :
        if x < y :
            parent[y] = x
            cnt[x] += cnt[y]
        else :
            parent[x] = y
            cnt[y] += cnt[x]

def isGroup(i,j) :
    # 선분 i와 j가 교차하는지 판단
    abc = ccw(line[i][0],line[i][1],line[i][2],line[i][3],line[j][0],line[j][1])
    abd = ccw(line[i][0],line[i][1],line[i][2],line[i][3],line[j][2],line[j][3])
    cda = ccw(line[j][0],line[j][1],line[j][2],line[j][3],line[i][0],line[i][1])
    cdb = ccw(line[j][0],line[j][1],line[j][2],line[j][3],line[i][2],line[i][3])
    if abc*abd == 0 and cda*cdb == 0 :
        # 두 선분이 한 직선 위에 존재함
        ax,bx,cx,dx = line[i][0],line[i][2],line[j][0],line[j][2]
        ay,by,cy,dy = line[i][1],line[i][3],line[j][1],line[j][3]
        if bx<ax :
            ax,bx = bx,ax
        if dx<cx :
            cx,dx = dx,cx
        if by<ay : by,ay = ay,by
        if dy<cy : cy,dy = dy,cy
        if ax <= dx and cx <= bx :
            if ay <= dy and cy <= by :
                return 1
            else :
                return 0
        else :
            return 0
    elif abc*abd <= 0 and cda*cdb<=0 :
        # 교차함
        return 1
    else :
        # 교차하지 않음
        return 0

for i in range(N-1) :
    for j in range(i+1,N) :
        if isGroup(i,j) :
            union(i,j)

ans = maxAns = 0;

for i in range(N) :
    if parent[i] == i :
        ans += 1
        if cnt[i] > maxAns :
            maxAns = cnt[i]

print(ans)
print(maxAns)