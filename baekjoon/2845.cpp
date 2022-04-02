// 파티가 끝나고 난 뒤
// 수학 & 사칙연산

#include <iostream>

int L, P, news;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> L >> P;

    int participant = L*P;

    for(int i = 0; i < 5; i++){
        std::cin >> news;

        std::cout << news - participant << ' ';
    }

    std::cout << '\n';

    return 0;
}