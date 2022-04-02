# 최단경로
# 다익스트라

# 다익스트라 알고리즘을 처음으로 적용해 본 문제
# memo에 최단 경로를 저장하고, min heap에 (거리, 인덱스)를 저장하여
# 매 차례에 최단 거리 노드부터 탐색을 진행할 수 있도록 한다

import sys
import heapq
input = sys.stdin.readline
inf = 9999999999999999
V,E = map(int,input().split())
K = int(input())
line = [[] for _ in range(V+1)]
for _ in range(E) :
    u,v,w = map(int,input().split())
    line[u].append((v,w))
memo = [inf]*(V+1)
heap = []
memo[K] = 0
heapq.heappush(heap,(0,K))
while len(heap) :
    dist,index = heapq.heappop(heap)
    # 서로 다른 두 정점 사이에 간선이 여러개 있을 수 있으므로, 이미 처리된 간선이면 pass
    if not memo[index] < dist :
        for i,weight in line[index] :
            nextDist = dist + weight
            if nextDist < memo[i] :
                memo[i] = nextDist
                heapq.heappush(heap,(nextDist,i))
for i in range(1,V+1) :
    if memo[i] == inf :
        print('INF')
    else :
        print(memo[i])