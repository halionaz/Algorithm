// 사탕 줍는 로봇
// 최대 유량
// 에드몬드-카프 알고리즘

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

const int maxN = 301;
const int infFlow = 987654321;

int n, m, a, b, c;
int capacity[maxN][maxN];
int flow[maxN][maxN];
std::vector<int> way[maxN];

// start -> end로의 최대 유량을 찾아내는 함수
int maxFlow(int start, int end){

    int maxF = 0;

    while(1){
        // start 지점에서 end 지점으로 갈 수 있는 경로 탐색 반복

        std::queue<int> que;
        std::vector<int> parents(maxN, -1);

        parents[start] = start;
        que.push(start);

        // 최단으로 end에 도착할 수 있는 경로 탐색

        while(!que.empty() && parents[end] == -1){
            int cur = que.front();
            que.pop();

            for(int i = 0; i < way[cur].size(); i++){
                int next = way[cur][i];
                if(parents[next] == -1 ){
                    // 아직 탐색하지 않은 노드
                    if(capacity[cur][next] - flow[cur][next] > 0){
                        que.push(next);
                        parents[next] = cur;
                    }
                }
            }
        }

        // end로의 경로를 못찾았으면 종료
        if(parents[end] == -1){
            break;
        } else {

            int newFlow = infFlow;

            for(int i = end; i != start; i = parents[i]){
                newFlow = std::min(newFlow, capacity[parents[i]][i] - flow[parents[i]][i]);
            }

            // 유량 조정
            for(int i = end; i != start; i = parents[i]){
                flow[parents[i]][i] += newFlow;
                flow[i][parents[i]] -= newFlow; // 유량의 대칭성에 따라 역방향으로 음수 flow 발생
            }

            maxF += newFlow;
            
        }

    }

    return maxF;

}


int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;

    for(int i = 0; i < m; i++){
        std::cin >> a >> b >> c;
        way[a].push_back(b);
        way[b].push_back(a); // 역방향 간선을 걸어주어야 하므로, 존재는 하도록 함
        capacity[a][b] += c;
        capacity[b][a] += c;
    }

    std::cout << maxFlow(1, n) << '\n';

    return 0;
}