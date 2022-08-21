// 성택이의 은밀한 비밀번호
// 구현

#include <iostream>
#include <string>

int N;
std::string S;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    while(N--){
        std::cin >> S;
        if(S.length() >= 6 && S.length() <= 9){
            std::cout << "yes\n";
        } else {
            std::cout << "no\n";
        }
    }

    return 0;
}