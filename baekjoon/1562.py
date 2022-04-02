# 계단 수
# 다이나믹 프로그래밍 & 비트마스킹 & 비트필드를 이용한 다이나믹 프로그래밍

N = int(input())
dp = [[[-1]*(1<<10) for _ in range(N+1)] for _ in range(10)]
def stair(start,length,number) :
    if length == N :
        return 1 if number == (1<<10)-1 else 0
    if dp[start][length][number] == -1 :
        dp[start][length][number] = 0
        if start + 1 < 10 :
            dp[start][length][number] += stair(start+1,length+1,number|(1<<(start+1)))
        if start - 1 >= 0 :
            dp[start][length][number] += stair(start-1,length+1,number|(1<<(start-1)))
        return dp[start][length][number]%1000000000
    else :
        return dp[start][length][number]
ans = 0
for i in range(1,10) :
    ans += stair(i,1,1<<i)
    ans %= 1000000000
print(ans)