# KCM Travel
# 데이크스트라 & 다이나믹 프로그래밍

import sys
input = sys.stdin.readline
INF = 99999999999999999999
T = int(input())
for _ in range(T) :
    N,M,K = map(int,input().split())
    ticket = [[] for _ in range(N+1)]
    for _ in range(K) :
        u,v,c,d = map(int,input().split())
        ticket[u].append((v,c,d))
    dp = [[INF]*(M+1) for _ in range(N+1)]
    #dp[i][j]=k 이면, i까지 가는 데, j이하의 돈을 쓴다면 k시간이 걸린다는 것
    dp[1][0] = 0
    for i in range(M+1) :
        for here in range(1,N+1) :
            if dp[here][i] == INF :
                continue
            else :
                lastTime = dp[here][i]
                for end,cost,dist in ticket[here] :
                    if cost+i <= M :
                        dp[end][cost+i] = min(dp[end][cost+i],lastTime+dist)
    result = min(dp[N])
    if result == INF :
        print('Poor KCM')
    else :
        print(result)