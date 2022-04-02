// 열쇠
// 너비 우선 탐색 & 시뮬레이션

#include <iostream>
#include <string>
#include <queue>
#include <cstring>

int T, H, W;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;

    while(T--){

        int ans = 0;
        char map[102][102];
        bool visited[102][102];
        bool key[26];

        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));
        memset(key, false, sizeof(key));

        std::cin >> H >> W;

        for(int i = 1; i <= H; i++){
            for(int j = 1; j <= W; j++){
                std::cin >> map[i][j];
            }
        }

        std::string first;

        std::cin >> first;

        // 가지고 있는 key 표시
        if(first != "0"){
            for(int i = 0; i < first.length(); i++){
                key[first[i] - 'a'] = 1;
            }
        }

        std::queue<std::pair<int, int> > que; // bfs용
        std::queue<std::pair<int, int> > door[26]; // 문 저장용

        que.push(std::make_pair(0, 0));
        visited[0][0] = 1;

        while(!que.empty()){
            int curX = que.front().first;
            int curY = que.front().second;
            que.pop();

            for(int d = 0; d < 4; d++){
                int newX = curX + dx[d];
                int newY = curY + dy[d];

                if(0 <= newX && newX <= H+1 && 0 <= newY && newY <= W+1){
                    if(!visited[newX][newY]){

                        visited[newX][newY] = 1;
                        char next = map[newX][newY];

                        if(next == '*'){

                            continue;

                        } else if ('A' <= next && next <= 'Z'){
                            // 문
                            if(key[next - 'A']){
                                // 탐색
                                que.push(std::make_pair(newX,newY));
                            } else {
                                // 나중을 도모
                                door[next-'A'].push(std::make_pair(newX,newY));
                            }
                        } else if ('a' <= next && next <= 'z'){
                            // 열쇠
                            if(!key[next - 'a']){
                                key[next - 'a'] = 1;
                                while(!door[next - 'a'].empty()){
                                    // 이 열쇠를 필요로 하는 문이 있다면
                                    que.push(door[next - 'a'].front());
                                    door[next - 'a'].pop();
                                }
                            }
                            que.push(std::make_pair(newX, newY));
                        } else {
                            // 빈 공간 또는 문서
                            if(map[newX][newY] == '$'){
                                ans++;
                            }
                            que.push(std::make_pair(newX, newY));
                        }

                    }
                }
            }
        }

        std::cout << ans << '\n';

    }

    return 0;
}