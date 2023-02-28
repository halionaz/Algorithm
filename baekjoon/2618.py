# 경찰차
# 다이나믹 프로그래밍
# bottom-up & py_output_at_once

import sys
input = sys.stdin.readline
INF = 99999999
N = int(input())
W = int(input())
case = [(1,1)]
for _ in range(W) :
    y,x = map(int,input().split())
    case.append((y,x))

# dp[i][j] :: 1번 경찰차가 i번 사건을 맡았고, 2번 경찰차가 j번 사건을 맡았을 때의 (이동거리, 1번 차가 맡은 그 전 사건, 2번 차가 맡은 그 전 사건)
dp = [[[INF,-1,-1] for _ in range(W+1)] for _ in range(W+1)]
ans = [INF,-1,-1]

for i in range(W+1) :
    for j in range(W+1) :
        # 1번 경찰차가 i번 사건을 맡고,
        # 2번 경찰차가 j번 사건을 맡는 경우
        if i == 0 or j == 0 :
            if i == 0 and j == 0 :
                # 시작할 때 거리는 0
                dp[i][j][0] = 0 
            elif i == 0 : 
                # 2번째 경찰차만 출동하는 경우
                if j == 1 : 
                    # 첫 출동은 (N,N)에서 시작
                    dp[i][j] = [2 * N - case[j][0] - case[j][1],0,0]
                else :
                    dp[i][j] = [dp[i][j-1][0] + abs(case[j-1][0]-case[j][0])+abs(case[j-1][1]-case[j][1]),0,j-1]
            else :
                # 1번째 경찰차만 출동하는 경우
                dp[i][j] = [dp[i-1][j][0] + abs(case[i-1][0]-case[i][0])+abs(case[i-1][1]-case[i][1]),i-1,0]
        elif i == j : 
            # 같은 사건을 두 차가 맡을 수는 없음
            continue
        elif i > j :
            if i-j == 1 :
                # i 바로 직전 사건을 2번 차량이 해결함
                # 그렇다면 i 이전에 1번 차량이 해결한 문제가 뭘까?
                minimum = INF
                minInd = 0
                for x in range(i) :
                    val = dp[x][j][0] + abs(case[x][0]-case[i][0]) + abs(case[x][1]-case[i][1])
                    if val < minimum :
                        minimum = val
                        minInd = x
                dp[i][j] = [minimum,minInd,j]
            else :
                # i 바로 직전 사건도 1번 차량이 해결함
                dp[i][j] = [dp[i-1][j][0] + abs(case[i-1][0]-case[i][0])+abs(case[i-1][1]-case[i][1]),i-1,j]
        else :
            if j-i == 1 :
                # j 바로 이전 사건을 1번 차량이 해결함
                # 그렇다면 j 이전에 2번 차량이 해결한 문제가 뭘까?
                minimum = INF
                minInd = 0
                for x in range(j) :
                    if x :
                        val = dp[i][x][0] + abs(case[x][0]-case[j][0])+abs(case[x][1]-case[j][1])
                    else :
                        # x가 0인 경우, 즉 2번 차량이 첫 출발 하는 경우
                        val = dp[i][x][0] + 2 * N - case[j][0] - case[j][1]
                    if val < minimum :
                        minimum = val
                        minInd = x
                dp[i][j] = [minimum,i,minInd]
            else :
                # j 바로 직전 사건도 2번 차량이 해결함
                dp[i][j] = [dp[i][j-1][0] + abs(case[j-1][0]-case[j][0])+abs(case[j-1][1]-case[j][1]),i,j-1]
        if i == W or j == W :
            # 모든 사건을 해결한 경우
            if dp[i][j][0] < ans[0] :
                # 정답 갱신
                ans = [dp[i][j][0],i,j]

# 정답 출력
print(ans[0])
i,j = ans[1],ans[2]
ansList = []

# 경로 역추적을 통해 각 사건을 어떤 차가 해결했는지 처리
while True :
    # a는 1번 차가 그 전에, b는 2번 차가 그 전에 해결한 사건
    a,b = dp[i][j][1],dp[i][j][2]

    if a == -1 :
        break

    if i != a :
        ansList.append(1)
    else :
        ansList.append(2)
    i,j = a,b

ansList.reverse()

print(*ansList)