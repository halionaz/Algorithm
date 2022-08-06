# 가장 긴 증가하는 부분 수열 2
# 이분 탐색 & 가장 긴 증가하는 부분 수열: o(n log n)

# 이분 탐색 파트를 직접 구현한 버전은 12738.py 풀이에서 볼 수 있음

from bisect import bisect_left
N = int(input())
A = list(map(int,input().split()))
LIS = []
for i in A :
    length = len(LIS)
    if length :
        if LIS[length-1] < i :
            # 끝 요소가 현재 탐색중인 요소보다 작다면, 요소 추가
            LIS.append(i)
        else :
            # 끝 요소가 현재 탐색중인 요소보다 크다면, 
            # 일단 현재 요소가 들어갈 수 있는 index에 "대체"해 추가
            ind = bisect_left(LIS,i)
            LIS[ind] = i
    else :
        # 아무 요소가 없으므로, 일단 추가
        LIS.append(i)
cnt = len(LIS) # 현재 LIS 배열은 실제 LIS가 아닐 수도 있음. 그러나 길이는 LIS의 길이를 만족
print(cnt)