// 같은 탑
// 다이나믹 프로그래밍
// top-down

#include <iostream>
#include <algorithm>
#include <cstring>

const int minInf = -2147483645;

int N;
int arr[50];
// dp[i][j] :: i번째 조각까지 사용했고, 두 탑의 높이 차가 j일 때의 탑 높이 최댓값
int dp[50][250001];

int search(int ind, int diff){
    // ind까지 조각을 탐색했고, 두 탑의 높이 차가 diff일 때의 만들 수 있는 탑의 높이의 최댓값

    if((ind == N && diff) || diff > 250000){
        // 성립하지 않음
        return minInf;
    }

    if(ind == N && !diff){
        // 모든 인덱스를 돌았고, 두 탑의 높이 차이가 0임
        return 0;
    }

    if(dp[ind][diff] != -1){
        return dp[ind][diff];
    }

    // 쓰지 않을 때
    dp[ind][diff] = std::max(minInf, search(ind+1,diff));

    // 높은 탑에 ind번째 조각을 올려놓을 때 (두 탑의 높이 차이는 무조건 커짐)
    // 하지만 더 낮은 탑의 높이는 변하지 않으므로 만들 수 있는 탑의 높이도 변하지 않음
    dp[ind][diff] = std::max(dp[ind][diff], search(ind+1, diff + arr[ind]));

    // 낮은 탑에 ind번째 조각을 올려놓을 때
    if(diff > arr[ind]){
        // 기존 두 탑 높이 차보다 ind번째 조각이 더 작다면
        dp[ind][diff] = std::max(dp[ind][diff], arr[ind] + search(ind+1, diff - arr[ind]));
        // 낮은 탑이 조금 더 높아졌음
    } else {
        // 기존 두 탑 높이 차보다 ind번째 조각이 더 크거나 같다면
        dp[ind][diff] = std::max(dp[ind][diff], diff + search(ind+1, arr[ind] - diff));
        // 기존에 높던 탑이 만들 수 있는 탑의 높이가 됨
    }

    return dp[ind][diff];
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    memset(dp,-1,sizeof(dp));

    std::cin >> N;

    for(int i = 0; i < N; i++){
        std::cin >> arr[i];
    }

    int res = search(0,0);

    std::cout << (res ? res : -1) << '\n';

    return 0;
}