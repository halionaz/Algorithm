// 돌 게임
// 게임 이론 & 수학

#include <iostream>

int N;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    std::cout << (N%2 == 0 ? "CY" : "SK") << "\n";

    return 0;
}