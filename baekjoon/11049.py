# 행렬 곱셈 순서
# 다이나믹 프로그래밍

import sys
input = sys.stdin.readline
N = int(input())
arr = []
for _ in range(N) :
    arr.append(list(map(int,input().split())))
memo = [[0]*N for _ in range(N)]
for x in range(1,N) :
    for i in range(N-x) :
        j = i+x
        memo[i][j] = 99999999999999
        for mid in range(i,j) :
            memo[i][j] = min(memo[i][j],memo[i][mid]+memo[mid+1][j]+arr[i][0]*arr[mid][1]*arr[j][1])
print(memo[0][-1])