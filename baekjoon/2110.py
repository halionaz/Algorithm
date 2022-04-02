# 공유기 설치
# 이분 탐색 & 매개 변수 탐색

import sys
input = sys.stdin.readline
N, C = map(int,input().split())
house = sorted([int(input()) for _ in range(N)])
start = 1
end = house[-1] - house[0]
while start <= end :
    mid = (start + end) // 2
    cnt = 1
    last = 0
    for i in range(1,N) :
        if house[i] - house[last] >= mid :
            last = i
            cnt += 1
    if cnt >= C :
        start = mid + 1
    else :
        end = mid -1
print(end)