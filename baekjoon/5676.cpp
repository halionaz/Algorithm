// 음주 코딩 
// 세그먼트 트리

#include <iostream>
#include <vector>
#include <cmath>

int N, K;
std::vector<int> segTree;

int updateTree(int node, int s, int e, int ind, int val){
    if(ind < s || e < ind){
        return segTree[node];
    } else {
        if(s == e){
            int value;
            if(val > 0){
                value = 1;
            } else if(val < 0){
                value = -1;
            } else {
                value = 0;
            }
            return segTree[node] = value;
        } else {
            int mid = (s+e)/2;
            return segTree[node] = updateTree(node*2,s,mid,ind,val) * updateTree(node*2+1,mid+1,e,ind,val);
        }
    }
}

int searchTree(int node, int s, int e, int l, int r){
    if(r < s || e < l){
        return 1;
    } else {
        if(l <= s && e <= r){
            return segTree[node];
        } else {
            int mid = (s+e)/2;
            return searchTree(node*2,s,mid,l,r) * searchTree(node*2+1,mid+1,e,l,r);
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    while(std::cin >> N){

        segTree.clear();

        std::cin >> K;

        int height = (int)std::ceil(std::log2(N));
        int size = (1 << (height+1));
        segTree.resize(size);

        for(int i = 1; i <= N; i++){
            int val;
            std::cin >> val;
            updateTree(1,1,N,i,val);
        }

        while(K--){
            char order;
            int i,j;
            std::cin >> order >> i >> j;

            if(order == 'C'){
                updateTree(1,1,N,i,j);
            } else {
                int result = searchTree(1,1,N,i,j);
                if(0 < result){
                    std::cout << '+';
                } else if(result == 0){
                    std::cout << '0';
                } else {
                    std::cout << '-';
                }
            }

        }

        std::cout << '\n';

    }


    return 0;
}