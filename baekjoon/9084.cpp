// 동전
// 배낭 문제 & 다이나믹 프로그래밍
// bottom-up

// 냅색을 이용하지만, 그 전 순회를 이용한다는 인사이트
// 생각보다 처음 구상이 힘들었다

#include <iostream>

int T, N, M;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;

    while(T--){

        int dp[10001] = {0}; // dp[i]는 i금액을 만들 수 있는 경우의 수
        int unit[20]; // 단위 저장

        std::cin >> N;

        dp[0]= 1;

        for(int i = 0; i < N; i++){
            std::cin >> unit[i];
        }

        std::cin >> M;

        for(int i = 0; i < N; i++){
            for(int j = unit[i]; j <= M; j++){
                dp[j] += dp[j - unit[i]];
                // j 금액을 만들 수 있는 경우의 수는
                // dp[j] + dp[j - i번째 동전 금액]
            }
        }

        std::cout << dp[M] << '\n';

    }

    return 0;
}