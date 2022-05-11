// 줄세우기
// 다이나믹 프로그래밍

// 가장 긴 증가하는 부분 수열 아이디어를 사용함
// 이동하는 최소 횟수는 (전체 인원수 - LIS 길이)임

#include <iostream>
#include <algorithm>

int N, ans = 0;
int arr[201];
int dp[201]; // dp[i] :: i가 들어간 LIS 길이

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 0; i < N; i++){
        std::cin >> arr[i];
    }

    for(int i = 0; i < N; i++){
        dp[i] = 1;

        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i] && dp[i] < dp[j] + 1){
                dp[i] = dp[j]+1;
            }
        }

        ans = std::max(ans, dp[i]);
    }

    std::cout << N - ans << '\n';

    return 0;
}