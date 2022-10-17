// 숫자 맞추기
// 다이나믹 프로그래밍
// bottom-up

#include <stdio.h>
#include <cstring>

int N, ans;
int A[10001];
int B[10001];
int dp[10001][10]; 
// dp[i][j] :: i번째 돌림판을 보고 있을 때(i-1번째까진 다 맞춰짐), 
// 지금까지 왼쪽으로 j번 돌아갔을 때의 최소 경우의 수

int answerDP[10001][10][2];

void backTrack(int i, int j){
    if(i != 1){
        backTrack(i-1,answerDP[i][j][1]);
    }
    if(answerDP[i][j][0]){
        // 안돌려도 되는 경우 답에 출력하지 않음
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
            
            // i번째 돌림판을 목표하는 숫자로 하기위해
            // 왼쪽/오른쪽으로 돌려야하는 횟수 계산

            // 이미 j번 왼쪽으로 돌아가서 커졌으므로 이를 감안해 계산
            int left = (B[i] - A[i] - j + 20) % 10;
            int right = 10 - left;

            if(dp[i-1][j] + left < dp[i][(j+left)%10]){
                // 왼쪽으로 돌리기
                dp[i][(j+left)%10] = dp[i-1][j] + left;
                answerDP[i][(j+left)%10][0] = left; // 0에는 돌린 횟수
                answerDP[i][(j+left)%10][1] = j; // 1에는 백트래킹을 위해 그 윗판 정보를 남겨줌
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