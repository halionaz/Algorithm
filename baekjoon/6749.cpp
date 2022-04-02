// Next in line
// 사칙연산

#include <iostream>

int Y, M;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> Y >> M;

    std::cout << M - Y + M << '\n';

    return 0;
}