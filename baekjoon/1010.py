# 다리 놓기
# 조합론

# mCn의 값을 구하면 됨

T = int(input())
for _ in range(T) :
    N,M = map(int, input().split())
    ans = 1
    for i in range(N) :
        ans *= M
        M -= 1
        ans //= i+1
    print(ans)