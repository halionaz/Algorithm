// 아!
// 구현 & 문자열

#include <iostream>
#include <string>

std::string J;
std::string D;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> J >> D;

    if(D.length() <= J.length()){
        std::cout << "go\n";
    } else {
        std::cout << "no\n";
    }

    return 0;
}