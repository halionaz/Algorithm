// 구간 합 구하기
// 세그먼트 트리

#include <iostream>
#include <cmath>
#include <vector>

typedef long long ll;

int N,M,K;
std::vector<ll> inpArr;
std::vector<ll> tree;

ll makeSegmentTree(int node, int s, int e){
    if(s == e){
        return tree[node] = inpArr[s];
    } else {
        int mid = (s+e)/2;
        tree[node] = makeSegmentTree(node*2,s,mid) + makeSegmentTree(node*2+1,mid+1,e);
        return tree[node];
    }
}

ll returnSum(int node, int s, int e, int left, int right){
    // left - right의 합을 구해야 한다
    if(left > e || right < s){
        return 0;
    } 
    if(left <= s && e <= right){
        return tree[node];
    }

    int mid = (s+e) / 2;
    return returnSum(node*2,s,mid,left,right) + returnSum(node*2+1,mid+1,e,left,right);
}

void updateTree(int node, int s, int e, int ind, ll diff){
    // ind 인덱스의 숫자를 diff만큼의 차이가 있는 숫자로 바꿈
    if(ind < s || ind > e){
        return;
    } else {

        tree[node] += diff;

        if(s != e){
            int mid = (s+e)/2;
            updateTree(node*2,s,mid,ind,diff);
            updateTree(node*2+1,mid+1,e,ind,diff);
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M >> K;

    for(int i = 0; i < N; i++){
        ll x;
        std::cin >> x;
        inpArr.push_back(x);
    }

    int height = (int)std::ceil(std::log2(N)); // 세그먼트 트리의 높이는 log2(N)을 올림한 값
    int size = (1 << (height+1)); // 세그먼트 트리의 크기는 2**(높이+1)
    tree.resize(size);

    // 세그먼트 트리 만들기
    makeSegmentTree(1, 0, N-1);

    for(int i = 0; i < M+K; i++){
        ll a,b,c;
        std::cin >> a >> b >> c;
        if(a == 1){
            // 트리의 값 바꾸기
            ll diff = c - inpArr[b-1];
            inpArr[b-1] = c;
            updateTree(1,0,N-1,b-1,diff);
        } else {
            // 요소의 합 출력
            std::cout << returnSum(1,0,N-1, b-1, c-1) << '\n';
        }
    }

    return 0;
}