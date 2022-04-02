# 순열 만들기
# 그리디 알고리즘

import sys
input = sys.stdin.readline
N, M, K = map(int, input().split())
if N < M + K - 1 or N > M * K : 
    print(-1)
else :
    arr1 = []
    arr2 = []
    for i in range(1,N+1) :
        arr1.append(i)
        arr2.append(N-i+1)
    ind = N
    for i in range(1, M+1) :
        start = max(ind - K, M - i)
        arr1[start:ind] = reversed(arr1[start:ind])
        ind = start
    ind = N
    for i in range(1,K+1) :
        start = max(ind - M, K - i)
        arr2[start:ind] = reversed(arr2[start:ind])
        ind = start
    print(' '.join(map(str,arr1)))
    print(' '.join(map(str,arr2)))