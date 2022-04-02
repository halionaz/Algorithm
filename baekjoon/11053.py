# 가장 긴 증가하는 부분 수열
# 다이나믹 프로그래밍

N = int(input())
A = list(map(int, input().split()))
arr = [1]*N
for i in range(0,N) :
    maximum = 0
    for j in range(i+1) :
        if A[j] < A[i] and arr[j] > maximum :
            maximum = arr[j]
    arr[i] = maximum + 1
print(max(arr))