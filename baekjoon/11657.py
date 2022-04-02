# 타임머신
# 벨만-포드

import sys
input = sys.stdin.readline
INF = 99999999999999999999
N,M = map(int,input().split())
line = []
for _ in range(M) :
    line.append(tuple(map(int,input().split())))
memo = [INF]*(N+1)
memo[1] = 0
isPossible = 1
for i in range(N) :
    for a,b,c in line :
        if memo[a] == INF :
            continue
        else :
            if memo[a] + c < memo[b] :
                memo[b] = memo[a]+c
                if i == N-1 :
                    isPossible = 0
if isPossible :
    for i in range(2,N+1) :
        print(-1 if memo[i]==INF else memo[i])
else :
    print(-1)