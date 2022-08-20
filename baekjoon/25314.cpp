// 코딩은 체육과목 입니다
// 구현

#include <iostream>

int N;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 0; i < N/4; i++){
        std::cout << "long ";
    }

    std::cout << "int\n";

    return 0;
}