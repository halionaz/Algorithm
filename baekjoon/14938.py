# 서강그라운드
# 플로이드-와샬 

import sys
import math
inf = math.inf
input = sys.stdin.readline
n,m,r = map(int,input().split())
item = [0] + list(map(int,input().split()))
dp = [[inf]*(n+1) for _ in range(n+1)]
for _ in range(r) :
    a,b,l = map(int,input().split())
    dp[a][b] = l
    dp[b][a] = l
for x in range(1,n+1) :
    for i in range(1,n+1) :
        for j in range(1,n+1) :
            if i != j :
                dp[i][j] = min(dp[i][j],dp[i][x]+dp[x][j])
ans = -1
for i in range(1,n+1) :
    tem = item[i] 
    for j in range(1,n+1) :
        if dp[i][j] <= m :
            tem += item[j]
    ans = max(ans,tem)
print(ans)