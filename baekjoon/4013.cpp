// ATM
// 강한 연결 요소 & 다이나믹 프로그래밍
// 코사라주 알고리즘

#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>

const int maxNode = 500001;

int N,M,S,P;
std::vector<int> line[maxNode];
std::vector<int> reverseLine[maxNode];
std::vector<int> sccLine[maxNode];
bool visited[maxNode];
int scc[maxNode];
int sccCash[maxNode];
int cash[maxNode];
int ind = 0;
bool rest[maxNode];
std::stack<int> stck;
int dp[maxNode] = {0};

void DFS(int cur){
    visited[cur] = true;
    for(int i = 0; i < line[cur].size(); i++){
        if(!visited[line[cur][i]]){
            DFS(line[cur][i]);
        }
    }
    stck.push(cur);
}

void reverseDFS(int cur){
    visited[cur] = true;
    scc[cur] = ind;
    sccCash[ind] += cash[cur];
    for(int i = 0; i < reverseLine[cur].size(); i++){
        if(!visited[reverseLine[cur][i]]){
            reverseDFS(reverseLine[cur][i]);
        } else {
            if(scc[reverseLine[cur][i]] != scc[cur]){
                sccLine[scc[reverseLine[cur][i]]].push_back(scc[cur]);
            }
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    memset(sccCash,0,sizeof(sccCash));
    memset(rest,false,sizeof(rest));

    std::cin >> N >> M;

    for(int i = 0; i < M; i++){
        int a,b;
        std::cin >> a >> b;
        line[a].push_back(b);
        reverseLine[b].push_back(a);
    }

    for(int i = 0; i < N; i++){
        std::cin >> cash[i+1];
    }

    std::cin >> S >> P;

    // SCC 묶기

    memset(visited,false,sizeof(visited));

    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            DFS(i);
        }
    }

    memset(visited,false,sizeof(visited));
    
    while(!stck.empty()){
        if(!visited[stck.top()]){
            ind++;
            reverseDFS(stck.top());
        }
        stck.pop();
    }

    for(int i = 0; i < P; i++){
        int a;
        std::cin >> a;
        rest[scc[a]] = true;
    }

    // BFS로 인출 가능 최대 액수 DP
    std::queue<int> q;
    q.push(scc[S]);
    dp[scc[S]] = sccCash[scc[S]];

    int ans = 0;

    while(!q.empty()){

        int cur = q.front();
        q.pop();

        if(rest[cur]){
            // 현재 포인트에 접근 가능한 레스토랑이 있음
            ans = dp[cur] > ans ? dp[cur] : ans;
        }

        for(int i = 0; i < sccLine[cur].size(); i++){
            if(dp[cur] + sccCash[sccLine[cur][i]] > dp[sccLine[cur][i]]){
                dp[sccLine[cur][i]] = dp[cur] + sccCash[sccLine[cur][i]];
                q.push(sccLine[cur][i]);
            }
        }
    }

    std::cout << ans << '\n';

    return 0;
}