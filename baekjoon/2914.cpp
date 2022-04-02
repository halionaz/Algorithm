// 저작권
// 사칙연산

#include <iostream>

int A, I;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> A >> I;

    std::cout << A * (I-1) + 1 << '\n';

    return 0;
}