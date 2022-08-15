// 그대로 출력하기
// 구현

// inf_input

#include <cstdio>
#include <iostream>
#include <string.h>

std::string S;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    while(true){

        getline(std::cin, S);

        if(S == ""){
            break;
        }
        
        std::cout << S << '\n';

    }

    return 0;
}