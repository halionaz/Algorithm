# 01타일
# 다이나믹 프로그래밍
# bottom-up

N = int(input())
memo = [0]*1000001
memo[1],memo[2] = 1,2 # 1개 있을 땐 1 하나만, 2개 있을 땐 00, 11 만들 수 있음
for i in range(3,N+1) :
    # i-1장에 1 하나 붙이거나, i-2장에 00 붙이거나
    memo[i] = (memo[i-1] + memo[i-2])%15746
print(memo[N])