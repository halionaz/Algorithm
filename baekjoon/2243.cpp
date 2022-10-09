// 사탕상자
// 세그먼트 트리 & 이분 탐색

#include <iostream>
#include <cmath>
#include <vector>

typedef long long ll;

const int limit = 1000000;

int N;
int ans;
std::vector<ll> tree;

ll updateTree(ll node, int s, int e, int ind, ll diff){
    if(s == e){
        tree[node] += diff;
        return tree[node];
    } else {
        int mid = (s+e)/2;
        if(ind <= mid){
            return tree[node] = updateTree(node*2,s,mid,ind,diff) + tree[node*2+1];
        } else {
            return tree[node] = tree[node*2] + updateTree(node*2+1,mid+1,e,ind,diff);
        }
    }
}

ll searchTree(ll node, int s, int e, ll ind){
    if(s == e){
        ans = s;
        tree[node] -= 1;
        return tree[node];
    } else {
        int mid = (s+e)/2;
        if(tree[node*2] >= ind){
            return tree[node] = searchTree(node*2,s,mid,ind) + tree[node*2+1];
        } else {
            ind -= tree[node*2];
            return tree[node] = tree[node*2] + searchTree(node*2+1,mid+1,e,ind);
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    ll height = (ll)std::ceil(std::log2(limit));
    ll size = (1 << (height+1));
    tree.resize(size);

    std::cin >> N;

    while(N--){
        int A;
        std::cin >> A;
        if(A == 1){
            ll B;
            std::cin >> B;
            searchTree(1,1,limit,B);
            std::cout << ans << '\n';
        } else {
            int B;
            ll C;
            std::cin >> B >> C;
            updateTree(1,1,limit,B,C);
        }
    }

    return 0;
}