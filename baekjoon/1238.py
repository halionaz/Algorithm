# 파티
# 데이크스트라

import sys
import heapq
inf = float('inf')
input = sys.stdin.readline
N,M,X = map(int,input().split())
line = [[] for _ in range(N+1)]
for _ in range(M) :
    a,b,c = map(int,input().split())
    line[a].append([b,c])
def dijkstra(start) : 
    memo = [inf]*(N+1)
    heap = []
    memo[start] = 0
    heapq.heappush(heap,[0,start])
    while len(heap) :
        time, index = heapq.heappop(heap)
        if not memo[index] < time :
            for i,weight in line[index] :
                nextTime = time + weight
                if nextTime < memo[i] :
                    memo[i] = nextTime
                    heapq.heappush(heap,[nextTime,i])
    return memo
startFromX = dijkstra(X)
maxim = -1
for i in range(1,N+1) :
    maxim = max(maxim,startFromX[i]+dijkstra(i)[X])
print(maxim)