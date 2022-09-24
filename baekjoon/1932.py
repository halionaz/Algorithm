# 정수 삼각형
# 다이나믹 프로그래밍
# bottom-up

n = int(input())
arr = []
for _ in range(n) :
    arr.append(list(map(int,(input().split()))))
dp = [arr[0]] # dp[i][j] :: 위에서 i층에서, j번째 수를 포함하는 최대 합
for i in range(1,n) :
    stage = []
    for j in range(i+1) :
        if j == 0 :
            # 이 층의 가장 첫번째 수
            stage.append(dp[i-1][0]+arr[i][0])
        elif j == i :
            # 이 층의 가장 마지막 수
            stage.append(dp[i-1][j-1]+arr[i][j])
        else :
            stage.append(max(dp[i-1][j-1], dp[i-1][j])+arr[i][j])
    dp.append(stage)
print(max(dp[-1]))