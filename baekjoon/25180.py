# 썸 팰린드롬
# 그리디 알고리즘

N = int(input())
ans = 0
if N <= 9 :
    # 합이 9보다 작으면 무조건 한자리 수로 만들 수 있음
    ans = 1
else :
    if N % 2 == 1 :
        # 두자리 홀수인 경우
        ans = 1
        N -= 9 # 중간 수 9
        N //= 2 # 양쪽에 배분해야 하는 수
        wing = N//9 # 한쪽에 필요한 자리수
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

        # 중간에 8을 넣고 홀수개로 자리로 만드는게 더 짧을 수도 있음
        N -= 8
        N //= 2
        wing = N//9
        if N % 9 :
            wing += 1
        ans = min(ans, wing*2 + 1)

print(ans)
