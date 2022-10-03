// 단절점
// 단절점과 단절선

// 단절점 개념을 처음 사용해보는 문제

// DFS를 통해 방문 순서를 각 노드 별로 기록해놓은 후,
// 정점 X를 기준으로, X의 자식노드에서 X보다 숫자가 작은 노드로 갈 수 없다면
// X는 단절점임.
// 또한, DFS를 시작한 루트노드의 자식 수가 2개 이상이면 단절점임.

#include <algorithm>
#include <iostream>
#include <vector>

int V, E, A, B;
int order = 1;
std::vector<int> line[10001];
bool ans[10001]; // 단절점인지 여부 기록
int visited[10001]; // 노드에 방문 순서 기록

int dfs(int cur, bool root){
    visited[cur] = order;
    order += 1;

    // val은 현재 노드에서 갈 수 있는 가장 작은 방문 순서 노드
    // 현재 노드의 방문 순서 val에 기록
    int val = visited[cur];

    // 현재 노드의 자식 노드 개수
    int child = 0;

    for(int i = 0; i < line[cur].size(); i++){

        int nextNode = line[cur][i];

        if(visited[nextNode]){
            
            // 이미 방문한 노드!
            // 이 노드에서 갈 수 있는 가장 작은 방문 순서 노드 갱신
            val = std::min(val, visited[nextNode]);

        } else {

            child += 1;
            int next = dfs(nextNode, false);

            if(!root){
                // 루트 노드가 아니고
                if(next >= visited[cur]){
                    // 자식 노드들이 현재 cur 노드를 거치지 않고 
                    // cur 노드보다 숫자가 작은 노드로 갈 수 없음..

                    // 즉 단절점임
                    ans[cur] = true;
                }
            }

            val = std::min(val, next);

        }
    }

    if(root){
        // 루트 노드라면
        if(child >= 2){
            // 자식이 두개 이상이면 단절점임
            ans[cur] = true;
        }
    }

    return val;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> V >> E;

    for(int i = 0; i < E; i++){
        // 간선 기록
        std::cin >> A >> B;
        line[A].push_back(B);
        line[B].push_back(A);
    }

    // 입력값이 연결그래프가 아닐 수도 있으므로, 모든 정점에 대해 루트로 dfs 수행
    for(int i = 1; i <= V; i++){
        if(!visited[i]){
            dfs(i, true);
        }
    }

    int ansCnt = 0;

    for(int i = 1; i <= V; i++){
        if(ans[i]){
            ansCnt += 1;
        }
    }

    std::cout << ansCnt << '\n';

    for(int i = 1; i <= V; i++){
        if(ans[i]){
            std::cout << i << ' ';
        }
    }

    std::cout << '\n';

    return 0;
}