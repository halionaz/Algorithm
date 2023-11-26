// 파티
// 최대 유량
// 에드몬드-카프 알고리즘

// 제한 사항이 총 3가지가 있음
// 1. 한 사람이 가져갈 수 있는 최대 접시는 K개로 한정
// 2. 한 사람이 가져갈 수 있는 메뉴 당 최대 접시는 1개로 한정 (한 메뉴 당 하나씩 밖에 못 가져감)
// 3. 파티 전체에 메뉴 당 접시 개수 제한이 있음

// 네트워크 플로우로 해결하며,
// start -> 사람노드 -> 음식노드 -> end(파티)로 그래프 구성
// 이때, start -> 사람 노드 사이에는 한 사람이 가져갈 수 있는 최대 접시의 개수로 용량을 설정하고
// 사람 -> 음식 노드 사이에는 용량을 1로 설정하며 (메뉴 당 할당치)
// 음식 노드 -> end 사이에는 파티 전체의 메뉴 당 할당치로 용량을 설정하여
// 최대 유량을 구하면 됨

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

const int maxN = 304;
const int infFlow = 999999;

// Start = 0, End = 301
// 사람은 1 ~ 200 넘버링,
// 음식 메뉴는 201 ~ 300 넘버링
int S = 0, E = 301;
const int bias = 200; 

int N, K, D;
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
                if(parents[next] == -1){
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

    std::cin >> N >> K >> D;

    for(int i = bias + 1; i <= bias + D; i++){
        // i 메뉴 당 파티에 할당된 양
        // 음식 -> End 용량
        std::cin >> capacity[i][E];
        line[i].push_back(E);
        line[E].push_back(i);
    }

    for(int i = 1; i <= N; i++){
        // i 사람이 요리할 수 있는 메뉴 종류
        int z;
        std::cin >> z;
        
        // S -> 사람 용량
        capacity[S][i] = K;
        line[S].push_back(i);
        line[i].push_back(S);

        for(int j = 0; j < z; j++){
            int menu;
            std::cin >> menu;
            menu += bias;

            // 사람 -> 음식 용량

            capacity[i][menu] = 1;
            line[i].push_back(menu);
            line[menu].push_back(i);

        }
    }

    std::cout << maxFlow(S, E) << '\n';

    return 0;
}