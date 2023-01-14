// 전력난
// 최소 스패닝 트리
// 크루스칼 알고리즘

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

int M, N;
int parent[200001];
std::vector<std::vector<int> > road;

int find(int x){
    // x의 부모 노드를 찾는 함수
    if(parent[x] == x){
        return x;
    } else {
        parent[x] = find(parent[x]);
        return parent[x];
    }
}

void unite(int x, int y){
    // 두 노드 트리를 합치는 함수
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

    while(1){

        for(int i = 0; i < 200001; i++){
            parent[i] = i;
        }
        road.clear();

        std::cin >> M >> N;

        if(N == 0 && M == 0){
            break;
        }

        int V = 0;

        for(int i = 0; i < N; i++){
            std::vector<int> vec(3);
            std::cin >> vec[1] >> vec[2] >> vec[0];
            V += vec[0];
            road.push_back(vec);
        }

        // 거리가 짧은 순으로 정렬
        std::sort(road.begin(), road.end());

        int needV = 0;

        for(int i = 0; i < road.size(); i++){
            if(find(road[i][1]) != find(road[i][2])){
                unite(road[i][1], road[i][2]);
                needV += road[i][0];
            }
        }

        std::cout << V - needV << '\n';
    }

    return 0;
}