// 최솟값과 최댓값
// 세그먼트 트리

#include <iostream>
#include <cmath>
#include <vector>

typedef long long ll;

int N,M;
std::vector<ll> arr;
std::vector<ll> maxTree;
std::vector<ll> minTree;

ll makeMaxTree(int node, int s, int e){
    if(s == e){
        return maxTree[node] = arr[s];
    } else {
        int mid = (s+e)/2;
        ll right = makeMaxTree(node*2,s,mid);
        ll left = makeMaxTree(node*2+1,mid+1,e);
        maxTree[node] = right > left ? right : left;
        return maxTree[node];
    }
}
ll makeMinTree(int node, int s, int e){
    if(s == e){
        return minTree[node] = arr[s];
    } else {
        int mid = (s+e)/2;
        ll right = makeMinTree(node*2,s,mid);
        ll left = makeMinTree(node*2+1,mid+1,e);
        minTree[node] = right < left ? right : left;
        return minTree[node];
    }
}

ll returnMax(int node, int s, int e, int l, int r){
    if(l > e || r < s){
        return 0;
    }
    if(l <= s && e <= r){
        return maxTree[node];
    }

    int mid = (s+e) / 2;
    ll right = returnMax(node*2,s,mid,l,r);
    ll left = returnMax(node*2+1,mid+1,e,l,r);
    return right > left ? right : left;
}
ll returnMin(int node, int s, int e, int l, int r){
    if(l > e || r < s){
        return 1000000001;
    }
    if(l <= s && e <= r){
        return minTree[node];
    }

    int mid = (s+e) / 2;
    ll right = returnMin(node*2,s,mid,l,r);
    ll left = returnMin(node*2+1,mid+1,e,l,r);
    return right < left ? right : left;

}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;

    for(int i = 0; i < N; i++){
        ll x;
        std::cin >> x;
        arr.push_back(x);
    }

    int height = (int)std::ceil(std::log2(N));
    int size = (1<<(height+1));
    maxTree.resize(size);
    minTree.resize(size);

    makeMaxTree(1,0,N-1);
    makeMinTree(1,0,N-1);

    for(int i = 0; i < M; i++){
        int a,b;
        std::cin >> a >> b;
        std::cout << returnMin(1,0,N-1,a-1,b-1) << ' ' << returnMax(1,0,N-1,a-1,b-1) << '\n';
    }

    return 0;
}