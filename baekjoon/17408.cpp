// 수열과 쿼리 24
// 세그먼트 트리

// l-r 구간 내에서 최댓값 2개를 찾는 문제이므로
// 트리가 가장 큰 2개의 값을 저장하면 됨

#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>
#include <vector>

typedef long long ll;

int N, M, a;
std::vector<std::pair<ll, ll> > segTree;

std::pair<ll, ll> updateTree(int node, int s, int e, int ind, int val){
    if(ind < s || e < ind){
        return segTree[node];
    } else {
        if(s == e){
            segTree[node].first = val;
            segTree[node].second = 0;
            return segTree[node];
        } else {
            int mid = (s+e)/2;
            std::pair<ll, ll> left = updateTree(node*2, s, mid, ind, val);
            std::pair<ll, ll> right = updateTree(node*2+1, mid+1, e, ind, val);
            ll arr[4] = {left.first, left.second, right.first, right.second};
            std::sort(arr, arr+4, std::greater<ll>());
            segTree[node].first = arr[0];
            segTree[node].second = arr[1];
            return segTree[node];
        }
    }
}
std::pair<ll, ll> query(int node, int s, int e, int l, int r){
    if(r < s || e < l){
        return std::make_pair(0, 0);
    } else {
        if(l <= s && e <= r){
            return segTree[node];
        } else {
            int mid = (s+e)/2;
            std::pair<ll, ll> left = query(node*2, s, mid, l, r);
            std::pair<ll, ll> right = query(node*2+1, mid+1, e, l, r);
            ll arr[4] = {left.first, left.second, right.first, right.second};
            std::sort(arr, arr+4, std::greater<ll>());
            return std::make_pair(arr[0], arr[1]);
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

    for(int i = 1; i <= N; i++){
        std::cin >> a;
        updateTree(1, 1, N, i, a);
    }

    std::cin >> M;

    for(int i = 0; i < M; i++){
        int l, r;
        std::cin >> a >> l >> r;

        if(a == 1){
            updateTree(1, 1, N, l, r);
        } else {
            std::pair<ll, ll> res = query(1, 1, N, l, r);
            std::cout << res.first + res.second << '\n';
        }
    }

    return 0;
}