// 터보소트
// 세그먼트 트리 & 두 포인터

#include <iostream>
#include <vector>

int N, a;
int pos[100001];
std::vector<int>segTree(1<<19);

int updateTree(int node, int s, int e, int ind, int val){
    if(ind < s || e < ind){
        return segTree[node];
    } else {
        if(s == e){
            return segTree[node] = val;
        } else {
            int mid = (s + e)/2;
            return segTree[node] = updateTree(node*2, s, mid, ind, val) + updateTree(node*2+1, mid + 1, e, ind, val);
        }
    }
}

int query(int node, int s, int e, int l, int r){
    if(r < s || e < l){
        return 0;
    } else {
        if(l <= s && e <= r){
            return segTree[node];
        } else {
            int mid = (s + e) / 2;
            return query(node*2, s, mid, l, r) + query(node*2+1, mid+1, e, l, r);
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 1; i <= N; i++){
        std::cin >> a;
        // 숫자 a의 위치 기록
        pos[a] = i;
        updateTree(1, 1, N, i, 1);
    }

    int l = 1, r = N;

    while(l < r){
        std::cout << query(1, 1, N, 1, pos[l]-1) << '\n';
        updateTree(1, 1, N, pos[l], 0);
        l++;
        std::cout << query(1, 1, N, pos[r]+1, N) << '\n';
        updateTree(1, 1, N, pos[r], 0);
        r--;
    }

    if(l == r){
        std::cout << query(1, 1, N, 1, pos[l]-1) << '\n';
        updateTree(1, 1, N, pos[l], 0);
    }

    return 0;
}