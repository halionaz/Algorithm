// 치킨댄스를 추는 곰곰이를 본 임스
// 사칙연산

#include <iostream>
#include <algorithm>

int N, A, B;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> A >> B;

    int drinks = (A / 2) + B;

    std::cout << std::min(N, drinks) << '\n';

    return 0;
}