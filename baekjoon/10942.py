# 팰린드롬?
# 다이나믹 프로그래밍

import sys
input = sys.stdin.readline
N = int(input())
arr = [0] + list(map(int,input().split()))
M = int(input())
memo = [[0]*(N+1) for _ in range(N+1)]
for i in range(1,N+1) :
    memo[i][i] = 1
for i in range(1,N) :
    if arr[i] == arr[i+1] :
        memo[i][i+1] = 1
for x in range(2,N) : # 간격
    for i in range(1,N-x+1) : #시작점
        j = i+x #끝점
        if arr[i] == arr[j] and memo[i+1][j-1] :
            memo[i][j] = 1
for _ in range(M) :
    i,j = map(int,input().split())
    print(memo[i][j])