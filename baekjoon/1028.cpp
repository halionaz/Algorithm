// 다이아몬드 광산
// 다이나믹 프로그래밍

// 참고한 블로그에서는 모든 방향을 저장한 후
// 각 좌표에 대해 그 좌표가 다이아의 가장 위 꼭짓점인 경우와 가장 왼쪽 꼭짓점인 경우를 둘 다 계산했는데
// 굳이 둘다 계산할 필요 없이 모든 다이아는 결국 위 꼭짓점을 가지게 되므로
// 가장 왼쪽 꼭짓점인 경우를 생략하고 위 꼭짓점인 경우만 따져줘도 모든 다이아 탐색 가능

#include <algorithm>
#include <stdio.h>

typedef long long int ll;

ll R, C, i, j, k;

// memo는 각 좌표의 왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래로 뻗어나갈 수 있는 대각선 저장
// memo[i][j][k]
// (i,j)에서 k 방향으로 뻗을 수 있는 최대 대각선 길이
// k = 0 - 왼쪽위 :: 1 - 오른쪽위 :: 2 - 왼쪽 아래 :: 3 - 오른쪽 아래
ll memo[800][800][4];
ll mine[1510][1510];

int main(){

    scanf("%lld %lld", &R, &C);

    for(i = 1; i <= R; i++){
        for(j = 1; j <= C; j++){
            scanf("%1lld", &mine[i][j]);
        }
    }

    // 왼쪽 위와 오른쪽 위로 뻗어 나갈 수 있는 대각선 길이 계산
    for(i = 1; i <= R; i++){
        for(j = 1; j <= C; j++){
            if(mine[i][j]){
                memo[i][j][0] = memo[i-1][j-1][0] + 1;
                memo[i][j][1] = memo[i-1][j+1][1] + 1;
            }
        }
    }

    // 왼쪽 아래와 오른쪽 아래로 뻗어 나갈 수 있는 대각선 길이 계산
    for(i = R; i > 0; i--){
        for(j = 1; j <= C; j++){
            if(mine[i][j]){
                memo[i][j][2] = memo[i+1][j-1][2] + 1;
                memo[i][j][3] = memo[i+1][j+1][3] + 1;
            }
        }
    }

    ll ans = 0;

    for(i = 1; i <= R; i++){
        for(j = 1; j <= C; j++){
            for(k = 1; k <= std::min(memo[i][j][2], memo[i][j][3]); k++){
                // (i,j)가 다이아몬드의 제일 위쪽 꼭짓점일 경우
                if(mine[i + (k-1)*2][j] && memo[i + (k-1)*2][j][0] >= k && memo[i + (k-1)*2][j][1] >= k){
                    // 아래 꼭짓점의 양 위쪽 대각선이 모두 k보다 길거나 같다면 다이아 성립
                    ans = std::max(ans, k);
                }
            }
        }
    }

    printf("%lld", ans);

    return 0;
}