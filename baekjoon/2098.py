# 외판원 순회
# 외판원 순회 문제 & 다이나믹 프로그래밍 & 비트마스킹 & 비트필드를 이용한 다이나믹 프로그래밍

import sys
import math
input = sys.stdin.readline
N = int(input())
line = []
for _ in range(N) :
    line.append(list(map(int,input().split())))
dp = [[200000000]*(1<<N) for _ in range(N)]
def dfs(last,bit) :
    if bit == (1<<N)-1 :
        # 모든 노드를 순회 하였음
        if line[last][0] != 0 :
            # 다시 시작점으로 돌아가는 길이 있다면 계산 시작
            return line[last][0]
        else :
            # 길이 없으므로 불가능
            return 200000000
    if dp[last][bit] < 200000000 :
        # 이미 저장된 dp값이 있다면 반환
        return dp[last][bit]

    dp[last][bit] = 200000000
    for i in range(1,N) :
        if bit&(1<<i) == 0 and line[last][i] != 0 :
            # 미방문 노드인 경우 들러봄
            dp[last][bit] = min(dp[last][bit],dfs(i,bit|(1<<i))+line[last][i])

    # 길이 없다면, 길이 없다는 것을 표시해줌 
    # 굳이 표시하지 않는다 해도 논리 자체에는 문제가 없으나,
    # 이후 같은 상황에 도달했을 때, 미탐색과 구별이 되지 않아 또 탐색을 하기에 
    # 시간 낭비 오짐
    if dp[last][bit] == 200000000 :
        dp[last][bit] = 200000000 - 1

    return dp[last][bit]

print(dfs(0,1))