# 보석 도둑
# 그리디 알고리즘 & 우선순위 큐

import sys
import heapq
input = sys.stdin.readline
N,K = map(int,input().split())
gem = []
bag = []
for _ in range(N) :
    heapq.heappush(gem,list(map(int,input().split())))
for _ in range(K) :
    heapq.heappush(bag,int(input()))
ans = 0
capGem = []
for _ in range(K) :
    curBag = heapq.heappop(bag)
    while len(gem) and gem[0][0] <= curBag :
        w,v = heapq.heappop(gem)
        heapq.heappush(capGem,-v)
    if len(capGem) :
        ans -= heapq.heappop(capGem)
    elif not len(gem) :
        break
print(ans)