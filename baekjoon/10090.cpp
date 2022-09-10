// Counting Inversions
// 세그먼트 트리
// inversion counting

// 7578, 1615와 유사한 풀이

#include <iostream>
#include <cmath>
#include <utility>
#include <vector>
#include <algorithm>

int N, a;
std::vector<std::pair<int, int> > line;
std::vector<long long> segTree;

long long updateTree(int node, int s, int e, int ind, int diff){
    if(ind < s || e < ind){
        return segTree[node];
    } else {
        if(s == e){
            return segTree[node] = segTree[node] + diff;
        } else {
            int mid = (s+e)/2;
            return segTree[node] = updateTree(node*2, s, mid, ind, diff) + updateTree(node*2+1, mid+1, e, ind, diff);
        }
    }
}
long long query(int node, int s, int e, int l, int r){
    if(r < s || e < l){
        return 0;
    } else {
        if(l <= s && e <= r){
            return segTree[node];
        } else {
            int mid = (s+e)/2;
            return query(node*2, s, mid, l, r) + query(node*2+1, mid+1, e, l, r);
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    int height = (int)std::ceil(log2(N));
    int size = (1 << (height + 1));
    segTree.resize(size);

    for(int i = 0; i < N; i++){
        std::cin >> a;
        line.push_back(std::make_pair(i, a));
    }

    long long ans = 0;

    for(int i = N-1; i >= 0; i--){
        ans += query(1, 1, N, 1, line[i].second-1);
        updateTree(1, 1, N, line[i].second, 1);
    }

    std::cout << ans << '\n';

    return 0;
}