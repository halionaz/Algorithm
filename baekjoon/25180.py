# 썸 팰린드롬
# 그리디 알고리즘

N = int(input())
ans = 0
if N <= 9 :
    ans = 1
else :
    if N%2 == 1 :
        # 두자리 홀수인 경우
        ans = 1
        N -= 9
        N //= 2
        wing = N//9
        if N % 9 :
            wing += 1
        ans += wing*2

    else :
        # 짝수개 자리수인 경우
        n = N // 2
        wing = n // 9
        if n % 9 :
            wing += 1
        ans = wing*2

        # 중간에 8이 오는 홀수개 자리수인 경우
        N -= 8
        N //= 2
        wing = N//9
        if N % 9 :
            wing += 1
        ans = min(ans, wing*2 + 1)

print(ans)
