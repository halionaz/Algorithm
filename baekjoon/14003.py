# 가장 긴 증가하는 부분 수열 5
# 이분 탐색 & 가장 긴 증가하는 부분 수열: o(n log n)
# py_output_at_once

from bisect import bisect_left
N = int(input())
A = list(map(int,input().split()))
LIS = []
indArr = []
for i in A :
    length = len(LIS)
    if length :
        if LIS[length-1] < i :
            # 끝 요소가 현재 탐색중인 요소보다 작다면, 요소 추가
            LIS.append(i)
            indArr.append(length) # 추가된 요소의 LIS 인덱스 저장
        else :
            # 끝 요소가 현재 탐색중인 요소보다 크다면, 
            # 일단 현재 요소가 들어갈 수 있는 index에 "대체"해 추가
            ind = bisect_left(LIS,i)
            indArr.append(ind) # 대체된 LIS 인덱스 저장
            LIS[ind] = i
    else :
        # 아무 요소가 없으므로, 일단 추가
        LIS.append(i)
        indArr.append(0) # LIS 인덱스 추가
cnt = len(LIS) # 현재 LIS 배열은 실제 LIS가 아닐 수도 있음. 그러나 길이는 LIS의 길이를 만족
print(cnt)
cnt -= 1 # LIS 배열의 인덱스
ind = N-1 # 원본 수열의 인덱스
ans = []

# indArr에 들어있는 요소들을 뒤에서부터 탐색하면서 실제 LIS에 포함되는 요소를 골라냄
while cnt > -1 :
    if indArr[ind] == cnt :
        # 실제 LIS에 포함되는 녀석 찾음
        ans.append(A[ind])
        cnt -= 1
        ind -= 1
    else :
        ind -= 1
print(*ans[::-1])