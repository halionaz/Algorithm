# 웜홀
# 벨만-포드

import sys
input = sys.stdin.readline
TC = int(input())
inf = 99999999
for _ in range(TC) :
    N,M,W = map(int,input().split())
    line = []
    for _ in range(M) :
        S,E,T = map(int,input().split())
        line.append([S,E,T])
        line.append([E,S,T])
    for _ in range(W) :
        S,E,T = map(int,input().split())
        line.append([S,E,-T])
    memo = [inf]*(N+1)
    memo[1] = 0
    for i in range(N-1) :
        for a,b,c in line :
            if memo[a] + c < memo[b] :
                memo[b] = memo[a] + c
    isPossible = False
    for a,b,c in line :
        if memo[b] > memo[a] + c :
            isPossible = True
            break
    if isPossible :
        print('YES')
    else :
        print('NO')