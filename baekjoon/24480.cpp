// 알고리즘 수업 - 깊이 우선 탐색 2
// 깊이 우선 탐색

#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>

int N, M, R;
int u,v;
int ord = 1;
bool visited[100001];
int order[100001];
std::vector<int> line[100001];

void dfs(int node){
    visited[node] = true;
    order[node] = ord++;
    std::sort(line[node].begin(), line[node].end(), std::greater<int>());
    for(int i = 0; i < line[node].size(); i++){
        if(!visited[line[node][i]]){
            dfs(line[node][i]);
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M >> R;

    for(int i = 0; i < M; i++){
        std::cin >> u >> v;
        line[u].push_back(v);
        line[v].push_back(u);
    }

    dfs(R);

    for(int i = 1; i <= N; i++){
        std::cout << order[i] << '\n';
    }

    return 0;
}