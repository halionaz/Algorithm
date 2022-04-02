# 앱
# 다이나믹 프로그래밍 & 배낭 문제

# N,M= map(int,input().split())
# m = list(map(int,input().split()))
# c = list(map(int,input().split()))
# memo = [[0]*10001 for _ in range(N+1)]
# for i in range(N) :
#     for j in range(10001) :
#         if c[i] <= j :
#             memo[i+1][j] = max(memo[i][j],memo[i][j-c[i]]+m[i])
#         else :
#             memo[i+1][j] = memo[i][j]
# for i in range(10001) :
#     if memo[N][i] >= M :
#         print(i)
#         break

# 1차원 배열로 구현

N,M= map(int,input().split())
m = list(map(int,input().split()))
c = list(map(int,input().split()))
maximum = sum(c)
memo = [0]*(maximum+1)
for i in range(N) :
    for j in reversed(range(maximum+1)) :
        if c[i] <= j :
            memo[j] = max(memo[j],memo[j-c[i]]+m[i])
for i in range(maximum+1) :
    if memo[i] >= M :
        print(i)
        break
