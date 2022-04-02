// 수열과 쿼리 15
// 세그먼트 트리

#include <iostream>
#include <vector>
#include <cmath>

const int maxNum = 100001;

typedef long long ll;

int N, M;
ll arr[maxNum]; // 인덱스 별 값 저장
std::vector<int> segTree; // 가장 작은 값의 인덱스

int updateTree(int node, int s, int e, int ind){
    if(ind < s || e < ind){
        return segTree[node];
    } else {
        if(s == e){
            return segTree[node] = ind;
        } else {
            int mid = (s+e)/2;
            int left = updateTree(node*2,s,mid,ind);
            int right = updateTree(node*2+1,mid+1,e,ind);
            if(arr[left] <= arr[right]){
                return segTree[node] = left;
            } else {
                return segTree[node] = right;
            }
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    int height = (int)std::ceil(std::log2(N));
    int size = (1 << (height+1));
    segTree.resize(size);

    for(int i = 1; i <= N; i++){
        std::cin >> arr[i];
        updateTree(1,1,N,i);
    }

    std::cin >> M;

    while(M--){
        int order;
        std::cin >> order;

        if(order == 1){
            int i; ll v;
            std::cin >> i >> v;
            arr[i] = v;
            updateTree(1,1,N,i);
        } else {
            std::cout << segTree[1] << '\n';
        }
    }

    return 0;
}