// 파이프 옮기기 1
// 깊이 우선 탐색

// 방향
// → : 0, ↘ : 1, ↓ : 2

#include <iostream>

int N, ans = 0;
int world[17][17];


void dfs(int x, int y, int dir){

    if(x == N && y == N){
        ans += 1;
        return;
    }

    // 대각선으로 가는 경우
    if(y + 1 <= N && x + 1 <= N){
        if(world[x][y+1] != 1 && world[x+1][y] != 1 && world[x+1][y+1] != 1){
            // 벽이 없는 경우
            dfs(x+1, y+1, 1);
        }
    }

    if(dir == 0 || dir == 1){
        if(y + 1 <= N && world[x][y+1] != 1){
            dfs(x,y+1,0);
        }
    }

    if(dir == 1 || dir == 2){
        if(x + 1 <= N && world[x+1][y] != 1){
            dfs(x+1, y, 2);
        }
    }

    return;

}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            std::cin >> world[i][j];
        }
    }

    dfs(1,2,0);

    std::cout << ans << '\n';

    return 0;
}