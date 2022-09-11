# 파일 합치기
# 다이나믹 프로그래밍
# bottom-up

import sys
input = sys.stdin.readline
T = int(input())
for _ in range(T) :
    K = int(input())
    C = list(map(int,input().split()))
    S = [0]*(K+1)
    for i in range(1,K+1) :
        S[i] = S[i-1] + C[i-1]
    memo = [[0]*K for _ in range(K)]
    # memo[i][j] :: i~j까지를 합치는 최소 비용
    for x in range(1,K) : # GAP
        for i in range(K-x) :
            j = x + i
            memo[i][j] = 9999999999999
            for mid in range(i,j) :
                memo[i][j] = min(memo[i][j],memo[i][mid]+memo[mid+1][j]+S[j+1]-S[i])
    print(memo[0][-1])
