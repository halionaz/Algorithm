// 도미노
// 강한 연결 요소

// scc의 개수를 구해주되,
// 만약 scc에 묶여있진 않지만 그 scc 노드를 가리키는 외부 노드가 있다면
// 그 친구를 넘어뜨리면 되므로
// 단순 scc의 개수가 답은 아님

// indegree의 개수가 0인 scc만 넘어뜨려주면
// indegree가 존재하는 scc는 넘어진다는 사실을 알 수 있음
// 즉 들어오는 간선이 없는 scc의 개수를 구하면 됨

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

        // 스택에 얹혀있는 순서대로 탐색하면
        // indegree가 0인 노드부터 탐색 가능
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