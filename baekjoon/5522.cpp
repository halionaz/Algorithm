// 카드 게임
// 사칙연산

#include <iostream>

int inp, sum = 0;

int main(){

    std::ios_base::sync_with_stdio(0);

    for(int i = 0; i < 5; i++){
        std::cin >> inp;
        sum += inp;
    }

    std::cout << sum << '\n';

}