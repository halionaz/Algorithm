// 트리와 색깔
// 세그먼트 트리 & 머지 소트 트리 & 오일러 경로 테크닉

// 오일러 경로 테크닉을 이용하면 간단한 머지 트리 문제로 치환이 가능함

// 오일러 경로 테크닉이란
// dfs로 트리를 순회해서 방문하는 순서대로 번호를 다시 지정해주고 
// 노드에 진입한 시점과 빠져나간 시점을 기록하여 구간을 관리하는 방법

// 트리의 각 정점에 dfs로 해당 정점을 방문한 시점(시작 번호)와
// dfs로 해당 정점이 포함된 서브 트리에 대한 탐색이 종료된 시점(끝 번호)를 기록함

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

const int mod = 1000000007;

int N, M, C, ans = 0;
int color[200001];
std::vector<int> lines[200001];
std::vector<std::vector<int> > mergeTree;

// 오일러 테크닉
int in[200001];
int out[200001];

// dfs의 각 순서에 방문한 노드의 색깔 기록
int orderColor[200001];
int ind = 0;

void dfs(int cur){
    in[cur] = ++ind;
    orderColor[ind] = color[cur];
    for(int i = 0; i < lines[cur].size(); i++){
        if(!in[lines[cur][i]]){
            dfs(lines[cur][i]);
        }
    }
    out[cur] = ind;
}

void init(int node, int s, int e){
    if(s == e){
        mergeTree[node].push_back(orderColor[s]);
    } else {
        int mid = (s + e)/2;
        init(node*2, s, mid);
        init(node*2+1, mid+1, e);

        std::vector<int> &left = mergeTree[node*2];
        std::vector<int> &right = mergeTree[node*2+1];

        // 머지소팅
        for (int i = 0, j = 0; i < left.size() || j < right.size();) {
            if(j == right.size() || (i < left.size() && left[i] < right[j])){
                mergeTree[node].push_back(left[i++]);
            } else {
                mergeTree[node].push_back(right[j++]);
            }
        }
    }
}

int query(int node, int s, int e, int l, int r, int val){
    if(r < s || e < l){
        return 0;
    } else {
        if(l <= s && e <= r){
            return std::upper_bound(mergeTree[node].begin(), mergeTree[node].end(), val) - mergeTree[node].begin();
        } else {
            int mid = (s + e)/2;
            return query(node*2, s, mid, l, r, val) + query(node*2+1, mid+1, e, l, r, val);
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M >> C;

    int height = (int)std::ceil(log2(N));
    int size = (1 << (height + 1));
    mergeTree.resize(size);

    for(int i = 1; i <= N; i++){
        std::cin >> color[i];
    }

    for(int i = 0; i < N - 1; i++){
        int a, b;
        std::cin >> a >> b;
        lines[a].push_back(b);
        lines[b].push_back(a);
    }

    dfs(1);

    init(1, 1, N);

    while(M--){
        int a, b;
        std::cin >> a >> b;
        ans += query(1, 1, N, in[a], out[a], b);
        ans %= mod;
    }

    std::cout << ans << '\n';

    return 0;
}