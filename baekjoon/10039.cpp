// 평균 점수
// 사칙연산

#include <iostream>

int score[5], sum = 0;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    for(int i = 0; i < 5; i++){
        std::cin >> score[i];

        sum += (score[i] < 40 ? 40 : score[i]);
    }

    std::cout << sum / 5 << '\n';

    return 0;
}