// 해킹
// 데이크스트라

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

const int inf = 987654321;

int T, N, D, C, a, b, s;
int memo[10001];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;

    while(T--){

        std::priority_queue<std::pair<int, int> > pq;
        std::vector<std::pair<int, int> > line[10001];

        for(int i = 0; i < 10001; i++){
            memo[i] = inf;
        }

        std::cin >> N >> D >> C;

        for(int i = 0; i < D; i++){
            std::cin >> a >> b >> s;
            line[b].push_back(std::make_pair(a,s));
        }

        pq.push(std::make_pair(0,C));
        memo[C] = 0;

        while(!pq.empty()){
            int dist = pq.top().first * -1;
            int cur = pq.top().second;
            pq.pop();
            if(memo[cur] < dist){
                // 다른 노드를 경유하는 더 빠른 길을 이미 찾음
                continue;
            }
            for(int i = 0; i < line[cur].size(); i++){
                int newDist = line[cur][i].second + dist;
                if(newDist < memo[line[cur][i].first]){
                    memo[line[cur][i].first] = newDist;
                    pq.push(std::make_pair(newDist * -1, line[cur][i].first));
                }
            }
        }

        int time = 0;
        int ans = 0;

        for(int i = 1; i<= N; i++){
            if(memo[i] != inf){
                ans++;
                time = std::max(time, memo[i]);
            }
        }

        std::cout << ans << ' ' << time << '\n';
    }


    return 0;
}