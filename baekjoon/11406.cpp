// 책 구매하기 2
// 최대 유량
// 에드몬드-카프 알고리즘

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

const int maxN = 204;
const int infFlow = 987654321;

int N, M;
int S = 0, E = 201; // 서점은 1 ~ 100 넘버링, 사람은 101 ~ 200 넘버링
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

    std::cin >> N >> M;

    for(int i = 101; i <= N + 100; i++){
        // 각 사람이 사려고 하는 책 개수
        // 사람 -> End 간선의 용량으로 설정
        std::cin >> capacity[i][E];
        line[i].push_back(E);
        line[E].push_back(i);
    }
    for(int i = 1; i <= M; i++){
        // 각 서점이 가지고 있는 책의 개수
        // Start -> 서점 간선의 용량으로 설정
        std::cin >> capacity[S][i];
        line[S].push_back(i);
        line[i].push_back(S);
    }

    for(int i = 1; i <= M; i++){
        for(int j = 101; j <= N + 100; j++){
            std::cin >> capacity[i][j];
            line[i].push_back(j);
            line[j].push_back(i);
        }
    }

    std::cout << maxFlow(S, E) << '\n';

    return 0;
}
