// 서강의 역사를 찾아서
// 구현

#include <iostream>
#include <algorithm>

int N, M, area;
int curPoint[1001];
int pastPoint[1001];
int ans = 0;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;

    area = std::max(N,M);

    for(int i = 0; i < N; i++){
        std::cin >> curPoint[i];
    }
    for(int i = 0; i < M; i++){
        std::cin >> pastPoint[i];
    }

    for(int i = 0; i < area; i++){
        ans = std::max(ans, pastPoint[i] - curPoint[i]);
    }

    std::cout << ans << '\n';

    return 0;
}