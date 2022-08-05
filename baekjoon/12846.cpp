// 무서운 아르바이트
// 세그먼트 트리 & 분할 정복

// 6549, 히스토그램에서 가장 큰 직사각형과 동치인 문제
// 구간의 최솟값을 저장한 이후
// 최솟값 * 구간을 사각형의 넓이로 산정하고
// 그 최솟값 왼편과 오른편 각각에 더 넓은 사각형이 있는지를 분할정복으로 구함

#include <iostream>
#include <vector>
#include <cmath>

typedef long long ll;
const ll inf = 2000000000;

int n;
ll arr[100001];
std::vector<ll> minTree; // 구간의 가장 적은 일급 날짜를 저장

ll makeTree(int node, int s, int e){
    if(s == e){
        return minTree[node] = s;
    } else {
        int mid = (s+e)/2;
        int left = makeTree(node*2, s, mid);
        int right = makeTree(node*2+1, mid+1, e);

        if(arr[left] < arr[right]){
            return minTree[node] = left;
        } else {
            return minTree[node] = right;
        }
    }
}
ll query(int node, int s, int e, int l, int r){
    if(r < s || e < l){
        return inf;
    } else {
        if(l <= s && e <= r){
            return minTree[node];
        } else {
            int mid = (s+e)/2;
            int left = query(node*2, s, mid, l, r);
            int right = query(node*2+1, mid+1, e, l, r);
            if(left == inf){
                return right;
            } else if(right == inf){
                return left;
            } else if(arr[left] < arr[right]){
                return left;
            } else {
                return right;
            }
        }
    }
}

ll solve(int s, int e){

    // 가장 적은 일급 날짜 구하기
    int minIndex = query(1, 0, n-1, s, e);

    ll width = (ll)(e-s+1);
    ll area = arr[minIndex]*width;

    // minIndex 기준 왼쪽에 더 큰 사각형이 존재하는지 판별
    if(s <= minIndex - 1){
        ll tmp = solve(s, minIndex-1);
        if(tmp > area){
            area = tmp;
        }
    }

    // minIndex 기준 오른쪽에 더 큰 사각형이 존재하는지 판별
    if(e >= minIndex + 1){
        ll tmp = solve(minIndex+1, e);
        if(tmp > area){
            area = tmp;
        }
    }

    return area;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;

    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
    }

    int height = (int)std::ceil(std::log2(n));
    int size = (1<<(height+1));
    minTree.resize(size);

    makeTree(1, 0, n-1);

    std::cout << solve(0,n-1) << '\n';

    return 0;
}