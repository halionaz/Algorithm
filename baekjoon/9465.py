# 스티커
# 다이나믹 프로그래밍

import sys
input = sys.stdin.readline
T = int(input())
for _ in range(T) :
    n = int(input())
    sticker = [[0]]
    for _ in range(2) :
        sticker.append([0]+list(map(int,input().split())))
    dp = [[0]*(n+1) for _ in range(3)]
    dp[1][1] = sticker[1][1]
    dp[2][1] = sticker[2][1]
    for i in range(2,n+1) :
        dp[1][i] = max(dp[2][i-1],dp[2][i-2])+sticker[1][i]
        dp[2][i] = max(dp[1][i-1],dp[1][i-2])+sticker[2][i]
    print(max(dp[1][n],dp[2][n]))