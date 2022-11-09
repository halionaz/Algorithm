// 집배원 한상덕
// 깊이 우선 탐색 & 두 포인터 & 매개 변수 탐색

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <string.h>

const int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
const int dy[8] = {0, 0, 1, -1, 1, 1, -1, -1};

int N, C, left, right;
int ans = 1000001;
char position[51][51];
int altitude[51][51];
std::vector<int> alt;
std::pair<int, int> startPos;
bool visited[51][51];

void dfs(int x, int y){

    visited[x][y] = true;
    if(position[x][y] == 'K'){
        C++;
    }

    for(int i = 0; i < 8; i++){
        int newX = x + dx[i];
        int newY = y + dy[i];
        if(newX >= 0 && newY >= 0 && newX < N && newY < N){
            // 맵 내에 있을 때,
            if(!visited[newX][newY]){
                // 아직 방문하지 않았을 때,
                int cur = altitude[newX][newY];
                if(alt[left] <= cur && cur <= alt[right]){
                    // 현재 탐색 고도 범위 내에 있을 때
                    dfs(newX, newY);
                }
            }
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    int houseCnt = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            std::cin >> position[i][j];
            if(position[i][j] == 'P'){
                startPos = std::make_pair(i, j);
            } else if(position[i][j] == 'K'){
                houseCnt++;
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            std::cin >> altitude[i][j];
            // 포인터 탐색을 위한 고도 배열
            alt.push_back(altitude[i][j]);
        }
    }

    // 정렬 후, 중복된 고도 제거
    std::sort(alt.begin(), alt.end());
    alt.erase(std::unique(alt.begin(), alt.end()), alt.end());


    // 정렬된 고도값으로 답을 추론 후 탐색
    left = 0;
    right = 0;
    int maxInd = alt.size();

    while(right < maxInd){

        // 이번 탐색에서의 집 개수
        C = 0; 
        memset(visited, 0, sizeof(visited));

        if(alt[left] <= altitude[startPos.first][startPos.second] && altitude[startPos.first][startPos.second] <= alt[right]){
            // 시작점 가능
            // 계산 시작
            dfs(startPos.first, startPos.second);

        }

        if(houseCnt == C){
            // 답 만족
            ans = std::min(ans, alt[right] - alt[left]);
            left++;

        } else {
            // 다 방문 못 함
            right++;
        }
    }

    std::cout << ans << '\n';

    return 0;
}