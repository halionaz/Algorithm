// 수열
// 누적 합 & 두 포인터 & 슬라이딩 윈도우

#include <iostream>
#include <vector>
#include <algorithm>

int N, K, ans;
std::vector<int> temps;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> K;

    temps.resize(N);

    int cur = 0;

    for(int i = 0; i < N; i++){

        std::cin >> temps[i];

        if(i < K){
            cur += temps[i];
        }
    }

    ans = cur;

    for(int i = 0; i + K < N; i++){

        cur += temps[i+K];
        cur -= temps[i];

        ans = std::max(ans, cur);

    }

    std::cout << ans << '\n';

    return 0;
}