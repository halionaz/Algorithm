# 1로 만들기
# 다이나믹 프로그래밍
# bottom-up

N = int(input())
memo = [0]*(N+1)
for i in reversed(range(1,N+1)) :
    if i == N :
        memo[i] = 0
    else :
        minimum = 10**7
        if i*3 <= N and memo[i*3] < minimum :
            minimum = memo[i*3]
        if i*2 <= N and memo[i*2] < minimum :
            minimum = memo[i*2]
        if i+1 <= N and memo[i+1] < minimum :        
            minimum = memo[i+1]
        memo[i] = minimum + 1
print(memo[1])
