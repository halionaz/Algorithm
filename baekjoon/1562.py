# 계단 수
# 다이나믹 프로그래밍 & 비트마스킹 & 비트필드를 이용한 다이나믹 프로그래밍
# top-down

N = int(input())
# dp[i][j][k] :: 마지막 숫자가 i이고, j자릿수이며, 0~9까지 사용한 숫자가 k 상태인 계단 수 개수
dp = [[[-1]*(1<<10) for _ in range(N+1)] for _ in range(10)]
def stair(start,length,number) :
    if length == N :
        # 만약 0~9까지 모든 수를 다 사용했다면 1 return,
        # 아니라면 0
        return 1 if number == (1<<10)-1 else 0
    if dp[start][length][number] == -1 :
        # 그 전에 탐색 X
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