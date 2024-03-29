# 트리의 독립집합
# 다이나믹 프로그래밍 & 트리에서의 다이나믹 프로그래밍
# top-down & py_output_at_once

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
# dp[i][0] :: i번째 정점까지 확인했을 때, i번째 정점이 집합에 들어가지 않을때의 가중치 최댓값
# dp[i][1] :: i번째 정점까지 확인했을 때, i번째 정점이 집합에 들어갈 때의 가중치 최댓값
dp = [[0,0] for _ in range(n+1)] 
trace = [[[] for _ in range(2)] for _ in range(n+1)]
def dpdfs(cur,parent) :
    dp[cur][1] = weight[cur]
    for i in line[cur] :
        if i != parent :
            # 자식 노드라면 dfs 진행
            dpdfs(i,cur)
            if dp[i][1] > dp[i][0] :
                # 만약 자식 노드를 집합에 넣은게 넣지 않은 것보다 가중치가 크다면
                dp[cur][0] += dp[i][1] # 현재 노드까지 살폈을 때, 현재 노드를 넣지 않은 최댓값에 더해줌
                trace[cur][0] += trace[i][1] + [i]
            else :
                # 만약 자식 노드를 집합에 넣지 않은게 넣은 것보다 가중치가 크다면
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
