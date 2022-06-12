// 퍼즐
// 너비 우선 탐색

// 그냥 단순하게 이동가능한 모든 경우를 구하는 거의 브루트포스에 가까운 접근법이나,
// 최소 이동 횟수를 구해야하므로 BFS으로 탐색하는 방식
// 답이 나올 수 없는 경우(답이 -1인 경우)엔 모든 이동 가능 경우를 조사한 것이므로
// 풀이 시간이 길어지게 됨

#include <iostream>
#include <queue>
#include <string>
#include <map>

const std::string goal = "123456780";

char inp;
std::string start = "";
std::map<std::string, int> visited; // 방문 여부와 함께 이동 횟수 저장

int moveX[4] = {0,0,1,-1};
int moveY[4] = {1,-1,0,0}; 

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    for(int i = 0; i < 9; i++){
        std::cin >> inp;
        start += inp;
    }

    std::queue<std::string> que;

    que.push(start);
    visited[start] = 0;

    while(!que.empty()){
        std::string cur = que.front();
        que.pop();

        if(cur == goal){
            break;
        }

        int empt = cur.find('0');
        int x = empt % 3;
        int y = empt / 3;

        for(int i = 0; i < 4; i++){

            int nextX = x + moveX[i];
            int nextY = y + moveY[i];

            if(0 <= nextX && nextX < 3 && 0 <= nextY && nextY < 3){
                std::string next = cur;
                std::swap(next[empt], next[nextY*3 + nextX]);

                if(visited.find(next) == visited.end()){
                    visited[next] = visited[cur] + 1;
                    que.push(next);
                }
            }
        }
    }

    if(visited.find(goal) == visited.end()){
        std::cout << -1 << '\n';
    } else {
        std::cout << visited[goal] << '\n';
    }

    return 0;
}