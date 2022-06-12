# 플로이드 2
# 플로이드-워셜

import sys
input = sys.stdin.readline
INF = 999999999999999999
n = int(input())
m = int(input())
dp = [[[INF] for _ in range(n+1)] for _ in range(n+1)]
for _ in range(m) :
    a,b,c = map(int,input().split())
    dp[a][b] = [min(c,dp[a][b][0]),a,b]
for x in range(1,n+1) :
    for i in range(1,n+1) :
        for j in range(1,n+1) :
            if i != j :
                if dp[i][x][0]+dp[x][j][0] < dp[i][j][0] :
                    dp[i][j] = [dp[i][x][0]+dp[x][j][0]] + dp[i][x][1:] + dp[x][j][2:]
for i in range(1,n+1) :
    for j in range(1,n+1) :
        print(0 if dp[i][j][0] == INF else dp[i][j][0],end=' ')
    print()
for i in range(1,n+1) :
    for j in range(1,n+1) :
        if dp[i][j][0] :
            print(len(dp[i][j])-1,end=' ')
            print(*dp[i][j][1:])
        else :
            print(0)