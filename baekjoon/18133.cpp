// 가톨릭대학교에 워터 슬라이드를??
// 강한 연결 요소

// 15783 세진 바이러스와 정확히 똑같은 문제

// 일반 SCC와 다르게 역방향 경로를 저장하지 않고
// 처음에 DFS와 stack을 이용해 들어오는 개수가 0인 것이 가장 먼저 탐색될 수 있도록 함
// 그 이후 한번 더 DFS를 실시해
// input degree가 0인 애들에 물을 붓는게
// 얼마나 많은 node를 해결할 수 있는지 보면서 개수를 센다

#include <iostream>
#include <stack>
#include <vector>
#include <cstring>

int N,M, ind = 0;
bool visited[100001];
std::vector<int> line[100001];
std::stack<int> stck;

void dfs(int cur, bool t){
    visited[cur] = true;
    for(int i = 0; i < line[cur].size(); i++){
        if(!visited[line[cur][i]]){
            dfs(line[cur][i], t);
        }
    }
    if(t) stck.push(cur);
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;

    for(int i = 0; i < M; i++){
        int x, y;
        std::cin >> x >> y;
        line[x].push_back(y);
    }

    memset(visited, false, sizeof(visited));

    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            dfs(i, true);
        }
    }

    memset(visited,false,sizeof(visited));

    while(!stck.empty()){
        if(!visited[stck.top()]){
            ind++;
            dfs(stck.top(), false);
        }
        stck.pop();
    }

    std::cout << ind << '\n';

    return 0;
}