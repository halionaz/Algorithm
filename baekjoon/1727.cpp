// 커플 만들기
// 정렬 & 다이나믹 프로그래밍 & 그리디 알고리즘
// bottom-up

#include <cstdlib>
#include <iostream>
#include <algorithm>

int n, m;
int male[1000], female[1000];
int dp[1001][1001];
// dp[i][j] :: i번째(명) 남자, j번째(명) 여자를 매칭할 때 성격 차이 합의 최솟값
// 만약 i와 j가 같다면, 남자와 여자의 수가 같으므로 모두가 커플이 됨
// 만약 i > j라면, 남자 몇명은 솔로로 남아야 함
// 만약 i < j라면, 여자 몇명은 솔로로 남아야 함

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;

    for(int i = 0; i < n; i++){
        std::cin >> male[i];
    }
    for(int i = 0; i < m; i++){
        std::cin >> female[i];
    }

    std::sort(male, male + n);
    std::sort(female, female + m);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            // dp[i][j] 만들기
            if(i == j){
                // 모두가 커플이 될 수 있음
                dp[i][j] = dp[i-1][j-1] + abs(male[i-1] - female[j-1]);
            } else if(i > j){
                // i번째 남자를 솔로로 남기거나, 커플로 이어줌 
                dp[i][j] = std::min(dp[i-1][j], dp[i-1][j-1] + abs(male[i-1]-female[j-1]));
            } else if(i < j){
                // j번째 여자를 솔로로 남기거나, 커플로 이어줌
                dp[i][j] = std::min(dp[i][j-1], dp[i-1][j-1] + abs(male[i-1] -female[j-1]));
            }
        }
    }

    std::cout << dp[n][m] << '\n';

    return 0;
}