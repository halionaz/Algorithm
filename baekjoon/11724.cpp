// 연결 요소의 개수
// 깊이 우선 탐색

#include <iostream>
#include <vector>

int N,M;
std::vector<int> line[1001];
int visited[1001];
void dfs(int node){
    visited[node] = 1;
    for(int i = 0; i < line[node].size(); i++){
        if(!visited[line[node][i]]){
            dfs(line[node][i]);
        }
    }
}
int main(){
    std::cin >> N >> M;
    int a,b;
    for(int i = 0; i < M; i++){
        std::cin >> a >> b;
        line[a].push_back(b);
        line[b].push_back(a);
    }
    int ans = 0;
    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            dfs(i);
            ans++;
        }
    }
    std::cout<<ans<<'\n';
    return 0;
}