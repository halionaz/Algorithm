// 예쁜 케이크
// 수학 & 정수론

#include <iostream>
#include <cmath>
#include <algorithm>

typedef long long ll;

ll T, N;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;

    while(T--){

        std::cin >> N;

        if((N-2)%3 == 0 || N % 9 == 0){
            std::cout << "TAK\n";
            continue;
        }

        std::cout << "NIE\n";

    }

    return 0;
}