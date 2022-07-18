// 친구비
// 분리 집합 

#include <iostream>

int parents[10001];
int cost[10001];

int find(int x){

    // 조상을 찾는 함수

    if(x == parents[x]){
        return x;
    } else {
        parents[x] = find(parents[x]);
        return parents[x];
    }
}

void unite(int a, int b){
    a = find(a);
    b = find(b);

    if(a != b){
        // 둘이 합치기, 단 더 친구비가 저렴한 쪽으로
        if(cost[a] < cost[b]){
            parents[b] = a;
        } else {
            parents[a] = b;
        }
    }
}

int N, M, k, v, h;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M >> k;

    for(int i = 1; i <= N; i++){
        parents[i] = i;
        std::cin >> cost[i];
    }

    for(int i = 0; i < M; i++){
        std::cin >> v >> h;
        unite(v, h);
    }

    int ans = 0;

    for(int i = 1; i <= N; i++){
        int parent = find(i);
        if(i != find(0)){
            ans += cost[parent];
            unite(0, i);
        }
    }

    if(ans > k){
        std::cout << "Oh no\n";
    } else {
        std::cout << ans << '\n';
    }

    return 0;
}