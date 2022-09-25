// 세금
// 데이크스트라

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

struct road{
    int ind, cnt, cost;
};
struct cmp{
    bool operator()(road &a, road &b){
        return a.cost > b.cost;
    }
};

const int MAX = 987654321;
int N, M, K, S, D, a, b, w, sum = 0;
std::vector<road> roads[1001];
std::priority_queue<road, std::vector<road>, cmp> que;
// dp[i][j] :: i번째 노드를 j번개의 경로를 거쳐 이동하는 최소 비용
int dp[1001][1001]; 


void calc(){
    int result = MAX;
    for(int i = 1; i < N; i++){
        result = std::min(result, dp[D][i] + i*sum);
    }
    std::cout << result << '\n';
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M >> K;
    std::cin >> S >> D;

    for(int i = 1; i <= N; i++){
        for(int j = 0; j < N; j++){
            dp[i][j] = MAX;
        }
    }

    for(int i = 0; i < M; i++){
        std::cin >> a >> b >> w;
        roads[a].push_back({b,0,w});
        roads[b].push_back({a,0,w});
    }

    que.push({S, 0, 0});
    dp[S][0] = 0;

    // 다익스트라 알고리즘 사용
    while(!que.empty()){
        int cur = que.top().ind; // 현재 노드
        int cnt = que.top().cnt; // 현재 노드까지의 경로 개수
        int cost = que.top().cost; // 현재 노드까지의 비용
        que.pop();

        if(dp[cur][cnt] < cost){
            // 이미 더 짧은 경로가 탐색 완료됨
            continue;
        } else {
            for(int i = 0; i < roads[cur].size(); i++){
                int nextNode = roads[cur][i].ind;
                int nextCost = roads[cur][i].cost;
                if(dp[nextNode][cnt+1] > nextCost + cost){
                    dp[nextNode][cnt+1] = nextCost + cost;
                    que.push({nextNode, cnt+1, nextCost + cost});
                }
            }
        }
    }

    calc();

    while(K--){
        // 세금 인상!
        int weight;
        std::cin >> weight;
        sum += weight;
        
        calc();
    }

    return 0;
}