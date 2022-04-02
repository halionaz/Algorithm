// 히스토그램
// 세그먼트 트리 & 분할 정복

// 6549와 똑같은 문제

// 구간의 최솟값을 저장한 이후
// 최솟값 * 구간을 사각형의 넓이로 산정하고
// 그 최솟값 왼편과 오른편 각각에 더 넓은 사각형이 있는지
// 분할정복으로 구함

#include <iostream>
#include <vector>
#include <cmath>

typedef long long ll;
const ll inf = 2000000000;

int N;
ll arr[100001];
std::vector<ll> minTree;
// minTree는 구간의 최솟값을 지닌 인덱스를 보관한다

ll makeTree(int node, int s, int e){
    if( s == e ){
        return minTree[node] = s;
    } else {
        int mid = (s+e)/2;
        int left = makeTree(node*2,s,mid);
        int right = makeTree(node*2+1,mid+1,e);
        if(arr[left] < arr[right]){
            return minTree[node] = left;
        } else {
            return minTree[node] = right;
        }
    }
}
ll search(int node, int s, int e, int l, int r){
    if(r < s || e < l){
        return inf;
    } else {
        if(l <= s && e <= r){
            return minTree[node];
        } else {
            int mid = (s+e)/2;
            int left = search(node*2,s,mid,l,r);
            int right = search(node*2+1,mid+1,e,l,r);
            if(left == inf){
                return right;
            } else if(right == inf){
                return left;
                // 위에 두 조건은 오류 방지용
            } else if(arr[left] < arr[right]){
                return left;
            } else {
                return right;
            }
        }
    }
}

ll solve(int s, int e){
    
    int minInd = search(1,0,N-1,s,e);

    ll height = (ll)(e-s+1);
    ll area = arr[minInd] * height;

    // minInd 기준 왼쪽에 더 큰 사각형이 존재하는지 판별
    if(s <= minInd - 1){
        ll tmp = solve(s, minInd-1);
        if(tmp > area){
            area = tmp;
        }
    }

    // minInd 기준 오른쪽에 더 큰 사각형이 존재하는지 판별
    if(e >= minInd + 1){
        ll tmp = solve(minInd+1,e);
        if(tmp > area){
            area = tmp;
        }
    }

    return area;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    arr[100000] = 1000000000;

    std::cin >> N;

    for(int i = 0; i < N; i++){
        std::cin >> arr[i];
    }

    int height = (int)std::ceil(std::log2(N));
    int size = ( 1 << (height+1));
    minTree.resize(size);

    makeTree(1,0,N-1);

    std::cout << solve(0,N-1) << '\n';

    return 0;
}