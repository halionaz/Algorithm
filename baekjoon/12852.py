# 1로 만들기 2
# 다이나믹 프로그래밍
# bottom-up

N = int(input())
dp = [[0,0]]*(N+1) 
# dp[i][0] :: i를 1로 만드는 최소 횟수
# dp[i][1] :: 그 횟수를 만들기 위해서 이 수를 몇으로 만들어야 하는가?
dp[1] = [0,1]
for i in range(2,N+1) :
    minimum = dp[i-1][0] # 일단 초깃값은 i보다 1 작은 수 (연산 3)
    minimumWay = i-1
    if i%3 == 0 :
        if dp[i//3][0]<minimum :
            minimum = dp[i//3][0]
            minimumWay = i//3
    if i%2 == 0 :
        if dp[i//2][0]<minimum :
            minimum = dp[i//2][0]
            minimumWay = i//2
    dp[i] = [minimum+1,minimumWay]
print(dp[N][0])
wayPoint = N
print(N,end=' ')
while wayPoint != 1 :
    wayPoint = dp[wayPoint][1]
    print(wayPoint,end=' ')
print()
