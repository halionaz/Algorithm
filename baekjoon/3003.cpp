// 킹, 퀸, 룩, 비숍, 나이트, 폰
// 사칙연산

#include <iostream>

int inp;
int desirable[6] = {1,1,2,2,2,8};

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    for(int i = 0; i < 6; i++){
        std::cin >> inp;
        std::cout << desirable[i] - inp << ' ';
    }

    std::cout << '\n';

    return 0;

}