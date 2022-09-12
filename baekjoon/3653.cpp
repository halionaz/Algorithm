// 영화 수집
// 세그먼트 트리

// segTree를 M + N 크기로 만듦 ( 0 ~ N + M - 1 까지 존재)
// 뒤쪽 N개에만 우선 1을 넣어줌
// M개의 query 동안, 위로 쌓아줘야 하는 애들을 앞쪽 M개에 뒤에서부터 차곡차곡 쌓아줌

// 말하자면 N개가 쌓여있을 때, M번 N개의 DVD 위로 퍼올려줘야 하므로,
// N개 위에 M개의 칸을 미리 만들어놓고 쿼리가 진행될때마다 밑에 칸에서 빼서 위의 여분 칸에 채워줌

#include <cmath>
#include <iostream>
#include <math.h>
#include <vector>

std::vector<int> segTree;
int ind[100001];
int T, N, M;

// M ~ N + M - 1을 1로 초기화
int initTree(int node, int s, int e){
    if(s == e){
        if(s >= M){
            ind[s - M] = s;
            return segTree[node] = 1;
        } else {
            return segTree[node] = 0;
        }
    } else {
        int mid = (s + e) / 2;
        return segTree[node] = initTree(node*2, s, mid) + initTree(node*2+1, mid+1, e);
    }
}

int updateTree(int node, int s, int e, int ind, int val){
    if(ind < s || e < ind){
        return segTree[node];
    } else {
        if(s == e){
            return segTree[node] = val;
        } else {
            int mid = (s + e)/2;
            return segTree[node] = updateTree(node*2, s, mid, ind, val) + updateTree(node*2+1, mid+1, e, ind, val);
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
            int mid = (s + e)/2;
            return query(node*2, s, mid, l, r) + query(node*2+1, mid+1, e, l, r);
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> T;

    while(T--){

        std::cin >> N >> M;

        segTree.clear();
        int height = (int)std::ceil(log2(N + M));
        int size = (1 << (height + 1));
        segTree.resize(size);

        initTree(1, 0, N + M - 1);

        // idx는 꺼낸 DVD 넣을 자리 표시
        int idx = M - 1;

        for(int i = 0; i < M; i++){

            int cur;
            std::cin >> cur;

            cur -= 1;
            std::cout << query(1, 0, N + M - 1, 0, ind[cur] - 1) << ' ';

            updateTree(1, 0, N + M - 1, ind[cur], 0); // DVD 꺼내기
            ind[cur] = idx;
            idx -= 1;
            updateTree(1, 0, N + M - 1, ind[cur], 1); // DVD 넣기
        }

        std::cout << '\n';

    }

    return 0;

}