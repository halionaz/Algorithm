// 같은 탑
// 다이나믹 프로그래밍

#include <iostream>
#include <algorithm>
#include <cstring>

const int minInf = -2147483645;

int N;
int arr[50];
int dp[50][250001];
// dp[i][j] i번째 조각까지 사용했고, 두 탑의 높이 차가 j일 때의 탑 높이 최솟값

int search(int ind, int diff){

    if((ind == N && diff) || diff > 250000){
        return minInf;
    }

    if(ind == N && !diff){
        return 0;
    }

    if(dp[ind][diff] != -1){
        return dp[ind][diff];
    }

    dp[ind][diff] = std::max(minInf, search(ind+1,diff));
    // 쓰지 않을 때

    dp[ind][diff] = std::max(dp[ind][diff], search(ind+1, diff + arr[ind]));
    // 높은 탑에 올려놓을 때

    if(diff > arr[ind]){
        dp[ind][diff] = std::max(dp[ind][diff], arr[ind] + search(ind+1, diff - arr[ind]));
    } else {
        dp[ind][diff] = std::max(dp[ind][diff], diff + search(ind+1, arr[ind] - diff));
    }
    // 낮은 탑에 올려놓을 때

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