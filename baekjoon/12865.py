# 평범한 배낭
# 다이나믹 프로그래밍 & 배낭 문제
# bottom-up

# 냅색 입문 문제
# memo[i][j]는 i개의 물건을 탐색했고
# j개의 무게까지 버틸 수 있을 때 최대 가치를 나타낸다.
# 즉 memo[10][50]은, 10개의 물건을 탐색했고, 50 무게를 버틸 수 있을 때 최대 효용이다

# memo[i][j]를 채워야 할 때, 만약 i번째 물건 무게가 j보다 크다면 넣지 못한다는 말이다
# 따라서 memo[i][j] = memo[i-1][j]이다.
# memo[i-1][j]는 i번째 물건을 넣지 않았을 때의 최대 가치를 보장한다

# i번째 물건 무게가 j보다 작다면, 일단 이미 들어간 물건을 다 빼던가 해서 i 물건을 넣을 순 있다는 것이다
# 따라서 어떻게 하면 최대 가치를 만들 수 있는지 탐색한다
# 안넣는게 더 클 수도 있으니, memo[i-1][j]와
# i는 안들어간 상태에서 i 무게 만큼은 더 넣을 수 있는 경우인 memo[i-1][j - (i 무게)] + i 가치 를 비교한다
# memo[i-1][j - (i무게)] 는 i 탐색 이전, i를 무조건 넣을 수 있는 상태에서의 가치 최대를 보장하므로
# 이 둘을 비교하면 최댓값 DP 탐색이 된다

N,K = map(int,input().split())
arr = [[0]]
for _ in range(N) :
    arr.append(list(map(int,input().split())))
memo = [[0 for _ in range(K+1)] for _ in range(N+1)]
for i in range(1,N+1) :
    for j in range(1,K+1) :
        if arr[i][0] <= j :
            memo[i][j] = max(memo[i-1][j], memo[i-1][j-arr[i][0]]+ arr[i][1]) 
        else :
            memo[i][j] = memo[i-1][j]
print(memo[-1][-1])