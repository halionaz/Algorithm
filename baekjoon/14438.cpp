// 수열과 쿼리 17
// 세그먼트 트리

// 최솟값 저장

#include <iostream>
#include <vector>
#include <cmath>

typedef long long ll;

const ll llmax = 1e9+1;

int N, M;
std::vector<ll> segTree;

ll min(ll a, ll b){
    return a < b ? a : b;
}

ll updateTree(int node, int s, int e, int ind, ll val){
    if(ind < s || e < ind){
        return segTree[node];
    } else {
        if(s == e){
            return segTree[node] = val;
        } else {
            int mid = (s+e)/2;
            return segTree[node] = min(updateTree(node*2,s,mid,ind,val),updateTree(node*2+1,mid+1,e,ind,val));
        }
    }
}

ll query(int node, int s, int e, int l, int r){
    if(r < s || e < l){
        return llmax;
    } else {
        if(l <= s && e <= r){
            return segTree[node];
        } else {
            int mid = (s+e)/2;
            return min(query(node*2,s,mid,l,r),query(node*2+1,mid+1,e,l,r));
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    int height = (int)std::ceil(std::log2(N));
    int size = (1 << (height+1));
    segTree.resize(size);

    for(int i = 1; i <= N; i++){
        ll val;
        std::cin >> val;
        updateTree(1,1,N,i,val);
    }

    std::cin >> M;

    while(M--){
        int order,i;
        ll j;
        std::cin >> order >> i >> j;
        if(order == 1){
            updateTree(1,1,N,i,j);
        } else {
            std::cout << query(1,1,N,i,j) << '\n';
        }
    }

    return 0;
}