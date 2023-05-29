// 좋은 구간
// 브루트포스 알고리즘 & 정렬

#include <iostream>
#include <algorithm>
#include <vector>

int L, N;
std::vector<int> S;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> L;

    S.resize(L + 1);

    for(int i = 1; i <= L; i++){
        std::cin >> S[i];
    }

    std::sort(S.begin(), S.end());

    std::cin >> N;

    if(std::find(S.begin(), S.end(), N) == S.end()){
        for(int i = 0; i < L; i++){
            if(S[i] < N && N < S[i+1]){
                // 구간의 개수
                // n보다 작거나 같은 수 x n보다 크거나 같은수 - 1
                std::cout << (N - S[i]) * (S[i+1] - N) - 1 << '\n';
                break;
            }
        }
    } else {
        // 집합 안에 N이 있으므로, 구간 형성 불가
        std::cout << "0\n";
    }

    return 0;
}