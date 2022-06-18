// 불
// 너비 우선 탐색

// [4179, 불!]과 같은 문제

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <string.h>

const int inf = 999999999;

int T,W,H;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char maze[1000][1000];
int fireArrival[1000][1000];
bool visited[1000][1000];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;

    while(T--){
        memset(visited, 0, sizeof(visited));

        std::cin >> W >> H;

        std::vector<int> sangStart(3);
        std::queue<std::pair<int, int> > que;

        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                fireArrival[i][j] = inf;
                std::cin >> maze[i][j];
                if(maze[i][j] == '@'){
                    sangStart[0] = i;
                    sangStart[1] = j;
                    sangStart[2] = 0;
                } else if (maze[i][j] == '*'){
                    std::pair<int, int> fireStart;
                    fireStart.first = i;
                    fireStart.second = j;
                    que.push(fireStart);
                    fireArrival[i][j] = 0;
                }
            }
        }


        while(!que.empty()){
            
            std::pair<int, int> cur = que.front();
            que.pop();

            for(int i = 0; i < 4; i++){
                std::pair<int, int> next = std::make_pair(cur.first + dx[i], cur.second + dy[i]);

                if(0 <= next.first && next.first < H && 0 <= next.second && next.second < W){
                    if(maze[next.first][next.second] != '#'){
                        // 불이 번질 수 있음
                        if(fireArrival[next.first][next.second] > fireArrival[cur.first][cur.second] + 1){
                            // 아직 불이 도달 안한 불이 번질 수 있는 곳
                            fireArrival[next.first][next.second] = fireArrival[cur.first][cur.second] + 1;
                            que.push(next);
                        }
                    }
                }
            }
        }

        std::queue<std::vector<int> > sangQue;
        sangQue.push(sangStart);
        visited[sangStart[0]][sangStart[1]] = true;

        bool ans = false;

        while(!sangQue.empty()){
            std::vector<int> cur = sangQue.front();
            // cur[0],cur[1] 좌표에 있고, 이 좌표에 도달한 타이밍은 cur[2]
            sangQue.pop();

            if(cur[0] == 0 || cur[1] == 0 || cur[0] == H-1 || cur[1] == W-1){
                std::cout << cur[2]+1 << '\n';
                ans = true;
                break;
            }

            for(int i = 0; i < 4; i++){
                std::vector<int> next = {cur[0]+dx[i], cur[1]+dy[i], cur[2]+1};
                
                if(0 <= next[0] && next[0] < H && 0 <= next[1] && next[1] < W){
                    if(maze[next[0]][next[1]] != '#' && !visited[next[0]][next[1]]){
                        if(fireArrival[next[0]][next[1]] > next[2]){
                            visited[next[0]][next[1]] = true;
                            sangQue.push(next);
                        }
                    }
                }
            }
        }

        if(!ans){
            std::cout << "IMPOSSIBLE\n";    
        }
    }


    return 0;
}
