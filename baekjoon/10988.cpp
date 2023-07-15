// 팰린드롬인지 확인하기
// 문자열

#include <iostream>
#include <string>

std::string S;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> S;

    int l = S.length();

    for(int i = 0; i < l / 2; i++){
        if(S[i] != S[l - i - 1]){
            std::cout << "0\n";
            return 0;
        }
    }

    std::cout << "1\n";

    return 0;
}