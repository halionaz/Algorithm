// 진법 변환 2
// 구현 & 수학

#include <iostream>
#include <string>

long long BinaryN;
int B;
std::string S;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> BinaryN >> B;

    while(BinaryN){
        if(BinaryN % B > 9){
            S = char('A' + (BinaryN % B) - 10) + S;
        } else {
            S = std::to_string(BinaryN % B) + S;
        }
        BinaryN /= B;
    }

    std::cout << S << '\n';

    return 0;
}