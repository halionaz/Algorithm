# 가장 긴 증가하는 부분 수열 2
# 이분 탐색 & 가장 긴 증가하는 부분 수열: o(n log n)

from bisect import bisect_left
N = int(input())
A = list(map(int,input().split()))
LIS = []
for i in A :
    length = len(LIS)
    if length :
        if LIS[length-1] < i :
            LIS.append(i)
        else :
            ind = bisect_left(LIS,i)
            LIS[ind] = i
    else :
        LIS.append(i)
cnt = len(LIS)
print(cnt)