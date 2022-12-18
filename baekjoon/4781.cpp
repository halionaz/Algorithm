// 사탕 가게
// 배낭 문제 & 다이나믹 프로그래밍
// bottom-up

// 가격이 소수점이라 자연수 처리가 조금 어려웠던 문제
// 물건 별로 dp 행을 만들지 말고
// 그냥 물건 순회하면서 계속 dp를 덮어쓰기 하는 것이 효율적임

#include <iostream>
#include <algorithm>
#include <cstring>

int N, C, M;
double F, P;

std::pair<int, int> candy[5001];
// memo[j] :: j의 돈을 가졌을 때 가질 수 있는 최대 칼로리 합
int memo[100 * 100 + 1];

int main(void){

    while (1){

        memset(memo, 0, sizeof(memo));

        std::cin >> N >> F;

        if (N == 0 && F == 0.00){
            // 문제 끝내기
            break;
        }

        // 부동 소수점 오류 없애기
        M = F*100 + 0.5;

        for (int i = 0; i < N; i++){

            std::cin >> C >> P;

            // 부동 소수점 오류 없애기
            candy[i] = std::make_pair(C, (int)(P * 100 + 0.5));
        }

        for(int i = 0; i < N; i++){
            for(int j = 1; j <= M; j++){
                if(candy[i].second <= j){
                    memo[j] = std::max(memo[j], memo[j - candy[i].second] + candy[i].first);
                }
            }
        }

        std::cout << memo[M] << '\n';

    }

    return 0;
}
