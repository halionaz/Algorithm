// 연속합과 쿼리
// 세그먼트 트리 & 분할 정복

// 가장 큰 연속합을 분할정복식으로 구함

// 각 node는 i~j 구간의 연속합 정보를 저장하는데,
// 분할정복식의 문제 풀이를 용이하게 하기 위해
// 1. i~k까지의 최대 연속합
// 2. k~j까지의 최대 연속합
// 3. k~l까지의 최대 연속합 정보
// 를 모두 저장 
// (i <= k <= l <= j)

// 이후 상위 노드의 1, 2, 3번은
// 1. max(left 노드의 1번, left 구간 전체합 + right 노드의 1번)
// 2. max(right 노드의 2번, right 구간 전체합 + left 노드의 2번)
// 3. max(left 노드의 3번, right 노드의 3번, left 노드의 2번 + right 노드의 1번)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

const int inf = 987654321;

struct segNode{
    int left, right, mid;
};

int N, M;
int arr[100001];
// 수열의 부분합 저장
int pSum[100001];
// 분할정복 적용할 세그트리
std::vector<segNode> segTree;

segNode updateTree(int node, int s, int e, int ind, int val){
    if(ind < s || e < ind){
        return segTree[node];
    } else {
        if(s == e){
            return segTree[node] = {val, val, val};
        } else {
            int mid = (s+e)/2;
            segNode left = updateTree(node*2, s, mid, ind, val);
            segNode right = updateTree(node*2+1, mid+1, e, ind, val); 

            segTree[node].left = std::max(left.left, pSum[mid] - pSum[s-1] + right.left);
            segTree[node].right = std::max(right.right, pSum[e] - pSum[mid] + left.right);
            segTree[node].mid = std::max(std::max(right.mid, left.mid), left.right + right.left);
            return segTree[node];
        }
    }
}

segNode query(int node, int s, int e, int l, int r){
    if(r < s || e < l){
        return {-inf, -inf, -inf};
    } else {
        if(l <= s && e <= r){
            return segTree[node];
        } else {
            int mid = (s+e)/2;
            segNode left = query(node*2, s, mid, l, r);
            segNode right = query(node*2+1, mid+1, e, l, r); 

            segNode ret;
            ret.left = std::max(left.left, pSum[mid] - pSum[s-1] + right.left);
            ret.right = std::max(right.right, pSum[e] - pSum[mid] + left.right);
            ret.mid = std::max(std::max(right.mid, left.mid), left.right + right.left);

            return ret;
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    // 크기 지정
    int height = (int)std::ceil(log2(N));
    int size = (1<<(height+1));
    segTree.resize(size);

    for(int i = 1; i <= N; i++){
        std::cin >> arr[i];
        pSum[i] = pSum[i-1] + arr[i];
        updateTree(1, 1, N, i, arr[i]);
    }

    std::cin >> M;

    while(M--){
        int i, j;
        std::cin >> i >> j;
        std::cout << query(1, 1, N, i, j).mid << '\n';
    }

    return 0;
}