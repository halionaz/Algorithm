// 다음 소수
// 소수 판정 & 브루트포스 알고리즘

#include <iostream>
#include <cmath>

typedef long long ll;

int T;
ll N;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;

    while(T--){

        std::cin >> N;

        if(N == 0 || N == 1){
            // 예외처리
            std::cout << "2\n";
            continue;
        }

        for(ll i = N; ; i++){

            ll max = ll(std::sqrt(i));

            bool isPrime = true;

            for(ll j = 2; j <= max; j++){
                if(i % j == 0){
                    // 나누어 떨어지므로 소수가 아님
                    isPrime = false;
                    break;
                }
            }

            if(isPrime){
                std::cout << i << '\n';
                break;
            }
        }
    }

    return 0;
}