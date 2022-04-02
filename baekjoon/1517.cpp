// 버블 소트
// 세그먼트 트리

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

typedef long long ll;

int N;
std::vector<int> tree;
std::vector<std::vector<ll> > arr;

ll returnSum(int node, int s, int e, int left, int right){
    if(left > e || right < s){
        return 0;
    }
    if(left <= s && e <= right){
        return tree[node];
    }
    int mid = (s+e)/2;
    return returnSum(node*2,s,mid,left,right) + returnSum(node*2+1,mid+1,e,left,right);
}

ll updateTree(int node, int s, int e, int ind){
    if(ind < s || e < ind){
        return tree[node];
    } else {
        if(s == e){
            return tree[node] = 1;
        } else {
            int mid = (s+e)/2;
            return tree[node] = updateTree(node*2,s,mid,ind) + updateTree(node*2+1,mid+1,e,ind);
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 0; i < N; i++){
        ll x;
        std::vector<ll> y;
        std::cin >> x;
        y.push_back(x);
        y.push_back(i);
        arr.push_back(y);
    }

    int height = (int)std::ceil(std::log2(N));
    int size = (1 << (height+1));
    tree.resize(size);

    std::sort(arr.begin(),arr.end());

    ll ans = 0;

    for(int i = 0; i < N; i++){
        int ind = arr[i][1];
        ans += returnSum(1,0,N-1,ind+1,N-1);
        updateTree(1,0,N-1,ind);
    }

    std::cout << ans << '\n';

    return 0;
}