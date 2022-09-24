// 네트워크 연결
// 최소 스패닝 트리
// 크루스칼 알고리즘

#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
std::vector<std::vector<int> > line;
int parent[1001];

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

    for(int i = 0; i < 1001; i++){
        parent[i] = i;
    }

    std::cin >> N >> M;

    int ans = 0;

    for(int i = 0; i < M; i++){
        std::vector<int> vec(3);
        std::cin >> vec[1] >> vec[2] >> vec[0];

        line.push_back(vec);
    }

    // 비용이 적은 순으로 정렬
    std::sort(line.begin(), line.end());

    for(int i = 0; i < line.size(); i++){
        
        if(find(line[i][1]) != find(line[i][2])){
            unite(line[i][1],line[i][2]);
            ans += line[i][0];
        }
    }

    std::cout << ans << '\n';

    return 0;
}