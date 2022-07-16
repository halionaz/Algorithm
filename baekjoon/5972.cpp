// 택배 배송
// 데이크스트라

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

const int inf = 987654321;

int N, M;
int a, b, c;
int memo[50001];
std::vector<std::pair<int, int> > line[50001];
std::priority_queue<std::pair<int, int> > pq;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    for(int i = 0; i < 50001; i++){
        memo[i] = inf;
    }

    std::cin >> N >> M;

    for(int i = 0; i < M; i++){
        std::cin >> a >> b >> c;
        line[a].push_back(std::make_pair(b, c));
        line[b].push_back(std::make_pair(a, c));
    }

    pq.push(std::make_pair(0, 1));
    memo[1] = 0;

    while(!pq.empty()){
        // 작은 애부터 꺼냈으므로 -1을 곱해줌
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

    std::cout << memo[N] << '\n';

    return 0;
}