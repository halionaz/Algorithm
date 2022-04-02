# 컵라면
# 그리디 알고리즘 & 우선순위 큐

# 데드라인 높은 순으로 받은 후, 낮은 시간에서부터 대입

import sys
import heapq
input = sys.stdin.readline
N = int(input())
problem = []
maxTime = 0
for _ in range(N) :
    d,c = map(int,input().split())
    maxTime = max(maxTime,d)
    heapq.heappush(problem,[-d,c])
ans = 0
possibleProblem = []
for i in reversed(range(1,maxTime+1)) :
    while len(problem) and -problem[0][0] >= i :
        d,c = heapq.heappop(problem)
        heapq.heappush(possibleProblem,-c)
    if len(possibleProblem) :
        ans -= heapq.heappop(possibleProblem)
    elif not len(problem) :
        break
print(ans)