// 도미노
// 강한 연결 요소

#include <iostream>
#include <cstring>
#include <vector>
#include <stack>

const int maxNum = 100001;

int T, N, M;
std::vector<int> line[maxNum];
std::stack<int> S;
bool visited[maxNum];

void sccdfs(int cur){
    if(visited[cur]){
        return;
    } else {
        visited[cur] = true;
        for(int i = 0; i < line[cur].size(); i++){
            sccdfs(line[cur][i]);
        }
        S.push(cur);
        return;
    }
}

void dfs(int cur){
    visited[cur] = true;
    for(int i = 0; i < line[cur].size(); i++){
        if(!visited[line[cur][i]]){
            dfs(line[cur][i]);
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;

    while(T--){

        std::cin >> N >> M;
        
        // 초기화
        memset(visited,false,sizeof(visited));
        for(int i = 1; i <= N; i++){
            line[i].clear();
        }
        while(!S.empty()) S.pop();

        // 블럭 사이 관계 입력 받기
        for(int i = 0; i < M; i++){
            int x,y;
            std::cin >> x >> y;
            line[x].push_back(y);
        }

        for(int i = 1; i <= N; i++){
            sccdfs(i);
        }

        memset(visited,false,sizeof(visited));
        int ans = 0;
        while(!S.empty()){
            int cur = S.top();
            S.pop();
            if(!visited[cur]){
                ans++;
                dfs(cur);
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}