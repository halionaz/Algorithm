// 연세워터파크
// 세그먼트 트리 & 다이나믹 프로그래밍

// 그냥 다 더하면 되는거 아닌가?
// 근데 문제는 음수 점수를 가진 징검다리가 있다는 점!

// 따라서 dp[i]가 i번째 징검다리까지 밟았을 때의 최대 점수라고 하면
// dp[i-D] ~ dp[i-1] 중 최댓값 + arr[i]와 arr[i]를 비교함

#include <iostream>
#include <vector>
#include <cmath>

typedef long long ll;
const ll llmin = -1e9-1;

int N, D;
ll arr[100001];
std::vector<ll> segDP;

ll max(ll a, ll b){
    return a > b ? a : b;
}

ll makeTree(int node, int s, int e, int ind, ll val){
    if(ind < s || e < ind){
        return segDP[node];
    } else {
        if(s == e){
            return segDP[node] = val;
        } else {
            int mid = (s+e)/2;
            return segDP[node] = max(makeTree(node*2,s,mid,ind,val), makeTree(node*2+1,mid+1,e,ind,val));
        }
    }
}

ll query(int node, int s, int e, int l, int r){
    if(r < s || e < l){
        return llmin;
    } else {
        if(l <= s && e <= r){
            return segDP[node];
        } else {
            int mid = (s+e)/2;
            return max(query(node*2,s,mid,l,r),query(node*2+1,mid+1,e,l,r));
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> D;

    int height = (int)std::ceil(std::log2(N));
    int size = (1 << (height+1));
    segDP.resize(size);

    for(int i = 1; i <= N; i++){
        ll val;
        std::cin >> val;
        makeTree(1,1,N,i,val);
        arr[i] = val;
    }

    for(int i = 2; i <= N; i++){
        makeTree(1,1,N,i,max(arr[i],query(1,1,N,max(1,i-D),i-1)+arr[i]));
    }

    std::cout << segDP[1] << '\n';

    return 0;
}