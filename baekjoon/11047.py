# 동전 0
# 그리디 알고리즘

N,K = map(int,input().split())
arr = [int(input()) for _ in range(N)]
ans = 0
for i in reversed(arr) :
    if i<=K :
        ans += K // i
        K = K % i
print(ans)