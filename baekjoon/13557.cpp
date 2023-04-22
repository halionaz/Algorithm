// 수열과 쿼리 10
// 세그먼트 트리 & 분할 정복

// 분할정복 개념을 적용한 세그 노드에 관련된 설명은 16993.cpp를 참조

// 구간의 시작점 범위와 구간의 끝점 범위가 주어졌을 때,
// 구간이 가질 수 있는 합의 최댓값 (최대 연속합)을 구하는 문제

// x1 <= start <= y1, x2 <= end <= y2 일 때
// 두 구간이 겹치지 않으면
// [x1, y1].right + [y1, x2].sum + [x2, y2].left
// 이 최대 연속합

// 두 구간이 겹치면 (x2 <= y1)
// 1. [x1, x2].right + [x2, y1].sum + [y1, y2].left
// 2. [x1, x2].right + [x2, y1].left
// 3. [x2, y1].right + [y1, y2].left
// 4. [x2, y1].mid
// 중 가장 큰 것이 최대 연속합

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long ll;

const ll inf = 1e17;

struct segNode{
    // i ~ j 구간에 대한 정보를 저장
    // sum :: i ~ j 구간 합
    // left :: i ~ k 구간 최대 연속합
    // right :: k ~ j 구간 최대 연속합
    // mid :: k ~ p 구간 최대 연속합
    ll sum, left, right, mid;
};

int N, M;
ll arr[100001];
// 분할정복 적용할 세그트리
std::vector<segNode> segTree;

segNode updateTree(int node, int s, int e){
    if(s == e){
        return segTree[node] = {arr[s], arr[s], arr[s], arr[s]};
    } else {
        int mid = (s+e)/2;
        segNode left = updateTree(node*2, s, mid);
        segNode right = updateTree(node*2+1, mid+1, e); 

        segTree[node].sum = left.sum + right.sum;
        segTree[node].left = std::max(left.left, left.sum + right.left);
        segTree[node].right = std::max(right.right, right.sum + left.right);
        segTree[node].mid = std::max(std::max(right.mid, left.mid), left.right + right.left);
        return segTree[node];
    }
}

segNode query(int node, int s, int e, int l, int r){
    if(r < s || e < l){
        return {0, -inf, -inf, -inf};
    } else {
        if(l <= s && e <= r){
            return segTree[node];
        } else {
            int mid = (s+e)/2;
            segNode left = query(node*2, s, mid, l, r);
            segNode right = query(node*2+1, mid+1, e, l, r); 

            segNode ret;
            ret.sum = left.sum + right.sum;
            ret.left = std::max(left.left, left.sum + right.left);
            ret.right = std::max(right.right, right.sum + left.right);
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
    }

    // 처음에는 for문 안에 입력을 받을 때마다 업데이트 시켜주는 함수였는데
    // 생각해보니 쿼리에 따라 수열이 수정되지 않으므로 그냥 다 받아놓고 한번에 업데이트 해도 됨
    updateTree(1, 1, N);

    std::cin >> M;

    while(M--){
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        if(y1 < x2){
            // 두 구간이 겹치지 않음
            segNode left = query(1, 1, N, x1, y1);
            segNode mid = query(1, 1, N, y1 + 1, x2 - 1);
            segNode right = query(1, 1, N, x2, y2);
            std::cout << left.right + mid.sum + right.left << '\n';
        } else {
            // 두 구간이 겹침
            segNode left = query(1, 1, N, x1, x2 - 1);
            segNode mid = query(1, 1, N, x2, y1);
            segNode right = query(1, 1, N, y1 + 1, y2);
            std::cout << std::max(std::max(left.right + mid.sum + right.left,
                                           left.right + mid.left),
                                  std::max(mid.right + right.left, mid.mid))
                      << '\n';
        }
    }

    return 0;
}