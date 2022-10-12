// 굉장한 학생
// 세그먼트 트리 & 스위핑

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

const int inf = 1e9;

int N, T;
std::vector<std::vector<int> > score;
std::vector<int> segTree;

int update(int node, int s, int e, int ind, int val){
    if(ind < s || ind > e){
        return segTree[node];
    } else {
        if(s == e){
            return segTree[node] = val;
        } else {
            int mid = (s+e)/2;
            return segTree[node] = std::min(update(node*2,s,mid,ind,val), update(node*2+1,mid+1,e,ind,val));
        }
    }
}

int query(int node, int s, int e, int l, int r){
    if(r < s || e < l){
        return inf;
    } else {
        if(l <= s && e <= r){
            return segTree[node];
        } else {
            int mid = (s+e)/2;
            return std::min(query(node*2,s,mid,l,r), query(node*2+1,mid+1,e,l,r));
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0);

    std::cin >> N;

    int height = std::ceil(std::log2(N));
    int size = (1 << (height + 1));
    segTree.resize(size,inf);
    score.resize(N+1);

    for(int i = 1; i <= N; i++){
        score[i].resize(3);
    }

    for(int i = 0; i < 3; i++){
        for(int j = 1; j <= N; j++){
            std::cin >> T; // 각 순위의 사람이 들어옴
            score[T][i] = j; // T의 i번째 시험 등수는 j
        }
    }
    std::sort(score.begin(), score.end());

    // 우선 1번째 시험 성적 순으로 정렬되었으므로, 
    // i 사람에 대해 이미 1번째 시험 성적이 더 높은 사람 중 (이미 탐색된 사람들 중)
    // 2,3 번째 시험 성적이 둘 다 더 좋은 사람이 없다면 i 사람은 굉장함
    int ans = 0;
    for(int i = 1; i <= N; i++){
        if(query(1,1,N,1,score[i][1]) > score[i][2]){
            ans++;
        }
        update(1,1,N,score[i][1], score[i][2]);
    }

    std::cout << ans << '\n';

    return 0;
}