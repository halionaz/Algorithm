# 경찰차
# 다이나믹 프로그래밍
# bottom-up

import sys
input = sys.stdin.readline
INF = 99999999
N = int(input())
W = int(input())
case = [(1,1)]
for _ in range(W) :
    y,x = map(int,input().split())
    case.append((y,x))

dp = [[[INF,-1,-1] for _ in range(W+1)] for _ in range(W+1)]
ans = [INF,-1,-1]
for i in range(W+1) :
    for j in range(W+1) :
        if i == 0 or j == 0 :
            if i == 0 and j == 0 :
                dp[i][j][0] = 0 # 시작할 때 거리는 0
            elif i == 0 : # 2번째 경찰차만 출동하는 경우
                if j == 1 : # 첫 출동은 (N,N)에서 시작
                    dp[i][j] = [2 * N - case[j][0] - case[j][1],0,0]
                else :
                    dp[i][j] = [dp[i][j-1][0] + abs(case[j-1][0]-case[j][0])+abs(case[j-1][1]-case[j][1]),0,j-1]
            else :
                dp[i][j] = [dp[i-1][j][0] + abs(case[i-1][0]-case[i][0])+abs(case[i-1][1]-case[i][1]),i-1,0]
        elif i == j : # 같은 사건을 두 차가 맡을 수는 없음
            continue
        elif i > j :
            if i-j == 1 :
                minimum = INF
                minInd = 0
                for x in range(i) :
                    val = dp[x][j][0] + abs(case[x][0]-case[i][0])+abs(case[x][1]-case[i][1])
                    if val < minimum :
                        minimum = val
                        minInd = x
                dp[i][j] = [minimum,minInd,j]
            else :
                dp[i][j] = [dp[i-1][j][0] + abs(case[i-1][0]-case[i][0])+abs(case[i-1][1]-case[i][1]),i-1,j]
        else :
            if j-i == 1 :
                minimum = INF
                minInd = 0
                for x in range(j) :
                    if x :
                        val = dp[i][x][0] + abs(case[x][0]-case[j][0])+abs(case[x][1]-case[j][1])
                    else :
                        val = dp[i][x][0] + 2 * N - case[j][0] - case[j][1]
                    if val < minimum :
                        minimum = val
                        minInd = x
                dp[i][j] = [minimum,i,minInd]
            else :
                dp[i][j] = [dp[i][j-1][0] + abs(case[j-1][0]-case[j][0])+abs(case[j-1][1]-case[j][1]),i,j-1]
        if i == W or j == W :
            if dp[i][j][0] < ans[0] :
                ans = [dp[i][j][0],i,j]
print(ans[0])
i,j = ans[1],ans[2]
ansList = []
while True :
    a,b = dp[i][j][1],dp[i][j][2]
    if a == -1 :
        break
    if i != a :
        ansList.append(1)
    else :
        ansList.append(2)
    i,j = a,b
ansList.reverse()
for i in ansList :
    print(i)