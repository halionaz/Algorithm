// 숫자 맞추기
// 다이나믹 프로그래밍

#include <stdio.h>
#include <cstring>

int N, ans;
int A[10001];
int B[10001];
int dp[10001][10];
// A -> B
int answerDP[10001][10][2];

void backTrack(int i, int j){
    if(i != 1){
        backTrack(i-1,answerDP[i][j][1]);
    }
    if(answerDP[i][j][0]){
        printf("%d %d\n",i,answerDP[i][j][0]);
    }
    return;
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
            if(dp[i-1][j] + left < dp[i][(j+left)%10]){
                // 왼쪽으로 돌리기
                dp[i][(j+left)%10] = dp[i-1][j] + left;
                answerDP[i][(j+left)%10][0] = left;
                answerDP[i][(j+left)%10][1] = j;
            }
            if(dp[i-1][j]+right < dp[i][j]){
                // 오른쪽으로 돌리기
                dp[i][j] = dp[i-1][j]+right;
                answerDP[i][j][0] = -right;
                answerDP[i][j][1] = j;
            }
        }
    }

    int ans = dp[N][0];
    int ansInd;
    for(int i = 1; i < 10; i++){
        if(dp[N][i] < ans){
            ans = dp[N][i];
            ansInd = i;
        }
    }
    printf("%d\n",ans);

    backTrack(N,ansInd);

    return 0;
}