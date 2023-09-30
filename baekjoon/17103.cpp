// 골드바흐 파티션
// 소수 판정 & 에라토스테네스의 체

#include <iostream>
#include <cstring>
#include <cmath>

int T, N;
bool isPrime[1000001];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    // 소수 골라내기
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i <= int(std::sqrt(1000001)); i++){
        if(isPrime[i]){
            for(int j = i*i; j < 1000001; j += i){
                isPrime[j] = false;
            }
        }
    }

    std::cin >> T;

    while(T--){

        std::cin >> N;

        int ans = 0;
        for(int i = 2; i <= N / 2; i++){
            if(isPrime[i] && isPrime[N - i]){
                ans++;
            }
        }

        std::cout << ans << '\n';

    }

    return 0;
}