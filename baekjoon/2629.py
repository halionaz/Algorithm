# 양팔저울
# 다이나믹 프로그래밍 & 배낭 문제

# dp의 앞뒤값이 모두 바뀌므로 1차원 배열만 가지고 값을 바꿔나가기는 힘듦

N = int(input())
weight = [0] + list(map(int,input().split()))
M = int(input())
check = list(map(int,input().split()))
memo = [[True] + [False]*40000 for _ in range(N+1)]
for i in range(1,N+1) :
    for j in range(1,40001) :
        if memo[i-1][j] or memo[i-1][abs(weight[i]-j)] :
            memo[i][j] = True
        else :
            if 40001 > weight[i] + j and memo[i-1][weight[i]+j] :
                memo[i][j] = True
for i in check :
    if memo[N][i] :
        print('Y',end=' ')
    else :
        print('N',end=' ')
