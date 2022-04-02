# ATM
# 그리디 알고리즘

N = int(input())
P = list(map(int,input().split()))
P.sort()
ans = 0
for i in range(N) :
    time = 0
    for j in range(i+1) :
        time += P[j]
    ans += time
print(ans)