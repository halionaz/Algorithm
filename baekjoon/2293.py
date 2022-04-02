# 동전 1
# 다이나믹 프로그래밍

import sys
input = sys.stdin.readline
n,k = map(int,input().split())
coin = []
for _ in range(n) :
    coin.append(int(input()))
memo = [1] + [0]*k
for i in coin :
    for j in range(1,k+1) :
        plus = 0
        if j >= i :
            plus = memo[j-i]
        memo[j] = memo[j] + plus
print(memo[k])