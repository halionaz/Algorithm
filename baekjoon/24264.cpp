// 알고리즘 수업 - 알고리즘의 수행 시간 3
// 구현 & 시뮬레이션

#include <iostream>

long long N;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    // 알고리즘의 수행 횟수는 N 반복문이 중첩되어 있으므로 N^2
    // 수행 횟수를 다항식으로 나타내면 차수가 2임
    std::cout << N * N << '\n';
    std::cout << 2 << '\n';

    return 0;
}