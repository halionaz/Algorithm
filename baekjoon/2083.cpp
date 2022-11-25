// 럭비 클럽
// 구현

#include <iostream>
#include <string>

std::string S;
int age, weight;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    while(true){

        std::cin >> S;
        std::cin >> age >> weight;

        if(S == "#"){
            break;
        }

        std::cout << S << ' ' << ((age > 17 || weight >= 80) ? "Senior" : "Junior") << '\n';
    }

    return 0;
}