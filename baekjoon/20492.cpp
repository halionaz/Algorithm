// 세금
// 사칙연산

#include <iostream>

int N;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    std::cout << (N/100)*78 << ' ';
    std::cout << N-(((N/100)*20)/100)*22 << '\n';

    return 0;
}