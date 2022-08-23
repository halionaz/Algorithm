// 배열에서 이동
// 이분 탐색 & 너비 우선 탐색

#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <string.h>

int N, maxVal = -1, minVal = 201;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int map[100][100];
bool visited[100][100];

bool bfs(int ans){
    // ans 차이를 가지게 하는 답이 존재하는지 유무 판단

    std::queue<std::pair<int, int> > que;

    for(int mn = minVal; mn <= maxVal; mn++){

        memset(visited, true, sizeof(visited));
        // 일단 다 가능하게 만들어 둠,
        // 이제 ans만큼의 간극 내의 좌표들만 남겨둠
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(mn <= map[i][j] && map[i][j] <= mn + ans){
                    visited[i][j] = false;
                }
            }
        }

        // // 이제 남아있는 노드를 이용해 bfs를 진행하여,
        // // ans차이가 가능한지 판단

        que.push(std::make_pair(0, 0));

        while(!que.empty()){
            int x = que.front().first;
            int y = que.front().second;
            que.pop();

            // 이 방문 판단을 그 전 노드에서 해줘도 되지만
            // (0, 0)이 방문 불가능한 놈(값 범위에 들지 않음)일 수도 있기에 이런식으로 전처리로 해줌
            if(visited[x][y]){
                // 이미 방문한 놈이라면
                continue;
            }

            visited[x][y] = true;

            if(x == N - 1 && y == N - 1){
                return true;
            }

            for(int d = 0; d < 4; d++){
                int newX = x + dx[d];
                int newY = y + dy[d];

                if(0 <= newX && newX < N && 0 <= newY && newY < N){
                    que.push(std::make_pair(newX, newY));
                }
            }
        }
    }

    // 모든 경우의 수를 돌아봤음에도 불가능
    return false;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;


    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            std::cin >> map[i][j];
            maxVal = std::max(maxVal, map[i][j]);
            minVal = std::min(minVal, map[i][j]);
        }
    }

    int left = 0;
    int right = maxVal - minVal;
    // left ~ right 사이에 답이 존재함

    int mid;

    while(left <= right){
        mid = (left + right) / 2;

        if(bfs(mid)){
            // 이게 되네?
            // 더 줄여!
            right = mid-1;
        } else {
            left = mid + 1;
        }
    }

    std::cout << right + 1 << '\n';

    return 0;
}