// 공장
// 세그먼트 트리

// 이런걸 inversion counting 이라고 한단다
// 사실 이게 세그먼트 트리를 이용한 inversion counting 알고리즘의 첫 문제가 되었어야 했는데
// 1615번을 이렇게 풀어버려서 두번째가 됨

#include <iostream>
#include <cmath>
#include <utility>
#include <vector>
#include <algorithm>

int N, a;
int firstRow[1000001];
std::vector<long long> arr;
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

    arr.resize(N+1);
    int height = (int)std::ceil(log2(N));
    int size = (1 << (height + 1));
    segTree.resize(size);

    for(int i = 1; i <= N; i++){
        std::cin >> a;
        firstRow[a] = i;
    }

    for(int i = 1; i <= N; i++){
        std::cin >> a;
        arr[i] = firstRow[a];
    }

    long long ans = 0;

    for(int i = N; i >= 1; i--){
        ans += query(1, 1, N, 1, arr[i]-1);
        updateTree(1, 1, N, arr[i], 1);
    }

    std::cout << ans << '\n';

    return 0;
}