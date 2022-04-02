// 데이터 구조
// 세그먼트 트리

#include <iostream>
#include <vector>
#include <cmath>

const int limit = 2000000;

int N;
int ans;
std::vector<int> tree;

int updateTree(int node, int s, int e, int ind){
    if(s == e){
        return tree[node] += 1;
    } else {
        int mid = (s+e)/2;

        if(ind <= mid){
            return tree[node] = updateTree(node*2,s,mid,ind) + tree[node*2+1];
        } else {
            return tree[node] = tree[node*2] + updateTree(node*2+1,mid+1,e,ind);
        }
    }
}
int countTree(int node, int s, int e, int ind){
    if(s == e){
        ans = s;
        return tree[node] -= 1;
    } else {
        int mid = (s+e)/2;
        if(ind <= tree[node*2]){
            return tree[node] = countTree(node*2,s,mid,ind) + tree[node*2+1];
        } else {
            return tree[node] = tree[node*2] + countTree(node*2+1,mid+1,e,ind-tree[node*2]);
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int height = (int)std::ceil(std::log2(limit));
    int size = (1 << (height+1));
    tree.resize(size);

    std::cin >> N;

    while(N--){
        int T,X;
        std::cin >> T >> X;
        if(T == 1){
            updateTree(1,1,limit,X);
        } else {
            countTree(1,1,limit,X);
            std::cout << ans << '\n';
        }
    }

    return 0;
}