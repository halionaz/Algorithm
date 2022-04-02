# 가운데를 말해요
# 우선순위 큐

import sys
import heapq
input = sys.stdin.readline
N = int(input())
left,right = [],[]
for _ in range(N) :
    inp = int(input())
    if len(left) == len(right) :
        heapq.heappush(left,(-inp,inp))
    else :
        heapq.heappush(right,(inp,inp))
    if len(right) != 0 and left[0][1] > right[0][1] :
        val1 = heapq.heappop(left)[1]
        val2 = heapq.heappop(right)[1]
        heapq.heappush(left,(-val2,val2))
        heapq.heappush(right,(val1,val1))
    print(left[0][1])