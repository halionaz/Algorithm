// Balanced Lineup
// 세그먼트 트리

// 6218과 동일한 문제.
// 세부적인 조건이 다르긴 하나, 풀이에 차이가 전혀 없음

#include <iostream>
#include <vector>
#include <cmath>

const int maxint = 987654321;

int N, Q, inp;
std::vector<int> minTree;
std::vector<int> maxTree;

int min(int a, int b){
    return a < b ? a : b;
}
int max(int a, int b){
    return a > b ? a : b;
}

int updateMinTree(int node, int s, int e, int ind, int val){
    if(ind < s || e < ind){
        return minTree[node];
    } else {
        if(s == e){
            return minTree[node] = val;
        } else {
            int mid = (s+e)/2;
            return minTree[node] = min(updateMinTree(node*2, s, mid, ind, val), updateMinTree(node*2+1, mid+1, e, ind, val));
        }
    }
}
int updateMaxTree(int node, int s, int e, int ind, int val){
    if(ind < s || e < ind){
        return maxTree[node];
    } else {
        if(s == e){
            return maxTree[node] = val;
        } else {
            int mid = (s+e)/2;
            return maxTree[node] = max(updateMaxTree(node*2, s, mid, ind, val), updateMaxTree(node*2+1, mid+1, e, ind, val));
        }
    }
}

int searchMinTree(int node, int s, int e, int l, int r){
    if(r < s || e < l){
        return maxint;
    } else {
        if(l <= s && e <= r){
            return minTree[node];
        } else {
            int mid = (s+e)/2;
            return min(searchMinTree(node*2, s, mid, l, r), searchMinTree(node*2+1, mid+1, e, l, r));
        }
    }
}
int searchMaxTree(int node, int s, int e, int l, int r){
    if(r < s || e < l){
        return maxint * -1;
    } else {
        if(l <= s && e <= r){
            return maxTree[node];
        } else {
            int mid = (s+e)/2;
            return max(searchMaxTree(node*2, s, mid, l, r), searchMaxTree(node*2+1, mid+1, e, l, r));
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> Q;

    int height = (int)std::ceil(log2(N+1));
    int size = (1 << (height+1));
    minTree.resize(size);
    maxTree.resize(size);

    for(int i = 1; i <= N; i++){
        std::cin >> inp;
        updateMinTree(1, 1, N, i, inp);
        updateMaxTree(1, 1, N, i, inp);
    }

    while(Q--){
        int A, B;
        std::cin >> A >> B;
        std::cout << searchMaxTree(1, 1, N, A, B) - searchMinTree(1, 1, N, A, B) << '\n';
    }

    return 0;
}