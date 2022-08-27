// 달려라 홍준
// 세그먼트 트리

// #include <iostream>
// #include <math.h>
// #include <vector>
// #include <algorithm>

// typedef long long ll;

// int N, M, c;
// std::vector<ll> segTree;

// ll updateTree(int node, int s, int e, int ind, ll val){
//     if(ind < s || e < ind){
//         return segTree[node];
//     } else {
//         if(s == e){
//             return segTree[node] = val;
//         } else {
//             int mid = (s+e)/2;
//             return segTree[node] = std::max(updateTree(node*2,s,mid,ind,val), updateTree(node*2+1,mid+1,e,ind,val));
//         }
//     }
// }

// ll query(int node, int s, int e, int l, int r){
//     if(r < s || e < l){
//         return -1;
//     } else {
//         if(l <= s && e <= r){
//             return segTree[node];
//         } else {
//             int mid = (s+e)/2;
//             return std::max(query(node*2,s,mid,l,r), query(node*2+1,mid+1,e,l,r));
//         }
//     }
// }

// int main(){

//     std::ios_base::sync_with_stdio(0);
//     std::cin.tie(0);

//     std::cin >> N >> M;

//     int height = (int)ceil(log2(N));
//     int size = (1 << (height+1));
//     segTree.resize(size);

//     for(int i = 1; i <= N; i++){
//         std::cin >> c;
//         updateTree(1, 1, N, i, c);
//     }

//     for(int i = M; i <= N-M+1; i++){
//         std::cout << query(1, 1, N, i-M+1, i+M-1) << ' ';
//     }

//     std::cout << '\n';

//     return 0;
// }

// 슬라이딩 윈도우

#include <iostream>
#include <deque>
#include <utility>
#include <vector>

typedef long long ll;

int N, M;
ll arr[5000000];
std::deque<std::pair<ll, int> > deq;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;

    for(int i = 1; i <= N; i++){
        std::cin >> arr[i];
    }

    for(int i = 1; i <= N; i++){
        if(i >= 2*M-1){
            if(!deq.empty() && deq.front().second <= i - 2*M + 1){
                deq.pop_front();
            }
        }
        while(!deq.empty() && deq.back().first < arr[i]){
            deq.pop_back();
        }
        deq.push_back(std::make_pair(arr[i], i));
        if(i >= 2*M-1){
            std::cout << deq.front().first << ' ';
        }
    }

    std::cout << '\n';

    return 0;
}
