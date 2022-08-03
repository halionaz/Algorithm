# 최소비용 구하기 2
# 데이크스트라

# py_output_at_once
# 리스트 한번에 일괄 출력하기

from sys import stdin
import heapq
input = stdin.readline
INF = 999999999999
n = int(input())
m = int(input())
line = [[] for _ in range(n+1)]
for _ in range(m) :
    a,b,c = map(int,input().split())
    line[a].append((b,c))
start,end = map(int,input().split())

dp = [[INF] for _ in range(n+1)]
dp[start] = [0,start]
heap = []
heapq.heappush(heap,(0,start))
while len(heap) :
    cost,ind = heapq.heappop(heap)
    if not dp[ind][0] < cost :
        for i,weight in line[ind] :
            nextCost = cost + weight
            if nextCost < dp[i][0] :
                dp[i] = [nextCost] + dp[ind][1:] + [i]
                heapq.heappush(heap,(nextCost,i))
print(dp[end][0])
print(len(dp[end])-1)
print(*dp[end][1:])