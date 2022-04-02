// 커피숍2
// 세그먼트 트리

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
            // std::cout << node << ' ';
            return segTree[node] = val;
        } else {
            int mid = (s+e)/2;
            return segTree[node] = updateTree(node*2,s,mid,ind,val) + updateTree(node*2+1,mid+1,e,ind,val);
        }
    }
}

ll query(int node, int s, int e, int l, int r){
    if(r < s || e < l){
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
    std::cout.tie(0);

    std::cin >> N >> Q;

    int height = (int)std::ceil(std::log2(N));
    int size = (1<<(height+1));
    segTree.resize(size);

    for(int i = 1; i <= N; i++){
        ll val;
        std::cin >> val;
        updateTree(1,1,N,i,val);
    }

    while(Q--){
        int x,y,a;
        ll b;
        std::cin >> x >> y >> a >> b;
        if(x > y){
            int tmp = x;
            x = y;
            y = tmp;
        }
        std::cout << query(1,1,N,x,y) << '\n';
        updateTree(1,1,N,a,b);
    }

    return 0;
}