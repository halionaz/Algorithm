# 조합
# 다이나믹 프로그래밍
# bottom-up

n,m = map(int,input().split())
dp = [1] * (n+1)
for i in range(1,n+1) :
    dp[i] = dp[i-1]*i
ans = dp[n]//(dp[m]*dp[n-m])
print(ans)