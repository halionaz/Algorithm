// 수열과 쿼리 1
// 세그먼트 트리 & 정렬 & 머지 소트 트리

// 13544번과 달리 입력이 이상하지 않기 때문에
// offline 쿼리로 처리해도 되지만
// 귀찮아서 그냥 13544번과 똑같은 온라인 머지 소트 트리로 구현

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

int N, M;
std::vector<int> input;
std::vector<std::vector<int> > mergeTree;

void init(int node, int s, int e){
    if(s == e){
        mergeTree[node].push_back(input[s]);
    } else {
        int mid = (s + e)/2;
        init(node*2, s, mid);
        init(node*2+1, mid+1, e);

        std::vector<int> &left = mergeTree[node*2];
        std::vector<int> &right = mergeTree[node*2+1];

        // 머지소팅
        for (int i = 0, j = 0; i < left.size() || j < right.size();) {
            if(j == right.size() || (i < left.size() && left[i] < right[j])){
                mergeTree[node].push_back(left[i++]);
            } else {
                mergeTree[node].push_back(right[j++]);
            }
        }
    }
}

int query(int node, int s, int e, int l, int r, int val){
    if(r < s || e < l){
        return 0;
    } else {
        if(l <= s && e <= r){
            return mergeTree[node].end() - std::upper_bound(mergeTree[node].begin(), mergeTree[node].end(), val);
        } else {
            int mid = (s + e)/2;
            return query(node*2, s, mid, l, r, val) + query(node*2+1, mid+1, e, l, r, val);
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    int height = (int)std::ceil(log2(N));
    int size = (1 << (height + 1));
    mergeTree.resize(size);
    input.resize(N+1);

    for(int i = 1; i <= N; i++){
        std::cin >> input[i];
    }

    init(1, 1, N);

    std::cin >> M;

    while(M--){
        int i, j, k;
        std::cin >> i >> j >> k;
        std::cout << query(1, 1, N, i, j, k) << '\n';
    }

    return 0;
}