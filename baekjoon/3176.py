# 도로 네트워크
# 최소 공통 조상

import sys
sys.setrecursionlimit(10**5)
input = sys.stdin.readline
log = 17

N = int(input())
line = [[] for _ in range(N+1)]
parents = [[[-1]*3 for _ in range(N+1)] for _ in range(log+1)]
depth = [-1]*(N+1)

for _ in range(N-1) :
    a,b,c = map(int,input().split())
    line[a].append([b,c])
    line[b].append([a,c])

def makeTree(tmp) :
    for i,c in line[tmp] :
        if depth[i] == -1 :
            parents[0][i][0] = tmp
            parents[0][i][1] = parents[0][i][2] = c
            depth[i] = depth[tmp] + 1
            makeTree(i)

depth[1] = 0
makeTree(1)

# sparse table 제작
# parents(sparse table)의 0번 인덱스는 로그 스케일 부모 노드를, 
# 1번 인덱스는 부모까지 가는 데 최소 도로의 값을, 
# 2번 인덱스는 부모까지 가는 데 최대 도로의 값을 저장함
for i in range(log) :
    for j in range(1,N+1) :
        if parents[i][j][0] != -1 :
            parents[i+1][j][0] = parents[i][parents[i][j][0]][0]
            if parents[i+1][j][0] != -1 :
                parents[i+1][j][1] = min(parents[i][parents[i][j][0]][1],parents[i][j][1])
                parents[i+1][j][2] = max(parents[i][parents[i][j][0]][2],parents[i][j][2])

M = int(input())
for _ in range(M) :
    minAns = float('inf')
    maxAns = -1

    # a - b 경로 중 가장 짧은 도로의 길이와 가장 긴 도로의 길이 구하면 됨
    a,b = map(int,input().split())
    if depth[a] != depth[b] :

        if depth[a] < depth[b] :
            # a의 깊이가 더 깊게 조정
            a, b = b, a
        
        d = depth[a] - depth[b]
        ind = 0
        while d :
            if d % 2 :
                minAns = min(minAns,parents[ind][a][1])
                maxAns = max(maxAns,parents[ind][a][2])
                a = parents[ind][a][0]
            d //= 2
            ind += 1

    if a != b :
        for i in reversed(range(log+1)) :
            if parents[i][a][0] != parents[i][b][0] :
                minAns = min(minAns,parents[i][a][1],parents[i][b][1])
                maxAns = max(maxAns,parents[i][a][2],parents[i][b][2])
                a = parents[i][a][0]
                b = parents[i][b][0]
        minAns = min(minAns,parents[0][a][1],parents[0][b][1])
        maxAns = max(maxAns,parents[0][a][2],parents[0][b][2])

    print(minAns,maxAns)