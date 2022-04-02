// 요세푸스 문제 2
// 세그먼트 트리

#include <iostream>
#include <vector>
#include <cmath>

int N,K;
int ans;
std::vector<int> tree;

int makeTree(int node, int s, int e){
    if(s == e){
        return tree[node] = 1;
    } else {
        int mid = (s+e)/2;
        return tree[node] = makeTree(node*2,s,mid) + makeTree(node*2+1,mid+1,e);
    }
}

int searchTree(int node, int s, int e, int ind){
    if(s == e){
        ans = s;
        return tree[node] = 0;
    } else {
        int mid = (s+e)/2;
        if(ind <= tree[node*2]){
            return tree[node] = searchTree(node*2,s,mid,ind) + tree[node*2+1];
        } else {
            return tree[node] = tree[node*2] + searchTree(node*2+1,mid+1,e,ind-tree[node*2]);
        }
    }
}
// int updateTree(int node, int s, int e, int ind){

// }

int main(){
    
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> K;

    int height = (int)std::ceil(std::log2(N));
    int size = (1 << (height+1));
    tree.resize(size);

    makeTree(1,1,N);

    int index = 1;

    std::cout << "<";

    for(int i = 0; i < N; i++){

        int remain = N - i;
        index += K-1;

        if(index % remain == 0){
            index = remain;
        } else if(index > remain){
            index %= remain;
        }

        searchTree(1,1,N,index);
        // updateTree(1,1,N,index);

        if(i == N-1){
            std::cout << ans;
        } else {
            std::cout << ans << ", ";
        }
        
    }
    std::cout << ">\n";

    return 0;
}