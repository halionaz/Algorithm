// 알고리즘 수업 - 알고리즘의 수행 시간 4
// 시뮬레이션 & 사칙연산

#include <iostream>

long long N;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    long long ans = 0;

    for(int i = N - 1; i >= 1; i--){
        ans += i;
    }

    std::cout << ans << '\n' << 2 << '\n';

    return 0;
}