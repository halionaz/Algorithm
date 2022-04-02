// 습격자 초라기
// 다이나믹 프로그래밍

#include <iostream>
#include <cstring>
#include <algorithm>

int T, N, W;
int arr[2][10000];
int dp[10001][3]; 
//dp[i][0] :: i-1까지 두 행 다 채우는 최소 소대
//dp[i][1] :: 0행은 i까지, 1행은 i-1까지 다 채우는 최소 소대
//dp[i][2] :: 0행은 i-1까지, 1행은 i까지 다 채우는 최소 소대

void makeDP(int s){
    for(int i = s; i < N; i++){

        //dp[i+1][0] 구하기

        dp[i+1][0] = std::min(dp[i][1]+1, dp[i][2]+1);
        if(arr[0][i] + arr[1][i] <= W){
            dp[i+1][0] = std::min(dp[i+1][0], dp[i][0]+1);
        }
        if(0 < i  && arr[0][i-1]+arr[0][i] <= W && arr[1][i-1] + arr[1][i] <= W){
            dp[i+1][0] = std::min(dp[i+1][0], dp[i-1][0] + 2);
        }

        //dp[i+1][1], dp[i+1][2] 구하기
        if(i+1 < N){
            dp[i+1][1] = dp[i+1][2] = dp[i+1][0] + 1;
            if(arr[0][i] + arr[0][i+1] <= W){
                dp[i+1][1] = std::min(dp[i+1][1],dp[i][2] + 1);
            }
            if(arr[1][i] + arr[1][i+1] <= W){
                dp[i+1][2] = std::min(dp[i+1][2], dp[i][1] + 1);
            }
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;

    while(T--){

        memset(arr,0,sizeof(arr));

        std::cin >> N >> W;

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < N; j++){
                std::cin >> arr[i][j];
            }
        }

        // 원형이 아닌 선형으로 생각하는 경우
        dp[0][0] = 0;
        dp[0][1] = dp[0][2] = 1;
        makeDP(0);
        int ans = dp[N][0];

        // 0행 0열과 0행 N-1열을 같은 소대가 맡는 경우
        if(1 < N && arr[0][0] + arr[0][N-1] <= W){
            dp[1][0] = 1;
            dp[1][1] = 2;
            dp[1][2] = arr[1][0] + arr[1][1] <= W ? 1 : 2;
            makeDP(1);
            ans = std::min(ans, dp[N-1][2] + 1);
            // 0행은 N-2까지, 1행은 N-1까지 다 채우는 최소 소대에서 0행 N-1과 0행 0열을 맡는 소대 한개 추가
        }
        if(1 < N && arr[1][0] + arr[1][N-1] <= W){
            dp[1][0] = 1;
            dp[1][1] = arr[0][0] + arr[0][1] <= W ? 1 : 2;
            dp[1][2] = 2;
            makeDP(1);
            ans = std::min(ans, dp[N-1][1] + 1);
            // 0행은 N-1까지, 1행은 N-2까지 다 채우는 최소 소대에서 1행 N-1과 1행 0열을 맡는 소대 한개 추가
        }

        if(1 < N && arr[0][0] + arr[0][N-1] <= W && arr[1][0] + arr[1][N-1] <= W){
            dp[1][0] = 0;
            dp[1][1] = dp[1][2] = 1;
            makeDP(1);
            ans = std::min(ans, dp[N-1][0] + 2);
        }

        std::cout << ans << '\n';
    }

    return 0;
}