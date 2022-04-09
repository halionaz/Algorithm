// 카드 구매하기
// 다이나믹 프로그래밍

#include <iostream>
#include <algorithm>

int N;
int P[10001], dp[1001] = {0};

int main()
{

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for (int i = 1; i <= N; i++)
    {
        std::cin >> P[i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            // i개 카드를 구매하는 가장 높은 금액은
            // max(i개 카드를 가장 높은 금액, (i - j)개 카드를 구매하는 가장 높은 금액 + j개 카드팩 구매 금액)
            dp[i] = std::max(dp[i], dp[i - j] + P[j]);
        }
    }

    std::cout << dp[N] << '\n';

    return 0;
}