// 테트로미노
// 브루트포스 알고리즘

#include <iostream>

int N,M;
int paper[501][501];
int visited[501][501];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int uniqI[4][3] = {{-1,0,0},{-1,1,0},{1,0,0},{-1,1,0}}; 
int uniqJ[4][3] = {{0,1,-1},{0,0,1},{0,1,-1},{0,0,-1}};
int ans = 0; 

void dfs(int x, int y, int depth){
    if(depth == 4){
        // 테크로미노 합 최댓값 갱신
        ans = visited[x][y] > ans ? visited[x][y] : ans;
        return;
    } else {
        for(int i = 0; i < 4; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(0<=newX && newX<N && 0<= newY && newY<M){
                if(!visited[newX][newY]){
                    visited[newX][newY] += visited[x][y] + paper[newX][newY];
                    dfs(newX,newY,depth+1);
                    visited[newX][newY] = 0;
                }
            }
        }
    }
}

void unique(int x, int y){
    // ㅗ, ㅜ, ㅓ, ㅏ 모양 표현
    for(int i = 0; i < 4; i++){
        int temp = paper[x][y];
        int canMake = 1;
        for(int j = 0; j < 3; j++){
            int newX = x + uniqI[i][j];
            int newY = y + uniqJ[i][j];
            if(0<=newX && newX<N && 0<= newY && newY<M){
                temp += paper[newX][newY];
            } else {
                canMake = 0;
                break;
            }
        }
        if(canMake){
            ans = temp > ans ? temp : ans;
        }
    }
}

int main(){
    std::cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j<M; j++){
            std::cin >> paper[i][j];
            visited[i][j] = 0;
        }
    }
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            visited[i][j] = paper[i][j];
            dfs(i,j,1);
            unique(i,j);
            visited[i][j] = 0;
        }
    }
    std::cout << ans << '\n';
    return 0;
}