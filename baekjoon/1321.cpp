// 군인
// 세그먼트 트리 & 이분 탐색

#include <iostream>
#define maxN 500001

typedef long long ll;

int N, M, a, i;
ll segTree[maxN*4];

ll updateTree(int node, int s, int e, int ind, ll diff){
    if(ind < s || e < ind){
        return segTree[node];
    } else {
        if(s == e){
            return segTree[node] = segTree[node] + diff;
        } else {
            int mid = (s + e)/2;
            return segTree[node] = updateTree(node*2, s, mid, ind, diff) + updateTree(node*2+1, mid+1, e, ind, diff);
        }
    }
}
int query(int node, int s, int e, ll serviceNum){
    if(s == e){
        return s;
    } else {
        int mid = (s + e)/2;
        ll leftCnt = segTree[node*2];
        if(serviceNum <= leftCnt){
            // 왼쪽 트리에 존재
            return query(node*2, s, mid, serviceNum);
        } else {
            // 오른쪽 트리에 존재
            return query(node*2+1, mid+1, e, serviceNum - leftCnt);
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(i = 1; i <= N; i++){
        std::cin >> a;
        updateTree(1, 1, N, i, a);
    }

    std::cin >> M;

    while(M--){
        std::cin >> a;
        if(a == 1){
            std::cin >> i >> a;
            updateTree(1, 1, N, i, a);
        } else {
            std::cin >> i;
            std::cout << query(1, 1, N, i) << '\n';
        }
    }

    return 0;
}