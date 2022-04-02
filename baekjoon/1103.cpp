// 게임 
// 다이나믹 프로그래밍 & 깊이 우선 탐색

#include <iostream>
#include <cstring>
#include <algorithm>

const int dx[4] = {1,0,0,-1};
const int dy[4] = {0,1,-1,0};

int N,M;
int board[51][51];
bool visited[51][51];
int dp[51][51];

int dfs(int i, int j){
    if( i < 1 || j < 1 || i > N || j > M || board[i][j] == 0){
        return 0;
    }
    if(visited[i][j]){
        std::cout << -1 << '\n';
        std::exit(0);
    } else {
        if(dp[i][j] != -1){
            return dp[i][j];
        } else {
            visited[i][j] = true;
            dp[i][j] = 0;
            for(int d = 0; d < 4; d++){
                int newI = i + dx[d]*board[i][j];
                int newJ = j + dy[d]*board[i][j];
                dp[i][j] = std::max( dp[i][j] , dfs(newI,newJ)+1 );
            }
            visited[i][j] = false;
            return dp[i][j];
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    memset(dp,-1,sizeof(dp));
    memset(visited,false,sizeof(visited));

    std::cin >> N >> M;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            char inp;
            std::cin >> inp;
            if(inp-'0' > 9){
                board[i][j] = 0;
            } else {
                board[i][j] = inp-'0';
            }
        }
    }

    std:: cout << dfs(1,1) << '\n';

    return 0;
}