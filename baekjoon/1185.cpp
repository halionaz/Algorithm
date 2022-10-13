// 유럽여행
// 최소 스패닝 트리
// 크루스칼 알고리즘

// 트리의 특정 노드에서 출발하여
// 모든 노드를 거치고 그 노드로 돌아오게 하려면
// 무조건 간선을 2번씩 지나게 됨

// 따라서 a와 b를 잇는 간선은 실제로 그 비용이 두배가 되고,
// 노드를 방문하는 비용도 있기 때문에, a와 b를 방문하는 비용까지 더해주어야 함
// a-b 간선의 비용은 (기존 cost * 2 + a + b)이고
// 이 값으로 MST 진행

// 시작도시는 방문비용을 한번 더 내야하므로 답에다 더해줌

#include <iostream>
#include <algorithm>
#include <vector>

int N, P;
int ans = 1001;
int nodeCost[10001];
int parent[10001];
std::vector<std::vector<int> > lines;

int find(int x){
    if(parent[x] == x){
        return x;
    } else {
        parent[x] = find(parent[x]);
        return parent[x];
    }
}

void unite(int x, int y){
    int xP = find(x);
    int yP = find(y);
    if(xP != yP){
        if(xP < yP){
            parent[yP] = xP;
        } else {
            parent[xP] = yP;
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    for(int i = 0; i < 10001; i++){
        parent[i] = i;
    }

    std::cin >> N >> P;

    for(int i = 1; i <= N; i++){
        std::cin >> nodeCost[i];
        ans = std::min(ans, nodeCost[i]);
    }
    for(int i = 0; i < P; i++){
        std::vector<int> line(3);
        std::cin >> line[1] >> line[2] >> line[0];
        line[0] = line[0] * 2 + nodeCost[line[1]] + nodeCost[line[2]];
        lines.push_back(line);
    }

    std::sort(lines.begin(), lines.end());

    for(int i = 0; i < lines.size(); i++){
        
        if(find(lines[i][1]) != find(lines[i][2])){
            unite(lines[i][1],lines[i][2]);
            ans += lines[i][0];
        }
    }

    std::cout << ans << '\n';

    return 0;
}