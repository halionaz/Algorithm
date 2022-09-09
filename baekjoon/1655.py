# 가운데를 말해요
# 우선순위 큐

import sys
import heapq
# 기본적으로 최소 힙 제공
input = sys.stdin.readline
N = int(input())
left,right = [],[]
for _ in range(N) :
    inp = int(input())
    if len(left) == len(right) :
        # 최대 힙
        heapq.heappush(left,(-inp,inp))
    else :
        # 최소 힙
        heapq.heappush(right,(inp,inp))

    # 일단 left와 right 밸런스를 맞춰놓고
    # 크기가 안맞으면 리밸런싱함
    if len(right) != 0 and left[0][1] > right[0][1] :
        val1 = heapq.heappop(left)[1]
        val2 = heapq.heappop(right)[1]
        heapq.heappush(left,(-val2,val2))
        heapq.heappush(right,(val1,val1))

    print(left[0][1])