// 삼각형
// 기하학 & 사칙연산

#include <iostream>

double W, H;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> W >> H;

    std::cout << std::fixed;
    std::cout.precision(1);
    std::cout << W * H * 0.5 << '\n';

    return 0;
}