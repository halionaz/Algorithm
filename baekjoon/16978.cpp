// 수열과 쿼리 22
// 세그먼트 트리 & 오프라인 쿼리

// 쿼리들이 처리하기 까다롭게 섞여있어,
// 쿼리를 유리하게 정렬해주는 과정이 필요함

#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
#include <cmath>

typedef long long ll;

struct query{
    ll comp, ind, type, a, b;

    bool operator < (query &A){
        if(comp != A.comp){
            return comp < A.comp;
        }

        return type < A.type;
    }
};

int N, M;
std::vector<ll> segTree;
std::vector<query> arr;
ll answer[101010];

ll updateTree(int node, int s, int e, int ind, ll val){
    if(ind < s || e < ind){
        return segTree[node];
    } else {
        if(s == e){
            return segTree[node] = val;
        } else {
            int mid = (s+e)/2;
            return segTree[node] = updateTree(node*2,s,mid,ind,val) + updateTree(node*2+1,mid+1,e,ind,val);
        }
    }
}

ll findSum(int node, int s, int e, int l, int r){
    if(r < s || e < l){
        return 0;
    } else {
        if(l <= s && e <= r){
            return segTree[node];
        } else {
            int mid = (s+e)/2;
            return findSum(node*2,s,mid,l,r) + findSum(node*2+1,mid+1,e,l,r);
        }
    }
}


int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    int height = (int)ceil(log2(N));
    int size = (1 << (height+1));
    segTree.resize(size);

    int a;

    for(int i = 1; i <= N; i++){
        std::cin >> a;
        updateTree(1, 1, N, i, a);
    }

    std::cin >> M;

    int query1 = 0, query2 = 0;

    for(int i = 1; i <= M; i++){
        query cur;

        std::cin >> cur.type;

        if(cur.type == 1){
            cur.comp = ++query1;
            std::cin >> cur.a >> cur.b;
        } else {
            cur.ind = ++query2;
            std::cin >> cur.comp >> cur.a >> cur.b;
        }
        arr.push_back(cur);
    }

    std::sort(arr.begin(), arr.end());

    for(int i = 0; i < arr.size(); i++){
        query cur = arr[i];

        if(cur.type == 1){
            updateTree(1, 1, N, cur.a, cur.b);
        } else {
            answer[cur.ind] = findSum(1, 1, N, cur.a, cur.b);
        }
    }

    for(int i = 1; i <= query2; i++){
        std::cout << answer[i] << '\n';
    }

    return 0;
}