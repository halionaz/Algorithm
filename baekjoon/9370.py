# 미확인 도착지
# 데이크스트라

import sys
import heapq
inf = 99999999999999999999999
input = sys.stdin.readline

def dijkstra(start,n) :
    # start에서 n개의 각 정점으로 가는 최단 거리
    memo = [inf]*(n+1)
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

T = int(input())

for _ in range(T) :
    n,m,t = map(int,input().split())
    s,g,h = map(int,input().split())
    line = [[] for _ in range(n+1)]
    candidate = []
    for _ in range(m) :
        a,b,d = map(int,input().split())
        line[a].append((b,d))
        line[b].append((a,d))
    for _ in range(t) :
        candidate.append(int(input()))
    SF1 = dijkstra(s,n)
    ans = []
    if SF1[g] > SF1[h] :
        # h -> g로 이동
        SF = dijkstra(g,n)
        sp = g
    else :
        # g -> h로 이동
        SF = dijkstra(h,n)
        sp = h
    for c in candidate :
        if SF[c]+SF1[sp] == SF1[c] :
            ans.append(c)
    print(' '.join(map(str,sorted(ans))))