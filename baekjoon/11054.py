# 가장 긴 바이토닉 부분 수열
# 다이나믹 프로그래밍
# bottom-up

N = int(input())
A = list(map(int, input().split()))
arr = [[1,1]] #첫번째 인자는 안 꺾인 수열의 길이, 꺾인 수열의 길이
ans = 1
for i in range(1,N) :
    maxNonBreak = 0
    maxBreak = 0
    for j in range(i) :
        if A[i] > A[j] and arr[j][0] > maxNonBreak :
            maxNonBreak = arr[j][0]
        elif A[i] < A[j] and max(arr[j][0],arr[j][1]) > maxBreak:
            maxBreak = max(arr[j][0],arr[j][1])
        if max(maxNonBreak+1, maxBreak+1) > ans :
            ans = max(maxNonBreak+1, maxBreak+1)
    arr.append([maxNonBreak+1,maxBreak+1])
print(ans)
