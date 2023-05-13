// 구간 합 최대? 2
// 세그먼트 트리 & 분할 정복

// 분할정복 개념을 적용한 세그 노드에 관련된 설명은 16993.cpp를 참조

// Ai = U × Ki + V 로 정의하면
// U × (Ki + Ki + 1 + ... + Kj) + V × (j - i)
// = Ai + ... + Aj - V 이므로
// 이 값에 대한 금광 세그 적용

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long ll;
const ll inf = 998877665544332211;

struct segNode{
    ll sum, left, right, mid;
};

int N, Q;
ll U, V;
ll arr[100001];

// 분할정복 적용할 세그트리
std::vector<segNode> segTree;

segNode updateTree(int node, int s, int e, int ind, ll val){
    if(ind < s || e < ind){
        return segTree[node];
    } else {
        if(s == e){
            return segTree[node] = {val, val, val, val};
        } else {
            int mid = (s+e)/2;
            segNode left = updateTree(node*2, s, mid, ind, val);
            segNode right = updateTree(node*2+1, mid+1, e, ind, val); 

            segTree[node].sum = left.sum + right.sum;
            segTree[node].left = std::max(left.left, left.sum + right.left);
            segTree[node].right = std::max(right.right, right.sum + left.right);
            segTree[node].mid = std::max(std::max(right.mid, left.mid), left.right + right.left);
            return segTree[node];
        }
    }
}

segNode query(int node, int s, int e, int l, int r){
    if(r < s || e < l){
        return {0, -inf, -inf, -inf};
    } else {
        if(l <= s && e <= r){
            return segTree[node];
        } else {
            int mid = (s+e)/2;
            segNode left = query(node*2, s, mid, l, r);
            segNode right = query(node*2+1, mid+1, e, l, r); 

            segNode ret;
            ret.sum = left.sum + right.sum;
            ret.left = std::max(left.left, left.sum + right.left);
            ret.right = std::max(right.right, right.sum + left.right);
            ret.mid = std::max(std::max(right.mid, left.mid), left.right + right.left);

            return ret;
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> Q >> U >> V;

    // 크기 지정
    int height = (int)std::ceil(log2(N));
    int size = (1<<(height+1));
    segTree.resize(size);

    for(int i = 1; i <= N; i++){
        std::cin >> arr[i];
        arr[i] *= U;
        arr[i] += V;
        updateTree(1, 1, N, i, arr[i]);
    }

    while(Q--){
        int c;
        ll a, b;
        std::cin >> c >> a >> b;

        if(c == 0){
            // 첫번째 쿼리
            std::cout << query(1, 1, N, a, b).mid - V << '\n';
        } else {
            // 두번째 쿼리
            arr[a] = U * b + V;
            updateTree(1, 1, N, a, arr[a]);
        }
    }

    return 0;
}