// 중앙값 측정
// 세그먼트 트리

#include <iostream>
#include <vector>
#include <cmath>

int N, K, midian;
std::vector<int> arr;
std::vector<int> segTree;
long long ans;

int updateTree(int node, int s, int e, int ind, int diff){
    if(ind < s || ind > e){
        return segTree[node];
    } else {
        if(s == e){
            return segTree[node] += diff;
        } else {
            int mid = (s+e)/2;
            return segTree[node] = updateTree(node*2, s, mid, ind, diff) + updateTree(node*2+1, mid+1, e, ind, diff);
        }
    }
}

int query(int node, int s, int e, int ind){
    if(s == e){
        return s;
    } else {
        int mid = (s+e)/2;

        if(segTree[node*2] >= ind){
            return query(node*2, s, mid, ind);
        } else {
            ind -= segTree[node*2];
            return query(node*2+1, mid+1, e, ind);
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int height = std::ceil(std::log2(65536));
    int size = (1 << (height+1));
    segTree.resize(size);

    std::cin >> N >> K;

    arr.resize(N);

    midian = (K+1)/2;

    for(int i = 0; i < N; i++){
        std::cin >> arr[i];
        // 더하기
        updateTree(1,0,65535, arr[i],1);
        if(i >= K-1){
            // 중앙값 계산
            ans += query(1,0,65535,midian);
            // 빼기
            updateTree(1,0,65535,arr[i-(K-1)], -1);
        }
    }

    std::cout << ans << '\n';

    return 0;
}