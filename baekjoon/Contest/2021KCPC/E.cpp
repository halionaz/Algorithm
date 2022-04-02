// 까다로운 아이들과 선물 상자
// 세그먼트 트리

#include <iostream>
#include <cmath>
#include <vector>

typedef long long ll;

const int limit = 100001;

int N, M;
int ans;
int greedy[limit];
int good[limit];
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
        if(tree[node*2+1] >= ind){
            return tree[node] = tree[node*2] + searchTree(node*2+1,mid+1,e,ind);
        } else {
            ind -= tree[node*2+1];
            return tree[node] = searchTree(node*2, s, mid, ind) +  tree[node*2+1];
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    ll height = (ll)std::ceil(std::log2(limit));
    ll size = (1 << (height+1));
    tree.resize(size);

    std::cin >> N >> M;

    for(int i = 0; i < N; i++){
        ll val;
        std::cin >> val;
        updateTree(1,1,limit, val, 1);
        // segtree val만큼의 선물 개수가 있는 상자가 1개 늘어남
    }

    for(int i = 0; i < M; i++){
        std::cin >> greedy[i];
    }
    for(int i = 0; i < M; i++){
        std::cin >> good[i];
    }
    for(int i = 0; i < M; i++){
        // i 번째 애 차례
        if(!(tree[1] >= good[i])){
            std::cout << 0 << '\n';
            return 0;
        }
        searchTree(1,1,limit,good[i]);
        if(ans >= greedy[i]){
            if(ans - greedy[i]){
                updateTree(1, 1, limit, ans - greedy[i],1);
            }
        } else {
            std::cout << 0 << '\n';
            return 0;
        }
    }

    std::cout << 1 << '\n';

    return 0;
}