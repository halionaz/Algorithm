// 최솟값 찾기
// 우선순위 큐 & 덱

// 슬라이딩 윈도우 (덱 이용)
// 덱에는 최대 L개의 숫자만 저장
// 덱에 있는 숫자들은 오름차순으로 정렬, arr[i]가 덱에서 가장 큰 숫자가 되도록 조정
// 각 인덱스마다 덱의 front 숫자 출력 

#include <iostream>
#include <deque>
#include <vector>

typedef long long ll;

int N, L;
ll arr[5000000];
std::deque<std::vector<ll> > deq;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> L;

    for(int i = 0; i < N; i++){
        std::cin >> arr[i];
    }

    for(int i = 0; i < N; i++){
        if(!deq.empty() && deq.front()[1] < i - L + 1){
            deq.pop_front();
        }
        while(!deq.empty() && deq.back()[0] > arr[i]){
            deq.pop_back();
        }
        std::vector<ll> vec;
        vec.push_back(arr[i]);
        vec.push_back(i);
        deq.push_back(vec);
        std::cout << deq.front()[0] << ' ';
    }
    std::cout << '\n';

    return 0;
}

// // 세그먼트 트리 (시간초과)

// #include <iostream>
// #include <vector>
// #include <cmath>

// typedef long long ll;
// const ll maxll = 1000000001;

// int N, L;
// std::vector<ll> segTree;

// ll min(ll a, ll b){
//     return a < b ? a : b;
// }
// int max(int a, int b){
//     return a > b ? a : b;
// }

// ll updateTree(int node, int s, int e, int ind, ll val){
//     if(ind < s || e < ind){
//         return segTree[node];
//     } else {
//         if(s == e){
//             return segTree[node] = val;
//         } else {
//             int mid = (s+e)/2;
//             return segTree[node] = min(updateTree(node*2,s,mid,ind,val),updateTree(node*2+1,mid+1,e,ind,val));
//         }
//     }
// }

// ll searchTree(int node, int s, int e, int l, int r){
//     if(r < s || e < l){
//         return maxll;
//     } else {
//         if(l <= s && e <= r){
//             return segTree[node];
//         } else {
//             int mid = (s+e)/2;
//             return min(searchTree(node*2,s,mid,l,r), searchTree(node*2+1,mid+1,e,l,r));
//         }
//     }
// }

// int main(){

//     std::ios_base::sync_with_stdio(0);
//     std::cin.tie(0);

//     std::cin >> N >> L;

//     int height = (int)std::ceil(std::log2(N));
//     int size = (1 << (height+1));
//     segTree.resize(size);

//     for(int i = 0; i < N; i++){
//         ll inp;
//         std::cin >> inp;
//         updateTree(1,0,N-1,i,inp);
//     }

//     for(int i = 0; i < N; i++){
//         std::cout << searchTree(1,0,N-1,max(0,i-L+1),i) << ' ';
//     }
//     std::cout << '\n';

//     return 0;
// }