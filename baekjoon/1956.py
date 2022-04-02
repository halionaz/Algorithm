# 운동
# 플로이드-와샬

import sys
input = sys.stdin.readline
INF = 99999999999999999999
V,E = map(int,input().split())
dp = [[INF]*(V+1) for _ in range(V+1)]
for i in range(1,V+1) :
    dp[i][i] = 0
for _ in range(E) :
    a,b,c = map(int,input().split())
    dp[a][b] = c
for x in range(1,V+1) :
    for i in range(1,V+1) :
        for j in range(1,V+1) :
            if i != j :
                dp[i][j] = min(dp[i][j],dp[i][x]+dp[x][j])
ans = INF
for start in range(1,V+1) :
    for x in range(1,V+1) :
        if start != x :
            ans = min(ans,dp[start][x]+dp[x][start])
print(-1 if ans == INF else ans)