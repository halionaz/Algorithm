# 할 일 정하기 1
# 다이나믹 프로그래밍 & 비트마스킹 & 비트필드를 이용한 다이나믹 프로그래밍

import sys
import math
input = sys.stdin.readline
N = int(input())
W = []
def bitCount(x) :
    ans = 0
    while x :
        ans += x&1
        x = x>>1
    return ans
for _ in range(N) :
    W.append(list(map(int,input().split())))
dp = [math.inf]*(1<<N) #dp[1011] = 1,3,4번 일은 진행중, 2번일 미진행중
dp[0] = 0
for i in range(1<<N) :
    k = bitCount(i)
    for j in range(N) :
        if not i & (1<<j) :
            dp[i|1<<j] = min(dp[i|1<<j],dp[i]+W[k][j])
print(dp[-1])
