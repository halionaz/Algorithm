// blobhyperthink
// 세그먼트 트리 & 다이나믹 프로그래밍

// query(l,x) :: 길이가 l이면서 x로 끝나는 증가 수열 개수
// query(l, x) = query(l-1, 1) + query(l-1, 2) + ... + query(l-1, x-1)

#include <iostream>

const int N = 100001;
const int mod = 1e9 + 7;

int n;
int segTree[12][N];

void update(int l, int x, int val){

    for (; x < N; x += x & -x){
        segTree[l][x] += val;
        if (segTree[l][x] >= mod){
            segTree[l][x] -= mod;
        }
    }

}
int query(int l, int x, int ret = 0){

    // l의 길이를 가지고, x 이하의 수로 끝나는 수열의 개수 반환
    for(; x; x -= x & -x){
        ret += segTree[l][x];
        if(ret >= mod){
            ret -= mod;
        }
    }

    return ret;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;

    for(int i = 1; i<= n; i++){
        int x;
        std::cin >> x;
        update(1, x, 1);

        for(int l = 1; l < 11; l++){
            // 상위 노드 업데이트
            int val = query(l, x - 1);
            update(l + 1, x, val);
        }
    }

    std::cout << query(11, 100000) << '\n';

    return 0;
}