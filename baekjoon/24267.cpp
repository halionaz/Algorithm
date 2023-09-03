// 알고리즘 수업 - 알고리즘의 수행 시간 6
// 구현 & 수학 & 시뮬레이션

#include <iostream>

long long N;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    long long ans = 0;

    for(long long i = N - 2; i >= 1; i--){
        // i가 5라면, 5 + 4 + 3 + 2 + 1
        ans += ((i + 1) * i) / 2;
    }

    std::cout << ans << "\n3\n";

    return 0;
}