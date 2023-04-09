// 탐사
// 벨만-포드
// difference_constraints_system

// xj - xi <= b 식의 부등식이 여러개 있을 때, 
// 가중치가 b인 i->j 간선을 만드는 식으로 그래프를 구성한 뒤 i에 대해 벨만-포드 알고리즘을 적용하면, 
// xj = xi + 최단경로(i->j)가 되는데, 이 때 최단경로는 b보다 작거나 같으므로 xj - xi <= b를 항상 만족

// 이 문제에서는 
// pSum[i] :: 1 ~ i 까지의 물체 개수
// 로 정의하면 pSum[x]를 각 노드로 하는 그래프를 제작할 수 있음

// probe[x, y] = r이 주어졌을 때
// pSum[y] - pSum[x-1] = r 로 치환 가능하고 (가중치가 r인 x-1 -> y 간선, 가중치가 -r인 y -> x-1 간선)

// 한 곳에는 반드시 0개나 1개의 물체가 있으므로
// 1 >= pSum[x+1] - pSum[x] >= 0 이므로 이 정보들로 간선 연결

#include <iostream>
#include <vector>

struct line{
    int x, y, r;
};

const int inf = 987654321;

int K, N;
std::vector<line> lines;
// dist[i] :: start 노드부터 i까지 최단 거리
int dist[1002];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> K >> N;

    while(N--){
        int x, y, r;
        std::cin >> x >> y >> r;
        // pSum[y] - pSum[x-1] = r 정보로 간선 연결
        // 가중치가 r인 x-1 -> y 간선, 가중치가 -r인 y -> x-1 간선
        line l1 = {x-1, y, r};
        line l2 = {y, x-1, -r};
        lines.push_back(l1);
        lines.push_back(l2);
    }
    
    // 시작 지점
    int start = K + 1;

    // 1 >= pSum[x+1] - pSum[x] >= 0을 이용한 간선 연결
    for(int i = 0; i <= K; i++){
        if(i > 0){
            line l1 = {i-1, i, 1};
            line l2 = {i, i-1, 0};
            lines.push_back(l1);
            lines.push_back(l2);
        }
        // 시작 지점 연결
        line l = {start, i, 0};
        lines.push_back(l);
    }

    // 벨만 포드 알고리즘 적용
    for(int i = 0; i < 1002; i++){
        dist[i] = inf;
    }

    dist[start] = 0;

    for(int i = 0; i < K+2; i++){
        for(int j = 0; j < lines.size(); j++){
            int x = lines[j].x;
            int y = lines[j].y;
            int r = lines[j].r;
            if(dist[x] == inf){
                // 아직 시작점조차 탐색 안한 상태
                continue;
            } 
            if(dist[x] + r < dist[y]){
                dist[y] = dist[x] + r;
                if(i == K+1){
                    // 음수 사이클 발생
                    std::cout << "NONE\n";
                    return 0;
                }
            }
        }
    }

    for(int i = 1; i <= K; i++){
        if(dist[i] - dist[i-1] == 0){
            std::cout << '-';
        } else {
            std::cout << '#';
        }
    }

    std::cout << '\n';

    return 0;

}