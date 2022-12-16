// 알고리즘 수업 - 깊이 우선 탐색 4
// 깊이 우선 탐색

#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

int N, M, R;
int depth[100001];
std::vector<int> line[100001];
bool cmp(int i, int j){ return i > j; }

void dfs(int cur){

    for(int i = 0; i < line[cur].size(); i++){
        if(depth[line[cur][i]] == -1){
            depth[line[cur][i]] = depth[cur] + 1;
            dfs(line[cur][i]);
        }
    }

    return;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M >> R;

    memset(depth, -1, sizeof(depth));

    for(int i = 0; i < M; i++){
        int u, v;
        std::cin >> u >> v;
        line[u].push_back(v);
        line[v].push_back(u);
    }
    for(int i = 1; i <= N; i++){
        std::sort(line[i].begin(), line[i].end(), cmp);
    }

    depth[R] = 0;
    dfs(R);

    for(int i = 1; i <= N; i++){
        std::cout << depth[i] << '\n';
    }

    return 0;
}