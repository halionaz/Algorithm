# 외판원 순회
# 외판원 순회 문제 & 다이나믹 프로그래밍 & 비트마스킹 & 비트필드를 이용한 다이나믹 프로그래밍

import sys
import math
input = sys.stdin.readline
N = int(input())
line = []
for _ in range(N) :
    line.append(list(map(int,input().split())))
dp = [[math.inf]*(1<<N) for _ in range(N)]
def dfs(last,bit) :
    if bit == (1<<N)-1 :
        # 모든 노드를 순회 하였음
        if line[last][0] != 0 :
            # 다시 시작점으로 돌아가는 길이 있다면 계산 시작
            return line[last][0]
        else :
            # 길이 없으므로 불가능
            return math.inf
    if dp[last][bit] < math.inf :
        # 이미 저장된 dp값이 있다면 반환
        return dp[last][bit]

    minimum = math.inf
    for i in range(1,N) :
        if bit&(1<<i) == 0 and line[last][i] != 0 :
            # 미방문 노드인 경우 들러봄
            minimum = min(minimum,dfs(i,bit|(1<<i))+line[last][i])
    dp[last][bit] = minimum
    return minimum
print(dfs(0,1))