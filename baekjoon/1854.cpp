// K번째 최단경로 찾기
// 데이크스트라 & 우선순위 큐

#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int N, M, K;
int a, b, c;
std::vector<std::pair<int, int> > line[1001];
std::priority_queue<int> ansPQ[1001];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> N >> M >> K;

    for(int i = 0; i < M; i++){
        std::cin >> a >> b >> c;
        line[a].push_back(std::make_pair(b, c));
    }

    // 다익스트라를 이용한 k번째 최단거리 탐색
    std::priority_queue<std::pair<int, int>,std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > pq;

    // 시작점 투입
    pq.push(std::make_pair(0, 1));
    ansPQ[1].push(0);

    while(!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for(int i = 0; i < line[cur].size(); i++){
            int next = line[cur][i].first;
            int nextCost = line[cur][i].second + cost;

            if(ansPQ[next].size() < K){
                // 아직 K번째 답이 안나왔으므로 일단 추가
                ansPQ[next].push(nextCost);
                pq.push(std::make_pair(nextCost, next));
            } else if(ansPQ[next].top() > nextCost){
                // 이미 K번째까지 들어찼으나,
                // ansPQ에 들어가있는 가장 큰 답이
                // 지금 계산중인 cost보다 크다면
                // top을 빼고 현재 값을 투입
                ansPQ[next].pop();
                ansPQ[next].push(nextCost);
                pq.push(std::make_pair(nextCost,next));
            }
        }
    }

    for(int i = 1; i <= N; i++){
        if(ansPQ[i].size() < K){
            // K번째 최단 경로가 나오지 않은 것이므로
            std::cout << "-1\n";
        } else {
            std::cout << ansPQ[i].top() << '\n';
        }
    }

    return 0;
}