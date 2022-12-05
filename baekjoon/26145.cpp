// 출제비 재분배
// 구현 & 사칙연산

#include <iostream>

int N, M;
int S[1001];
int T[1001][1001];
int ans[2001];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;

    for(int i = 0; i < N; i++){
        std::cin >> ans[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N + M; j++){
            std::cin >> T[i][j];
            ans[i] -= T[i][j];
            ans[j] += T[i][j];
        }
    }

    for(int i = 0; i < N+M; i++){
        std::cout << ans[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}