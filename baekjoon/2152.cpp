// 여행 계획 세우기
// 강한 연결 요소 & 다이나믹 프로그래밍
// 코사라주 알고리즘

#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>

const int maxNode = 10001;

int N,M,S,T;
std::vector<int> line[maxNode];
std::vector<int> reverseLine[maxNode];
std::vector<int> sccLine[maxNode];

bool visited[maxNode];
int scc[maxNode];
int sccCityCnt[maxNode];
int ind = 0;
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

    // 이 SCC에 포함된 도시 개수 업데이트
    sccCityCnt[ind] += 1;

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

    memset(sccCityCnt,0,sizeof(sccCityCnt));

    std::cin >> N >> M >> S >> T;

    for(int i = 0; i < M; i++){
        int A,B;
        std::cin >> A >> B;
        line[A].push_back(B);
        reverseLine[B].push_back(A);
    }

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

    // BFS로 여행 가능 최대 도시 개수 DP
    std::queue<int> q;
    q.push(scc[S]);
    dp[scc[S]] = sccCityCnt[scc[S]];

    int ans = 0;

    while(!q.empty()){

        int cur = q.front();
        q.pop();

        for(int i = 0; i < sccLine[cur].size(); i++){
            if(dp[cur] + sccCityCnt[sccLine[cur][i]] > dp[sccLine[cur][i]]){
                dp[sccLine[cur][i]] = dp[cur] + sccCityCnt[sccLine[cur][i]];
                q.push(sccLine[cur][i]);
            }
        }
    }

    std::cout << dp[scc[T]] << '\n';

    return 0;
}