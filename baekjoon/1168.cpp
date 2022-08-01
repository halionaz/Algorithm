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
        // 탐색하면, 그 노드를 없애줌
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

int main(){
    
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> K;

    int height = (int)std::ceil(std::log2(N));
    int size = (1 << (height+1));
    tree.resize(size);

    // 모든 노드에 1이 들어가 있는,
    // 노드들의 부분합을 구하는 세그먼트 트리 제작
    makeTree(1,1,N);

    int index = 1;

    std::cout << "<";

    for(int i = 0; i < N; i++){

        int remain = N - i;
        // 다음 순서 구하기
        index += K-1;

        if(index % remain == 0){
            index = remain;
        } else if(index > remain){
            index %= remain;
        }

        // 인덱스 순번(누적합)의 ans 찾기
        searchTree(1,1,N,index);

        if(i == N-1){
            std::cout << ans;
        } else {
            std::cout << ans << ", ";
        }
        
    }
    std::cout << ">\n";

    return 0;
}