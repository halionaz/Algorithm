// 단절선
// 단절점과 단절선

// DFS를 통해 방문 순서를 각 노드 별로 기록해놓은 후,
// 정점 X를 기준으로, X보다 숫자가 작은 노드로 갈 수 없는 X의 자식노드로 가는 간선은
// 단절선임

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

int V, E, A, B;
int order = 1;
std::vector<int> line[100001];
int visited[100001]; // 노드에 방문 순서 기록
std::vector<std::pair<int, int> > ans;

int dfs(int cur, int par){

    visited[cur] = order;
    order += 1;

    // val은 현재 노드에서 갈 수 있는 가장 작은 방문 순서 노드
    // 현재 노드의 방문 순서 val에 기록
    int val = visited[cur];

    for(int i = 0; i < line[cur].size(); i++){

        int nextNode = line[cur][i];

        if(nextNode != par){
            if(visited[nextNode]){
                
                // 이미 방문한 노드!
                // 이 노드에서 갈 수 있는 가장 작은 방문 순서 노드 갱신
                val = std::min(val, visited[nextNode]);

            } else {

                int next = dfs(nextNode, cur);

                if(next > visited[cur]){

                    // 이 자식 노드에서 cur 노드를 거치지 않고서는 
                    // cur 노드보다 숫자가 작은 노드로 갈 수 없음

                    // 따라서 cur 노드와 자식 노드를 잇는 이 간선은
                    // 단절선임
                    
                    ans.push_back(std::make_pair(std::min(cur, nextNode), std::max(cur, nextNode)));
                }

                val = std::min(val, next);

            }
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

    dfs(1, 0);

    std::sort(ans.begin(), ans.end());

    std::cout << ans.size() << '\n';

    for(int i = 0; i < ans.size(); i++){
        std::cout << ans[i].first << ' ' << ans[i].second << '\n';
    }

    return 0;
}