// 트리
// 분리 집합

// Query를 역으로 받아서
// 간선을 제거하는 것 대신 간선을 붙여주는 과정 진행

#include <iostream>
#include <stack>

int N, Q;
int ancestor[200001];
int parent[200001];
int query[400010][3];
std::stack<bool> ans;

int find(int x){
    if(x == ancestor[x]){
        return x;
    } else {
        return ancestor[x] = find(ancestor[x]);
    }
}

void unite(int a, int b){
    a = find(a);
    b = find(b);

    if(a != b){
        if(a < b){
            ancestor[b] = a;
        } else {
            ancestor[a] = b;
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    for(int i = 0; i <= 200000; i++){
        ancestor[i] = i;
    }

    std::cin >> N >> Q;

    parent[1] = 1;
    for(int i = 2; i <= N; i++){
        std::cin >> parent[i];
    }

    for(int i = 0; i < Q + N - 1; i++){
        std::cin >> query[i][0];
        if(query[i][0]){
            std::cin >> query[i][1] >> query[i][2];
        } else {
            std::cin >> query[i][1];
        }
    }

    for(int i = Q + N - 2; i >=0; i--){
        if(query[i][0]){
            // 1 :: query
            // 같은 트리에 포함되어있으면 가능, 아니면 불가
            if(find(query[i][1]) == find(query[i][2])){
                ans.push(true);
            } else {
                ans.push(false);
            }
        } else {
            // 0 :: 간선 제거
            // 역순으로 진행중이므로, 다시 이어붙이는 작업 진행
            unite(query[i][1], parent[query[i][1]]);
        }
    }

    while(!ans.empty()){
            std::cout << (ans.top() ? "YES" : "NO") << '\n';
            ans.pop();
    }

    return 0;
}