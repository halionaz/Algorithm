# 보석 도둑
# 그리디 알고리즘 & 우선순위 큐

import sys
import heapq
input = sys.stdin.readline
N,K = map(int,input().split())
gem = []
bag = []

# 보석과 가방을 min heap으로 관리
for _ in range(N) :
    heapq.heappush(gem,list(map(int,input().split())))
for _ in range(K) :
    heapq.heappush(bag,int(input()))

ans = 0
capGem = []
for _ in range(K) :
    curBag = heapq.heappop(bag)
    while len(gem) and gem[0][0] <= curBag :
        # 현재 가방에 담을 수 있다면, 후보군으로 올려 놓음
        # 지금까지 채운 보석의 가격은 max heap으로 관리
        w,v = heapq.heappop(gem)
        heapq.heappush(capGem,-v)
    if len(capGem) :
        # 지금까지 채운 보석이 있다면,
        # 그 중에 가장 가격이 높은 한개를 이번 가방에 담음 (ans에 추가함)
        ans -= heapq.heappop(capGem)
    elif not len(gem) :
        # 이번에 채우지 못했는데, 남은 보석도 없다면 반복문을 끝냄
        break
print(ans)