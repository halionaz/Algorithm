// 나무 심기
// 세그먼트 트리 

// 새로운 나무를 심는 데 드는 비용
// 심을 나무의 왼쪽 구간의 나무 개수 X 심을 나무의 위치 - 왼쪽 나무들의 위치 합
// +
// 오른쪽 나무들의 위치 합 - 심을 나무의 오른쪽 구간의 나무 개수 X 심을 나무의 위치

// 매개 변수로 넘겨주는 tree 때문에 엄청 애먹었다...
// &를 추가해야 됐다니,, C++ 지식의 부족 이슈로 오래걸렸던 문제

#include <iostream>
#include <vector>

typedef long long ll;

int N, x;
ll ans = 1;
ll mod = 1000000007;
std::vector<ll> posTree(900000); // 각 나무의 위치를 저장하는 트리
std::vector<ll> densTree(900000); // 각 위치별 나무 개수 저장

ll updateTree(std::vector<ll> &segTree, int node, int s, int e, int ind, ll diff){
    if(ind < s || e < ind){
        return segTree[node];
    } else {
        if(s == e){
            return segTree[node] += diff;
        } else {
            int mid = (s + e) / 2;
            return segTree[node] = updateTree(segTree, node*2, s, mid, ind, diff) + updateTree(segTree, node*2+1, mid+1, e, ind, diff);
        }
    }
}

ll query(std::vector<ll> &segTree, int node, int s, int e, int l, int r){
    if(r < s || e < l){
        return 0;
    } else {
        if(l <= s && e <= r){
            return segTree[node];
        } else {
            int mid = (s + e) / 2;
            return query(segTree, node*2, s, mid, l, r) + query(segTree, node*2+1, mid + 1, e, l, r);
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 0; i < N; i++){
        std::cin >> x;
        if(i > 0){
            // 계산 시작
            ll left_num = 0, left_sum = 0, right_num = 0, right_sum = 0;
            if(x > 0){
                left_num = query(densTree, 1, 0, 199999, 0, x - 1);
                left_sum = (left_num * x - query(posTree, 1, 0, 199999, 0, x - 1)) % mod;
            }
            if(x < 199999){
                right_num = query(densTree, 1, 0, 199999, x + 1, 199999);
                right_sum = (query(posTree, 1, 0, 199999, x + 1, 199999) - right_num * x) % mod;
            }

            ll cost = (left_sum + right_sum) % mod;

            ans *= cost;
            ans %= mod;
        }

        updateTree(densTree, 1, 0, 199999, x, 1);
        updateTree(posTree, 1, 0, 199999, x, x);
    }

    std::cout << ans << '\n';

    return 0;
}