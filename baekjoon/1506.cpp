// 경찰서
// 강한 연결 요소

// 코사라주 알고리즘

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

typedef long long ll;

int N, ind = -1;
bool visited[101];
// int scc[101];
ll leastCost[101];
ll cost[101];
std::vector<int> line[101];
std::vector<int> rev_line[101];
std::stack<int> stck;

void dfs(int cur){
    visited[cur] = true;
    for(int i = 0; i < line[cur].size(); i++){
        if(!visited[line[cur][i]]){
            dfs(line[cur][i]);
        }
    }
    stck.push(cur);
}

void rev_dfs(int cur){
    visited[cur] = true;
    // scc[cur] = ind;
    if(cost[cur] < leastCost[ind]){
        // 이 SCC 내부에서 가장 적은 비용을 가진 도시라면, 답 갱신
        leastCost[ind] = cost[cur];
        // std::cout << cost[cur] << '\n';
    }
    for(int i = 0; i < rev_line[cur].size(); i++){
        if(!visited[rev_line[cur][i]]){
            rev_dfs(rev_line[cur][i]);
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 0; i < N; i++){
        std::cin >> cost[i];
    }

    for(int i = 0; i < N; i++){
        std::string s;
        std::cin >> s;
        for(int j = 0; j < s.length(); j++){
            if(s[j] == '1'){
                line[i].push_back(j);
                rev_line[j].push_back(i);
            }
        }
    }

    memset(visited, false, sizeof(visited));

    for(int i = 0; i < N; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    
    memset(visited, false, sizeof(visited));
    memset(leastCost, 1000000009, sizeof(leastCost));

    while(!stck.empty()){
        if(!visited[stck.top()]){
            ind++;
            rev_dfs(stck.top());
        }
        stck.pop();
    }

    ll ans = 0;

    for(int i = 0; i <= ind; i++){
        ans += leastCost[i];
    }

    std::cout << ans << '\n';

    return 0;
}