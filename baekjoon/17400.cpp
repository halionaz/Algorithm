// 깃발춤
// 세그먼트 트리

// 홀수 공연자와 짝수 공연자를 따로 나눠 세그먼트 트리에 담음

#include <algorithm>
#include <cstdlib>
#include <iostream>

typedef long long ll;

int N, Q, c;
ll oddSegTree[1500000];
ll evenSegTree[1500000];

ll updateTree(int node, int s, int e, int ind, ll diff) {
    if (ind < s || e < ind) {
        if (ind % 2 == 0){
            return evenSegTree[node];
        } else {
            return oddSegTree[node];
        }
    } else {
        if (s == e) {
            if (ind % 2 == 0){
                return evenSegTree[node] += diff;
            } else {
                return oddSegTree[node] += diff;
            }
        } else {
            int mid = (s + e) / 2;
            ll ret = updateTree(node * 2, s, mid, ind, diff) + updateTree(node * 2 + 1, mid + 1, e, ind, diff);
            if (ind % 2 == 0) {
                return evenSegTree[node] = ret;
            } else {
                return oddSegTree[node] = ret;
            }
        }
    }
}

ll query(ll *segTree, int node, int s, int e, int l, int r) {
    if (r < s || e < l){
        return 0;
    } else {
        if (l <= s && e <= r) {
            return segTree[node];
        } else {
            int mid = (s + e) / 2;
            return query(segTree, node * 2, s, mid, l, r) + query(segTree, node * 2 + 1, mid + 1, e, l, r);
        }
    }
}

int main() {

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        std::cin >> c;
        updateTree(1, 1, N, i, c);
    }

    while (Q--) {
        int type, L, R;
        std::cin >> type >> L >> R;
        if (type == 1) {
            ll odd = query(oddSegTree, 1, 1, N, L, R);
            ll even = query(evenSegTree, 1, 1, N, L, R);
            std::cout << llabs(odd - even) << '\n';
        } else {
            updateTree(1, 1, N, L, R);
        }
    }

    return 0;
}