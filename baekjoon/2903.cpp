// 중앙 이동 알고리즘
// 수학

// 한 변에 있는 점 개수 = 2^n + 1
// 전체 점 개수 = (2^n + 1)^2

#include <cmath>
#include <iostream>

int N;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    long long res = std::pow(std::pow(2, N) + 1,2);

    std::cout << res << '\n';

    return 0;
}