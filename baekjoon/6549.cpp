// 히스토그램에서 가장 큰 직사각형
// 스택

// 두가지 풀이가 있어 스택으로도 풀 수 있고, 세그트리와 분할정복을 활용한 풀이도 있음

// 처음엔 세그트리 풀이만 연습했지만
// 11873번을 풀려고 하니 6549번의 스택 풀이가 필요한듯 싶어
// 둘 다 연습해보자!

#include <iostream>
#include <algorithm>
#include <stack>

typedef long long ll;

int N;
ll arr[100001];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    while(true){

        std::cin >> N;

        ll ans = 0;
        std::stack<int> stck;

        if(N == 0){ // 0 입력시 종료
            break;
        }

        for(int i = 0; i < N; i++){
            std::cin >> arr[i];
        }

        for(int i = 0; i < N; i++){

            while(!stck.empty() && arr[i] <= arr[stck.top()]){
                
                // 스택에 쌓여있는 이전 높이보다 현 막대의 길이가 짧을 경우
                // 현 막대보다 큰 스택에 있는 높이들을 pop 해주면서 답을 갱신해줌

                ll lastMaxHeight = arr[stck.top()];
                stck.pop();

                ll width;

                if(stck.empty()){
                    // 스택이 비어있다면, 현 막대가 지금까지 탐색한 히스토그램에서 가장 짧은 막대인 것이므로
                    // 그냥 0 ~ i까지가 width가 됨
                    width = i;
                } else {
                    // 스택이 비어있지 않으면,
                    // 그 스택 요소가 현 막대보다 짧으므로, 스택 요소를 제외한 width를 구함
                    width = i - stck.top() - 1;
                }

                ans = std::max(ans, width * lastMaxHeight);

            }

            stck.push(i);
        }

        while(!stck.empty()){
            ll height = arr[stck.top()];
            stck.pop();

            ll width;

            if(stck.empty()){
                width = N;
            } else {
                width = N - stck.top() - 1;
            }
            ans = std::max(ans, width * height);
        }

        std::cout << ans << '\n';

    }

    return 0;
}


// 히스토그램에서 가장 큰 직사각형
// 세그먼트 트리 & 분할 정복

// 구간의 최솟값을 저장한 이후
// 최솟값 * 구간을 사각형의 넓이로 산정하고
// 그 최솟값 왼편과 오른편 각각에 더 넓은 사각형이 있는지
// 분할정복으로 구함

// #include <iostream>
// #include <vector>
// #include <cmath>

// typedef long long ll;
// const ll inf = 2000000000;

// int N;
// ll arr[100001];
// std::vector<ll> minTree;
// // minTree는 구간의 최솟값을 지닌 인덱스를 보관한다

// ll makeTree(int node, int s, int e){
//     if( s == e ){
//         return minTree[node] = s;
//     } else {
//         int mid = (s+e)/2;
//         int left = makeTree(node*2,s,mid);
//         int right = makeTree(node*2+1,mid+1,e);
//         if(arr[left] < arr[right]){
//             return minTree[node] = left;
//         } else {
//             return minTree[node] = right;
//         }
//     }
// }
// ll search(int node, int s, int e, int l, int r){
//     if(r < s || e < l){
//         return inf;
//     } else {
//         if(l <= s && e <= r){
//             return minTree[node];
//         } else {
//             int mid = (s+e)/2;
//             int left = search(node*2,s,mid,l,r);
//             int right = search(node*2+1,mid+1,e,l,r);
//             if(left == inf){
//                 return right;
//             } else if(right == inf){
//                 return left;
//                 // 위에 두 조건은 오류 방지용
//             } else if(arr[left] < arr[right]){
//                 return left;
//             } else {
//                 return right;
//             }
//         }
//     }
// }

// ll solve(int s, int e){
    
//     int minInd = search(1,0,N-1,s,e);

//     ll height = (ll)(e-s+1);
//     ll area = arr[minInd] * height;

//     // minInd 기준 왼쪽에 더 큰 사각형이 존재하는지 판별
//     if(s <= minInd - 1){
//         ll tmp = solve(s, minInd-1);
//         if(tmp > area){
//             area = tmp;
//         }
//     }

//     // minInd 기준 오른쪽에 더 큰 사각형이 존재하는지 판별
//     if(e >= minInd + 1){
//         ll tmp = solve(minInd+1,e);
//         if(tmp > area){
//             area = tmp;
//         }
//     }

//     return area;
// }

// int main(){

//     std::ios_base::sync_with_stdio(0);
//     std::cin.tie(0);

//     arr[100000] = 1000000000;

//     while(true){

//         minTree.clear();

//         std::cin >> N;

//         if(N == 0){
//             break;
//         }

//         for(int i = 0; i < N; i++){
//             std::cin >> arr[i];
//         }

//         int height = (int)std::ceil(std::log2(N));
//         int size = ( 1 << (height+1));
//         minTree.resize(size);

//         makeTree(1,0,N-1);


//         std::cout << solve(0,N-1) << '\n';

//     }


//     return 0;
// }
