# 사회망 서비스(SNS)
# 다이나믹 프로그래밍 & 트리에서의 다이나믹 프로그래밍

import sys
import math
sys.setrecursionlimit(10**6)
INF = math.inf
input = sys.stdin.readline
N = int(input())
edge = [[] for _ in range(N+1)]
dp = [[0,0] for _ in range(N+1)]
# dp[i][0]은 i가 얼리어답터가 아닐 때 전체 최소 얼리어답터 수, 
# dp[i][1]은 i가 얼리어답터일 때 전체 최소 얼리어답터 수
for _ in range(N-1) :
    u,v = map(int,input().split())
    edge[u].append(v)
    edge[v].append(u)
def dpdfs(cur,parent) :
    dp[cur][1] = 1
    for i in edge[cur] :
        if i != parent :
            dpdfs(i,cur)
            dp[cur][0] += dp[i][1]
            dp[cur][1] += min(dp[i][0],dp[i][1])
dpdfs(1,-1)
print(min(dp[1]))
