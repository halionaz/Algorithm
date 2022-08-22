// 수열과 쿼리 16
// 세그먼트 트리

// 그냥 쌩으로 값 저장하고, 세그먼트 트리엔 인덱스 저장한 후
// 세그먼트 트리 갱신할 때 배열에 인덱스 넣어서 비교해도 될 듯 하지만
// pair 자료형을 사용하여 만들어봄

#include <iostream>
#include <vector>
#include <cmath>

typedef long long ll;

const ll max = 1000000001;

int N,M;
ll arr[100001];
std::vector<std::pair<ll,int> > tree;

ll makeTree(int node, int s, int e){
    if(s == e){
        tree[node] = std::make_pair(arr[s],s);
        return tree[node].first;
    } else {
        int mid = (s+e)/2;
        ll left = makeTree(node*2,s,mid);
        ll right = makeTree(node*2+1,mid+1,e);
        if(left <= right){
            tree[node] = std::make_pair(left,tree[node*2].second);
            return left;
        } else {
            tree[node] = std::make_pair(right,tree[node*2+1].second);
            return right;
        }
    }
}
ll updateTree(int node, int s ,int e ,int ind, ll val){
    if(ind < s || ind > e){
        return max;
    } else {
        if(s == e){
            tree[node] = std::make_pair(val,ind);
            return val;
        } else {
            int mid = (s+e)/2;
            if(ind <= mid){
                ll left = updateTree(node*2,s,mid,ind,val);
                if(left <= tree[node*2+1].first){
                    tree[node] = std::make_pair(left,tree[node*2].second);
                    return left;
                } else {
                    tree[node] = std::make_pair(tree[node*2+1].first,tree[node*2+1].second);
                    return tree[node].first;
                }
            } else {
                ll right = updateTree(node*2+1,mid+1,e,ind,val);
                if(tree[node*2].first <= right){
                    tree[node] = std::make_pair(tree[node*2].first,tree[node*2].second);
                    return tree[node].first;
                } else {
                    tree[node] = std::make_pair(right,tree[node*2+1].second);
                    return right;
                }
            }
        }
    }
}
std::pair<ll,int> searchTree(int node, int s, int e, int l, int r){
    if(r < s || e < l){
        return std::make_pair(max,s);
    } else {
        if(l <= s && e <= r){
            return tree[node];
        } else {
            int mid = (s+e)/2;
            std::pair<ll,int> left = searchTree(node*2,s,mid,l,r);
            std::pair<ll,int> right = searchTree(node*2+1,mid+1,e,l,r);
            if(left.first <= right.first){
                return left;
            } else {
                return right;
            }
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 1; i <= N; i++){
        std::cin >> arr[i];
    }

    int height = (int)std::ceil(std::log2(N));
    int size = (1 << (height+1));
    tree.resize(size*3);

    makeTree(1,1,N);

    std::cin >> M;

    while(M--){
        int cmd;
        std::cin >> cmd;
        if(cmd == 1){
            int i;
            ll v;
            std::cin >> i >> v;
            updateTree(1,1,N,i,v);
        } else {
            int i,j;
            std::cin >> i >> j;
            std::cout << searchTree(1,1,N,i,j).second << '\n';
        }
    }

    return 0;
}