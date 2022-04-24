// Rats
// 사칙연산

#include <iostream>

int n1, n2, n12;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n1 >> n2 >> n12;

    std::cout << ((n1+1)*(n2+1)/(n12+1))-1 << '\n';

    return 0;

}