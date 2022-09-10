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
            LIS.append(i)
            indArr.append(length)
        else :
            ind = bisect_left(LIS,i)
            indArr.append(ind)
            LIS[ind] = i
    else :
        LIS.append(i)
        indArr.append(0)
cnt = len(LIS)
print(cnt)
cnt -= 1
ind = N-1
ans = []
while cnt>-1 :
    if indArr[ind] == cnt :
        cnt -= 1
        ans.append(A[ind])
        ind -= 1
    else :
        ind -= 1
print(*ans[::-1])