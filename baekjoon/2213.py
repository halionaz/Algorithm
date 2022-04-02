# 트리의 독립집합
# 다이나믹 프로그래밍 & 트리에서의 다이나믹 프로그래밍

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)
n = int(input())
weight = [0]+list(map(int,input().split()))
line = [[] for _ in range(n+1)]
for _ in range(n-1) :
    a,b = map(int,input().split())
    line[a].append(b)
    line[b].append(a)
dp = [[0,0] for _ in range(n+1)]
trace = [[[] for _ in range(2)] for _ in range(n+1)]
def dpdfs(cur,parent) :
    dp[cur][1] = weight[cur]
    for i in line[cur] :
        if i != parent :
            dpdfs(i,cur)
            if dp[i][1] > dp[i][0] :
                dp[cur][0] += dp[i][1]
                trace[cur][0] += trace[i][1] +[i]
            else :
                dp[cur][0] += dp[i][0]
                trace[cur][0] += trace[i][0]
            dp[cur][1] += dp[i][0]
            trace[cur][1] += trace[i][0]
dpdfs(1,-1)
if dp[1][0] > dp[1][1] :
    print(dp[1][0])
    ans = trace[1][0]
    ans.sort()
    print(*ans)
else :
    print(dp[1][1])
    ans = trace[1][1] + [1]
    ans.sort()
    print(*ans)
