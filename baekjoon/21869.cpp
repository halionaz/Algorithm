// Maximum Bishop
// 애드 혹 & 구성적

// 첫 열의 모든 칸에 비숍을 깔아두고,
// 1행과 n행을 제외한 마지막 열의 모든 칸에 비숍을 깔아주면
// 최대 비숍 설치

#include <iostream>

int N;

int main(){

    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    std::cin >> N;

    if(N == 1){
        std::cout << "1\n1 1\n";
    } else {
        std::cout << N+(N-2) << '\n';
        // 첫 열 모든 칸 + 마지막 열 2칸 빼고 모든 칸
        for(int i = 1; i <= N; i++){
            std::cout << "1 " << i << '\n';
        }
        for(int i = 2; i <= N-1; i++){
            std::cout << N << ' ' << i << '\n';
        }
    }

    return 0;
}

