# 플로이드
# 플로이드-와샬

import sys
input = sys.stdin.readline
INF = 999999999999999999
n = int(input())
m = int(input())
dp = [[INF]*(n+1) for _ in range(n+1)]
for _ in range(m) :
    a,b,c = map(int,input().split())
    dp[a][b] = min(c,dp[a][b])
for x in range(1,n+1) :
    for i in range(1,n+1) :
        for j in range(1,n+1) :
            if i != j :
                dp[i][j] = min(dp[i][x]+dp[x][j],dp[i][j])
for i in range(1,n+1) :
    for j in range(1,n+1) :
        print(0 if dp[i][j] == INF else dp[i][j],end=' ')
    print()