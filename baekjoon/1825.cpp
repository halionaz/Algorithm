// 순열 만들기
// 그리디 알고리즘

#include <iostream>
#include <vector>
#include <algorithm>

int N, M, K;
std::vector<int> arr1;
std::vector<int> arr2;

int main(){
    
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M >> K;

    if(N < M + K - 1 || N > M * K){
        // 만족하는 경우 X
        std::cout << -1 << '\n';
    } else {

        for(int i = 1; i <= N; i++){
            arr1.push_back(i);
            arr2.push_back(N - i + 1);
        }

        int ind = N;

        for(int i = 1; i <= M; i++){
            int start = std::max(ind - K, M - i);
            std::reverse(arr1.begin() + start, arr1.begin() + ind);
            ind = start;
        }

        ind = N;

        for(int i = 1; i <= K; i++){
            int start = std::max(ind - M, K - i);
            std::reverse(arr2.begin() + start, arr2.begin() + ind);
            ind = start;
        }

        for(int i = 0; i < N; i++){
            std::cout << arr1[i] << ' ';
        }
        std::cout << '\n';
        for(int i = 0; i < N; i++){
            std::cout << arr2[i] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}