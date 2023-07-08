// 문자와 문자열
// 문자열

#include <iostream>
#include <string>

int i;
std::string S;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> S;
    std::cin >> i;
    std::cout << S[i-1] << '\n';

    return 0;
}