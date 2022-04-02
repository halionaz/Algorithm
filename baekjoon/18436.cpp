// 수열과 쿼리 37
// 세그먼트 트리

#include <iostream>
#include <vector>
#include <cmath>

int N, M;
bool arr[100001];
std::vector<int> oddTree;
std::vector<int> evenTree;

int updateTree(int kind, int node, int s, int e, int ind, int val){
    if(ind < s || e < ind){
        return kind ? oddTree[node] : evenTree[node];
    } else {
        if(s == e){
            return kind ? (oddTree[node] += val) : (evenTree[node] += val);
        } else {
            int mid = (s+e)/2;
            int tmp = updateTree(kind,node*2,s,mid,ind,val) + updateTree(kind,node*2+1,mid+1,e,ind,val);
            return kind ? (oddTree[node] = tmp) : (evenTree[node] = tmp);
        }
    }
}

int query(int kind, int node, int s, int e, int l, int r){
    if(r < s || e < l){
        return 0;
    } else {
        if(l <= s && e <= r){
            return kind ? oddTree[node] : evenTree[node];
        } else {
            int mid = (s+e)/2;
            int tmp = query(kind,node*2,s,mid,l,r) + query(kind,node*2+1,mid+1,e,l,r);
            return tmp;
        }
    }
}

int main(){
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    std::cin >> N;

    int height = (int)std::ceil(std::log2(N));
    int size = (1<<(height+1));
    oddTree.resize(size);
    evenTree.resize(size);

    for(int i = 1; i <= N; i++){
        long long val;
        std::cin >> val;
        if(val%2){
            // 홀수
            arr[i] = true;
            updateTree(1,1,1,N,i,1);
        } else {
            arr[i] = false;
            updateTree(0,1,1,N,i,1);
        }
    }

    std::cin >> M;

    while(M--){
        int o, i, j;
        std::cin >> o >> i >> j;
        if(o == 1){
            if(j%2){
                // 바꾸려는 수가 홀수
                if(!arr[i]){
                    //인데 원래 ai는 짝수
                    arr[i] = true;
                    updateTree(1,1,1,N,i,1);
                    updateTree(0,1,1,N,i,-1);
                }
            } else {
                if(arr[i]){
                    arr[i] = false;
                    updateTree(1,1,1,N,i,-1);
                    updateTree(0,1,1,N,i,1);
                }
            }
        } else if(o == 2){
            std::cout << query(0,1,1,N,i,j) << '\n';
        } else {
            std::cout << query(1,1,1,N,i,j) << '\n';
        }
    }

    return 0;
}