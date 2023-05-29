// K번째 수
// 세그먼트 트리 & 정렬 & 머지 소트 트리 & 이분 탐색

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

int N, M, I, J, K;
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
            // val보다 작은 요소가 배열 내 몇개 있는지 반환
            return std::lower_bound(mergeTree[node].begin(), mergeTree[node].end(), val) - mergeTree[node].begin();
        } else {
            int mid = (s + e)/2;
            return query(node*2, s, mid, l, r, val) + query(node*2+1, mid+1, e, l, r, val);
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;

    int height = (int)std::ceil(log2(N));
    int size = (1 << (height + 1));
    mergeTree.resize(size);
    input.resize(N+1);

    for(int i = 1; i <= N; i++){
        std::cin >> input[i];
    }

    init(1, 1, N);

    while(M--){

        std::cin >> I >> J >> K;

        int left = -1e9, right = 1e9;
        int mid;

        // K보다 작은 값의 개수를 구하는 것이 아니라,
        // K번째 수를 구해야 함.

        // 따라서 X보다 작은 값의 개수를 구한 후,
        // 작은 값의 개수가 K보다 작다면, X를 늘리고
        // 작은 값의 개수가 K보다 크다면, X를 줄이는 식의 이분 탐색으로 
        // X값 탐색
        
        while(left <= right){
            mid = (left + right) / 2;
            if(query(1, 1, N, I, J, mid) < K){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        std::cout << left - 1 << '\n';
    }

    return 0;
}