// 로봇 조종하기
// 다이나믹 프로그래밍
// top-down

#include <iostream>
#include <cstring>

const int dx[3] = {0,1,0};
const int dy[3] = {-1,0,1};
const int min = -200000000;

int N, M;
int world[1001][1001];
int dp[1001][1001][3];
// 왼쪽, 위쪽 , 오른쪽
// 방향을 DP에 설정하지 않으면 이미 방문한 포인트가 겹칠 수 있어 DP를 쓸 수 없음
bool visited[1001][1001];

int dfs(int x, int y, int dir){
    if(x == N && y == M){
        return world[N][M];
    } else {
        if(dp[x][y][dir] != min){

            return dp[x][y][dir];

        } else {

            visited[x][y] = true;

            int cand = min;

            for(int d = 0; d < 3; d++){
                int nX = x + dx[d];
                int nY = y + dy[d];
                if(1 <= nX && nX <= N && 1 <= nY && nY <= M && !visited[nX][nY]){
                    int c = dfs(nX,nY,d);
                    if(c > cand){
                        cand = c;
                    }
                }
            }
            visited[x][y] = false;

            return dp[x][y][dir] = cand + world[x][y];

        }
        
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    memset(visited,false,sizeof(visited));

    std::cin >> N >> M;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            std::cin >> world[i][j];
            dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = min;
        }
    }

    std::cout << dfs(1,1,0) << '\n';

    return 0;
}