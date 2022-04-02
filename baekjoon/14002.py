# 가장 긴 증가하는 부분 수열 4
# 다이나믹 프로그래밍

N = int(input())
A = list(map(int,input().split()))
dp = [[1,-1]]*N
for i in range(1,N) :
    maximum = 0
    maximumInd = -1
    for j in range(i) :
        if A[j] < A[i] and dp[j][0]>maximum :
            maximum = dp[j][0]
            maximumInd = j
    dp[i] = [maximum+1,maximumInd]
ans = 0
ansInd = 0
for i in reversed(range(N)) :
    if i < ans :
        break
    else :
        if ans < dp[i][0] :
            ansInd = i
            ans = dp[i][0]
ind = ansInd
arr = ''
while True :
    arr = str(A[ind]) + ' ' + arr
    ind = dp[ind][1]
    if ind == -1 :
        break
print(ans)
print(arr)