// 수열과 쿼리 3
// 세그먼트 트리 & 정렬 & 머지 소트 트리

// 입력이 매우 이상합니다.
// i, j, k가 단순히 입력으로 결정되는 것이 아닌, 입력된 값과 바로 이전 정답을 xor한 값으로 결정됩니다.
// 이런 입력은 주로 grader를 안 쓰는 batch 형식의 문제에서 online을 강제할 때 많이 나옵니다.
// [출처] justicehui.github.io

// 그렇다고 한다 
// 단순 세그 트리를 이용한 offline 풀이가 아닌, 바로바로 답을 뽑아내야 하는 online 처리를 강제하기 위한 조치

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

int N, M, a, b, c;
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

    int lastAns = 0;

    while(M--){
        std::cin >> a >> b >> c;
        int i = a ^ lastAns;
        int j = b ^ lastAns;
        int k = c ^ lastAns;
        lastAns = query(1, 1, N, i, j, k);
        std::cout << lastAns << '\n';
    }

    return 0;
}