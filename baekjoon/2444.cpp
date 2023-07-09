// 별 찍기 - 7
// 구현

#include <iostream>
#include <stdlib.h>

int N;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    int width = N * 2 - 1;

    for(int i = 1; i <= width; i++){
        for(int j = 0; j < abs(N - i); j++){
            std::cout << ' ';
        }
        if(i <= N){
            for(int j = 0; j < i * 2 - 1; j++){
                std::cout << '*';
            }
        } else {
            for(int j = 0; j < (width + 1 - i) * 2 - 1; j++){
                std::cout << '*';
            }
        }
        std::cout << '\n';
    }

    return 0;
}