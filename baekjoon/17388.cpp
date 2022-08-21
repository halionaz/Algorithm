// 와글와글 숭고한
// 구현

#include <iostream>

int S, K, H;

int main(){

    std::cin >> S >> K >> H;

    if(S + K + H >= 100){
        std::cout << "OK\n";
    } else {
        if(S < K){
            if(S < H){
                std::cout << "Soongsil\n";
            } else {
                std::cout << "Hanyang\n";
            }
        } else {
            if(K < H){
                std::cout << "Korea\n";
            } else {
                std::cout << "Hanyang\n";
            }
        }
    }

}