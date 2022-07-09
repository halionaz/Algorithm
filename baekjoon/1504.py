# 특정한 최단 경로
# 데이크스트라

import sys
import heapq
input = sys.stdin.readline
inf = 99999999999999999
N,E = map(int,input().split())
line = [[] for _ in range(N+1)]
for _ in range(E) :
    a,b,c = map(int,input().split())
    line[a].append((b,c))
    line[b].append((a,c))
v1,v2 = map(int,input().split())
def dijkstra(start) :
    memo = [inf]*(N+1)
    heap = []
    memo[start] = 0
    heapq.heappush(heap,(0,start))
    while len(heap) :
        dist,index = heapq.heappop(heap)
        if not memo[index] < dist :
            for i,weight in line[index] :
                nextDist = dist + weight
                if nextDist < memo[i] :
                    memo[i] = nextDist
                    heapq.heappush(heap,(nextDist,i))
    return memo
startFromOne = dijkstra(1)
startFromV1 = dijkstra(v1)
startFromV2 = dijkstra(v2)
ans = min(startFromOne[v1] + startFromV1[v2] + startFromV2[N],startFromOne[v2] + startFromV2[v1] + startFromV1[N])
if ans >= inf :
    print(-1)
else :
    print(ans)