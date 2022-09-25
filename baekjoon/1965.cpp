// 상자넣기
// 다이나믹 프로그래밍
// bottom-up

// 가장 긴 증가하는 부분 수열 아이디어를 사용한 것으로
// 다이나믹 프로그래밍 기법을 사용했기 때문에
// O(n^2)의 시간이 소요됨

#include <iostream>
#include <algorithm>

int n, ans;
int boxes[1001];
int dp[1001];

int main(){

    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    std::cin >> n;

    for(int i = 0; i < n; i++){
        std::cin >> boxes[i];
    }

    for(int i = 0; i < n; i++){
        dp[i] = 1;

        for(int j = 0; j < i; j++){
            if(boxes[j] < boxes[i] && dp[i] < dp[j]+1){
                dp[i] = dp[j]+1;
            }
        }

        ans = std::max(dp[i], ans);

    }

    std::cout << ans << '\n';

    return 0;
}