// 문자열
// 구현 & 문자열

#include <iostream>
#include <string>

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::string S;
    int T;

    std::cin >> T;

    while(T--){

        std::cin >> S;

        std::cout << S[0] << S[S.length()-1] << '\n';

    }

    return 0;
}