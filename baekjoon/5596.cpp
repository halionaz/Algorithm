// 시험 점수
// 사칙연산

#include <algorithm>
#include <iostream>

int main(){

    int S = 0, T = 0, inp;

    for(int i = 0; i < 4; i++){
        std::cin >> inp;
        S += inp;
    }

    for(int i = 0; i < 4; i++){
        std::cin >> inp;
        T += inp;
    }

    std::cout << std::max(S, T) << '\n';

    return 0;
}