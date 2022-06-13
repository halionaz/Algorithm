// 말이 되고픈 원숭이
// 너비 우선 탐색

// 이번 문제에선 이미 탐색한 정점이더라도 그냥 지나치면 안된다!
// 같은 visited이더라도 능력 사용 횟수가 다를 수 있기 때문
// 따라서 visited를 설계할 때, 능력 사용 횟수까지 넣어서 구현해야된다.

#include <iostream>
#include <queue>
#include <vector>

int K, W, H;
bool board[201][201]; // board[H-1][W-1]
int visited[201][201][31]; // visited[i][j][k], (i,j) 칸을 능력을 k번 써서 왔을 때의 전체 횟수

int moveX[4] = {0, 0, 1, -1};
int moveY[4] = {1, -1, 0, 0};
int abilityX[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int abilityY[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> K >> W >> H;

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            std::cin >> board[i][j];
        }
    }

    std::queue<std::vector<int> > que;
    std::vector<int> start = {0, 0, 0};
    que.push(start);

    while(!que.empty()){
        std::vector<int> cur = que.front();
        que.pop();

        if(cur[0] == H-1 && cur[1] == W-1){
            std::cout << visited[cur[0]][cur[1]][cur[2]] << '\n';
            return 0;
        }

        for(int i = 0; i < 4; i++){
            // 기본 이동기
            int newX = cur[0] + moveX[i];
            int newY = cur[1] + moveY[i];

            if(0 <= newX && newX < H && 0 <= newY && newY < W){
                if(!board[newX][newY] && !visited[newX][newY][cur[2]]){
                    visited[newX][newY][cur[2]] = visited[cur[0]][cur[1]][cur[2]] + 1;
                    std::vector<int> next = {newX, newY, cur[2]};
                    que.push(next);
                }
            }


        }

        if(cur[2] < K){
            // 능력 사용 가능
            for(int i = 0; i < 8; i++){

                int newX = cur[0] + abilityX[i];
                int newY = cur[1] + abilityY[i];

                if(0 <= newX && newX < H && 0 <= newY && newY < W){
                    if(!board[newX][newY] && !visited[newX][newY][cur[2] + 1]){
                        visited[newX][newY][cur[2]+1] = visited[cur[0]][cur[1]][cur[2]] + 1;
                        std::vector<int> next = {newX, newY, cur[2]+1};
                        que.push(next);
                    }
                }
            }
        }

    }

    std::cout << -1 << '\n';

    return 0;
}