// 카드 게임
// 이분 탐색

// c++ 라이브러리를 이용해 이분 탐색 사용

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

int N,M,K;
std::vector<int> arr;
bool submit[4000001];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    memset(submit,false,sizeof(submit));

    std::cin >> N >> M >> K;

    for(int i = 0; i < M; i++){
        int x;
        std::cin >> x;
        arr.push_back(x);
    }

    std::sort(arr.begin(),arr.end());

    for(int i = 0; i < K; i++){
        int x;
        std::cin >> x;
        int ind = std::upper_bound(arr.begin(),arr.end(),x) - arr.begin();
        while(submit[ind]){
            // 만약 이미 냈다면, 그것보다 큰 그 다음 수를 선택
            ind++;
        }
        submit[ind] = 1;
        std::cout << arr[ind] << '\n';
    }

    return 0;
}