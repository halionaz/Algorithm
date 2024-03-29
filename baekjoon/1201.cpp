// NMK
// 그리디 알고리즘

#include <iostream>
#include <vector>
#include <algorithm>

int N, M, K;
std::vector<int> arr;

int main(){
    
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M >> K;

    if(N < M + K - 1 || N > M * K){
        // 만족하는 경우 X
        std::cout << -1 << '\n';
    } else {

        // 최대 K개의 숫자를 내림차순으로 하는 수열 M개를 이어 붙이면
        // 가장 긴 감소하는 부분 수열의 길이는 K이면서
        // 가장 긴 증가하는 부분 수열의 길이는 M이 됨

        for(int i = 1; i <= N; i++){
            arr.push_back(i);
        }

        int ind = 0;

        for(int i = 1; i <= M; i++){
            int end = std::min(ind + K, N - M + i);
            // ind에서 K만큼 추가해준 값과, 남은 M개의 그룹을 만들 수 있을만큼의 최솟값을 남긴 것중 작은 것 선택
            std::reverse(arr.begin()+ind, arr.begin()+end);
            ind = end;
        }

        for(int i = 0; i < N; i++){
            std::cout << arr[i] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}