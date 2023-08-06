// 약수들의 합
// 구현 & 정수론 & 브루트포스 알고리즘 & 수학

#include <iostream>
#include <vector>


int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    while(true){

        int N, sum = 0;
        std::vector<int> divisors;

        std::cin >> N;

        if(N == -1){
            break;
        }

        for(int i = 1; i < N; i++){
            if(N % i == 0){
                divisors.push_back(i);
                sum += i;
            }
        }

        if(sum == N){
            std::cout << N << " = ";
            for(int i = 0; i < divisors.size(); i++){
                if(i != 0){
                    std::cout << " + ";
                }
                std::cout << divisors[i];
            }
        } else {
            std::cout << N << " is NOT perfect.";
        }

        std::cout << "\n";

    }

    return 0;
}