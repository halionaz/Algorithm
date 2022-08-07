// 가계부 (Hard)
// 세그먼트 트리

// 전형적인 세그먼트 트리 입문 문제
// 부분합을 저장하는 세그먼트 트리

#include <iostream>
#include <vector>
#include <cmath>

typedef long long ll;

int N, Q;
std::vector<ll> segTree;

ll updateTree(int node, int s, int e, int ind, ll val){
    if(ind < s || e < ind){
        return segTree[node];
    } else {
        if(s == e){
            return segTree[node] += val;
        } else {
            int mid = (s+e)/2;
            return segTree[node] = updateTree(node*2,s,mid,ind,val) + updateTree(node*2+1,mid+1,e,ind,val);
        }
    }
}

ll query(int node, int s, int e, int l, int r){
    if(e < l || r < s){
        return 0;
    } else {
        if(l <= s && e <= r){
            return segTree[node];
        } else {
            int mid = (s+e)/2;
            return query(node*2,s,mid,l,r) + query(node*2+1,mid+1,e,l,r);
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> Q;

    int height = (int)std::ceil(std::log2(N));
    int size = (1<<(height+1));
    segTree.resize(size);

    while(Q--){
        int order, p;
        ll q;

        std::cin >> order >> p >> q;

        if(order == 1){
            updateTree(1,1,N,p,q);
        } else {
            std::cout << query(1,1,N,p,q) << '\n';
        }
    }

    return 0;
}