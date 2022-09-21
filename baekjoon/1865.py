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
    # 한번더 탐색할 시에 또 갱신이 되어버리는 참사가 발생한다면
    # 무한 음수 간선 사이클이 존재하는 것이므로 시간이 줄어들면서 처음 위치로 복귀하는 것이 가능함
    for a,b,c in line :
        if memo[b] > memo[a] + c :
            isPossible = True
            break
    if isPossible :
        print('YES')
    else :
        print('NO')