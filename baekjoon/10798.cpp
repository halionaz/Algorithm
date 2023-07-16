// 세로읽기
// 문자열

#include <iostream>
#include <string>

int main(){

    std::ios_base::sync_with_stdio();
    std::cin.tie(0);

    std::string inp[5];

    for(int i = 0; i < 5; i++){
        std::cin >> inp[i];
    }

    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 5; j++){
            if(inp[j].length() > i){
                std::cout << inp[j][i];
            }
        }
    }
    std::cout << '\n';

    return 0;
}