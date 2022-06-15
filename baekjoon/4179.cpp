// 불!
// 너비 우선 탐색

// 주의할 점! 
// 불이 시작한 곳이 한곳이 아닐 수도 있음...
// 이 조건 때문에 input 받을 때 fire을 매번 체크하고 큐에 넣어줘야 함
// 이거 때문에 헤맸다,,

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

const int inf = 2147483640;

int R,C;
char maze[1000][1000];
int fireArrival[1000][1000];
bool visited[1000][1000];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> R >> C;

    std::vector<int> jihoonStart(3);
    std::queue<std::pair<int, int> > que;

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            std::cin >> maze[i][j];
            fireArrival[i][j] = inf;
            if(maze[i][j] == 'J'){
                jihoonStart[0] = i;
                jihoonStart[1] = j;
                jihoonStart[2] = 0;
            } else if (maze[i][j] == 'F'){
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

            if(0 <= next.first && next.first < R && 0 <= next.second && next.second < C){
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

    std::queue<std::vector<int> > jihoonQue;
    jihoonQue.push(jihoonStart);
    visited[jihoonStart[0]][jihoonStart[1]] = true;

    while(!jihoonQue.empty()){
        std::vector<int> cur = jihoonQue.front();
        // cur[0],cur[1] 좌표에 있고, 이 좌표에 도달한 타이밍은 cur[2]
        jihoonQue.pop();

        if(cur[0] == 0 || cur[1] == 0 || cur[0] == R-1 || cur[1] == C-1){
            std::cout << cur[2]+1 << '\n';
            return 0;
        }

        for(int i = 0; i < 4; i++){
            std::vector<int> next = {cur[0]+dx[i], cur[1]+dy[i], cur[2]+1};
            
            if(0 <= next[0] && next[0] < R && 0 <= next[1] && next[1] < C){
                if(maze[next[0]][next[1]] != '#' && !visited[next[0]][next[1]]){
                    if(fireArrival[next[0]][next[1]] > next[2]){
                        visited[next[0]][next[1]] = true;
                        jihoonQue.push(next);
                    }
                }
            }
        }
    }

    std::cout << "IMPOSSIBLE\n";

    return 0;
}

