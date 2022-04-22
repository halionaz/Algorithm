// 스타후르츠
// 사칙연산

#include <ios>
#include <iostream>

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int N, T, C, P;

    std::cin >> N >> T >> C >> P;

    std::cout << ((N-1)/T)*C*P << '\n';

    return 0;
}