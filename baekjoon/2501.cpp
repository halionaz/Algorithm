// 약수 구하기
// 브루트포스 알고리즘 & 수학

#include <iostream>

int N, K;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> K;

    for(int i = 1; i <= N; i++){
        if(N % i == 0){
            // i는 N의 약수
            if((--K) == 0){
                std::cout << i << '\n';
                return 0;
            }
        }
    }

    std::cout <<"0\n";

    return 0;
}