// 심부름 가는 길
// 사칙연산

#include <iostream>

int sum, inp;

int main(){

    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    for(int i = 0; i < 4; i++){
        std::cin >> inp;
        sum += inp;
    }

    std::cout << sum/60 << '\n';
    std::cout << sum%60 << '\n';

    return 0;
}