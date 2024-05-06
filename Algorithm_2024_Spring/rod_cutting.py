# rod_cutting_problem
# 다이나믹 프로그래밍
# bottom-up

# 11052, 카드 구매하기 문제와 같음

inf = 987654321


def bottom_up_cutting_rod(p, n):
    income_dp = [-inf] * (n + 1)
    sol = [-1] * (n + 1)
    income_dp[0] = 0
    for j in range(1, n + 1):
        for i in range(1, j + 1):
            if income_dp[j] < p[i] + income_dp[j - i]:
                income_dp[j] = p[i] + income_dp[j - i]
                sol[j] = i
    return income_dp, sol


def print_solution(sol, n):
    while n > 0:
        print(sol[n])
        n -= sol[n]


N = int(raw_input())
P = [0]
for _ in range(N):
    P.append(int(raw_input()))

revenue, solution = bottom_up_cutting_rod(P, N)
print(revenue[N])
print_solution(solution, N)
