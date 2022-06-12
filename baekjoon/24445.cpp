// 알고리즘 수업 - 너비 우선 탐색 2
// 너비 우선 탐색

#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int N, M, R;
int u, v;
int ord = 1;
bool visited[100001];
int order[100001];
std::vector<int> line[100001];
std::queue<int> que;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M >> R;

    for(int i = 0; i < M; i++){
        std::cin >> u >> v;
        line[u].push_back(v);
        line[v].push_back(u);
    }

    que.push(R);
    visited[R] = true;

    while(!que.empty()){
        int cur = que.front();
        que.pop();
        order[cur] = ord++;
        std::sort(line[cur].begin(), line[cur].end(), std::greater<int>());
        for(int i = 0; i < line[cur].size(); i++){
            if(!visited[line[cur][i]]){
                que.push(line[cur][i]);
                visited[line[cur][i]] = true;
            }
        }
    }

    for(int i = 1; i <= N; i++){
        std::cout << order[i] << '\n';
    }

    return 0;
}