# 행렬 곱셈 순서
# 다이나믹 프로그래밍
# bottom-up

# 탑다운 형식으로도 풀 수 있으나, 바텀업으로 풂

import sys
input = sys.stdin.readline
N = int(input())
arr = []
for _ in range(N) :
    arr.append(list(map(int,input().split())))
memo = [[0]*N for _ in range(N)]
# memo[i][j] :: i~j까지의 행렬곱을 할 때 최소 연산 수
for x in range(1,N) :
    for i in range(N-x) :
        j = i+x
        memo[i][j] = 99999999999999
        for mid in range(i,j) :
            memo[i][j] = min(memo[i][j],memo[i][mid]+memo[mid+1][j]+arr[i][0]*arr[mid][1]*arr[j][1])
print(memo[0][-1])