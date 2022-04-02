# 우수 마을
# 다이나믹 프로그래밍 & 트리에서의 다이나믹 프로그래밍

import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
N = int(input())
population = [0] + list(map(int,input().split()))
edge = [[] for _ in range(N+1)]
for _ in range(N-1) :
    a,b = map(int,input().split())
    edge[a].append(b)
    edge[b].append(a)
dp = [[0,0] for _ in range(N+1)]
# dp[i][0]은 i마을이 우수마을이 아닐 때 서브트리 우수마을 주민 총 합
# dp[i][1]은 i마을이 우수마을일 때 서브트리 우수마을 주민 총 합
def dpdfs(cur,par) :
    dp[cur][1] = population[cur]
    for i in edge[cur] :
        if i != par :
            dpdfs(i,cur)
            dp[cur][1] += dp[i][0]
            dp[cur][0] += max(dp[i][0],dp[i][1])
dpdfs(1,-1)
print(max(dp[1]))