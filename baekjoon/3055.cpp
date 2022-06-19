// 탈출
// 너비 우선 탐색

#include <iostream>
#include <queue>
#include <vector>

const int inf = 2147483640;

int R,C;
char forest[50][50];
int waterArrived[50][50];
bool visited[50][50];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
std::pair<int, int> goal;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> R >> C;

    std::vector<int> hedgeStart(3);
    std::queue<std::pair<int, int> > que;

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            std::cin >> forest[i][j];
            waterArrived[i][j] = inf;
            if(forest[i][j] == 'S'){
                hedgeStart[0] = i;
                hedgeStart[1] = j;
                hedgeStart[2] = 0;
            } else if (forest[i][j] == '*'){
                std::pair<int, int> waterStart;
                waterStart.first = i;
                waterStart.second = j;
                que.push(waterStart);
                waterArrived[i][j] = 0;
            } else if (forest[i][j] == 'D'){
                goal = std::make_pair(i,j);
            }
        }
    }


    while(!que.empty()){
        
        std::pair<int, int> cur = que.front();
        que.pop();

        for(int i = 0; i < 4; i++){
            std::pair<int, int> next = std::make_pair(cur.first + dx[i], cur.second + dy[i]);

            if(0 <= next.first && next.first < R && 0 <= next.second && next.second < C){
                if(forest[next.first][next.second] != 'X' && forest[next.first][next.second] != 'D'){
                    // 홍수 가능
                    if(waterArrived[next.first][next.second] > waterArrived[cur.first][cur.second] + 1){
                        waterArrived[next.first][next.second] = waterArrived[cur.first][cur.second] + 1;
                        que.push(next);
                    }
                }
            }
        }
    }

    std::queue<std::vector<int> > hedgeQue;
    hedgeQue.push(hedgeStart);
    visited[hedgeStart[0]][hedgeStart[1]] = true;

    while(!hedgeQue.empty()){
        std::vector<int> cur = hedgeQue.front();
        // cur[0],cur[1] 좌표에 있고, 이 좌표에 도달한 타이밍은 cur[2]
        hedgeQue.pop();

        if(cur[0] == goal.first && cur[1] == goal.second){
            std::cout << cur[2] << '\n';
            return 0;
        }

        for(int i = 0; i < 4; i++){
            std::vector<int> next = {cur[0]+dx[i], cur[1]+dy[i], cur[2]+1};
            
            if(0 <= next[0] && next[0] < R && 0 <= next[1] && next[1] < C){
                if(forest[next[0]][next[1]] != 'X' && !visited[next[0]][next[1]]){
                    if(waterArrived[next[0]][next[1]] > next[2]){
                        visited[next[0]][next[1]] = true;
                        hedgeQue.push(next);
                    }
                }
            }
        }
    }

    std::cout << "KAKTUS\n";

    return 0;
}

