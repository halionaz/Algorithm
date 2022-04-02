# 연속합
# 다이나믹 프로그래밍

n = int(input())
arr = list(map(int, input().split()))
memo = [0]*len(arr)
ans = arr[0]
for i in range(n) :
    if i == 0 :
        memo[0] = arr[0]
    else :
        memo[i] = max(memo[i-1],0) + arr[i]
        if memo[i] > ans :
            ans = memo[i]
print(ans)

