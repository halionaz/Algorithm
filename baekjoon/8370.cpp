// Plane
// 사칙연산

#include <iostream>

int n1, k1, n2, k2;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n1 >> k1 >> n2 >> k2;


    std::cout << n1*k1 + n2*k2 << '\n';

    return 0;
}