// 방법을 출력하지 않는 숫자 맞추기
// 다이나믹 프로그래밍

#include <stdio.h>
#include <cstring>

int N, ans;
int A[10001];
int B[10001];
int dp[10001][10];
// A -> B

int min(int a, int b){
    return a<b?a:b;
}

int main(){

    memset(dp,9999999,sizeof(dp));

    scanf("%d",&N);

    for(int i = 1; i <= N; i++){
        scanf("%1d",&A[i]);
    }
    for(int i = 1; i <= N; i++){
        scanf("%1d",&B[i]);
    }
    for(int i = 0; i < 10; i++){
        dp[0][i] = i;
    }

    for(int i = 1; i <= N; i++){
        for(int j = 0; j < 10; j++){
            // j는 그 전 꺼 돌린 횟수
            
            int left = (B[i] - A[i] - j + 20) % 10;
            int right = 10 - left;
            dp[i][(j+left)%10] = min(dp[i][(j+left)%10],dp[i-1][j]+left); // 왼쪽으로 돌리기
            dp[i][j] = min(dp[i][j],dp[i-1][j]+right); // 오른쪽으로 돌리기
        }
    }

    int ans = dp[N][0];
    for(int i = 1; i < 10; i++){
        ans = min(ans,dp[N][i]);
    }

    printf("%d\n",ans);

    return 0;
}