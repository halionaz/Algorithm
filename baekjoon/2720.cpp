// 세탁소 사장 동혁
// 사칙연산 & 그리디 알고리즘

#include <iostream>

int T, C;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;

    while(T--){

        std::cin >> C;

        std::cout << C / 25 << ' ';
        C %= 25;
        std::cout << C / 10 << ' ';
        C %= 10;
        std::cout << C / 5 << ' ';
        C %= 5;
        std::cout << C / 1 << '\n';

    }

    return 0;
}