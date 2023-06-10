// 도시 왕복하기 2
// 최대 유량
// 정점 분할 & 에드몬드-카프 알고리즘

#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

const int maxN = 802;
const int infFlow = 987654321;

int N, P;

int from, to;
int capacity[maxN][maxN];
int flow[maxN][maxN];
std::vector<int> line[maxN];

// start -> end 최대 유량
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

            for(int i = 0; i < line[cur].size(); i++){
                int next = line[cur][i];
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

    std::cin >> N >> P;

    // 용량이 1인 in -> out 간선 생성
    for(int i = 1; i <= N; i++){
        line[i*2].push_back(i*2+1);
        line[i*2+1].push_back(i*2); // 역방향 간선을 걸어주어야 하므로, 존재는 하도록 함
        capacity[i*2][i*2+1] = 1;
        // 한 경로에 포함된 도시, 즉 도시 분할 간선이 다른 경로에 포함되면 안된다.
        // 즉 도시 분할 간선 하나의 용량은 1이고,
        // 1 -> 2 도시의 최대 유량을 구하면 되는 문제
    }

    for(int i = 0; i < P; i++){
        std::cin >> from >> to;
        line[from*2+1].push_back(to*2);
        line[to*2].push_back(from*2+1); // 역방향 간선을 걸어주어야 하므로, 존재는 하도록 함
        line[to*2+1].push_back(from*2); 
        line[from*2].push_back(to*2+1); // 역방향 간선을 걸어주어야 하므로, 존재는 하도록 함
        capacity[from*2+1][to*2] = infFlow;
        capacity[to*2+1][from*2] = infFlow; 
    }

    std::cout << maxFlow(1 * 2 + 1, 2 * 2) << '\n';

    return 0;
}