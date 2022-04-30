// Cupcake Party
// 사칙연산

#include <iostream>

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int R, S;

    std::cin >> R >> S;

    std::cout << (R*8 + S*3) - 28 << '\n';

    return 0;
}