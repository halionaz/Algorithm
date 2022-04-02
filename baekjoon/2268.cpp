// 수들의 합
// 세그먼트 트리

#include <iostream>
#include <vector>
#include <cmath>

typedef long long ll;

ll N, M;
std::vector<ll> segTree;

ll Modify(int node, int s, int e, int ind, ll val){
    if(ind < s || e < ind){
        return segTree[node];
    } else {
        if(s == e){
            return segTree[node] = val;
        } else {
            int mid = (s+e)/2;
            return segTree[node] = Modify(node*2,s,mid,ind,val) + Modify(node*2+1,mid+1,e,ind,val);
        }
    }
}

ll Sum(int node, int s, int e, int l, int r){
    if(r < s || e < l){
        return 0;
    } else {
        if(l <= s && e <= r){
            return segTree[node];
        } else {
            int mid = (s+e)/2;
            return Sum(node*2,s,mid,l,r) + Sum(node*2+1,mid+1,e,l,r);
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> N >> M;

    int height = (int)std::ceil(std::log2(N));
    int size = (1<<(height+1));
    segTree.resize(size);

    while(M--){
        ll o,i,j;
        std::cin >> o >> i >> j;
        if(o){
            Modify(1,1,N,i,j);
        } else {
            if(i > j){
                int tmp = i;
                i = j;
                j = tmp;
            }
            std::cout << Sum(1,1,N,i,j) << '\n';
        }
    }

    return 0;
}