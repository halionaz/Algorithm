// 별 찍기 - 3
// 구현

#include <iostream>

int N;

int main(){

    std::cin >> N;

    for(int i = N; i >= 1; i--){
        for(int j = 0; j < i; j++){
            std::cout << '*';
        }
        std::cout << '\n';
    }

    return 0;
}