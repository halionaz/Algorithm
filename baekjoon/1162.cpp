// 도로포장
// 데이크스트라 & 다이나믹 프로그래밍

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>

typedef long long ll;
const ll inf = 1e15;

ll N, M, K;
ll a, b, t;
std::vector<std::pair<ll, ll> > line[10001];
ll dp[10001][21]; //dp[i][j] :: i번째 도시에서, j개 도로를 포장했을 때의 최소 시간

struct element{
    ll dist;
    ll index;
    ll packed;

    bool operator<(const element& a) const{
        return dist > a.dist;
    }
};

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M >> K;

    for(int i = 0; i < M; i++){
        std::cin >> a >> b >> t;
        line[a].push_back(std::make_pair(b, t));
        line[b].push_back(std::make_pair(a, t));
    }

    for(int i = 0; i < 10001; i++){
        for(int j = 0; j < 21; j++){
            dp[i][j] = inf;
        }
    }

    std::priority_queue<element> pq;

    pq.push({0, 1, 0});
    dp[1][0] = 0;

    while(!pq.empty()){
        ll time = pq.top().dist;
        ll cur = pq.top().index;
        ll curPacked = pq.top().packed;
        pq.pop();

        if(dp[cur][curPacked] < time){
            // 다른 노드를 경유하는 더 빠른 길을 이미 찾음
            continue;
        }

        for(int i = 0; i < line[cur].size(); i++){
            ll newNode = line[cur][i].first;
            ll newTime = line[cur][i].second + time;

            // 포장 안하고 스킵
            if(newTime < dp[newNode][curPacked]){
                dp[newNode][curPacked] = newTime;
                pq.push({newTime, newNode, curPacked});
            }
            // 포장
            if(curPacked < K && time < dp[newNode][curPacked + 1]){
                dp[newNode][curPacked+1] = time;
                pq.push({time, newNode, curPacked + 1});
            }
        }
    }

    ll ans = inf;

    for(int i = 0; i <= K; i++){
        ans = std::min(ans, dp[N][i]);
    }

    std::cout << ans << '\n';

    return 0;
}