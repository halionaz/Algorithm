// 부분배열 고르기 2
// 세그먼트 트리 & 분할 정복

// 구간의 최솟값과 구간합을 저장하는 세그먼트 트리 2개를 만들고

// 구간의 점수를 구한 후,
// 구간의 최솟값 왼편과 오른편 각각에 더 큰 점수를 가진 구간이 있는지
// 분할정복으로 구함

// 구간의 점수보다 더 큰 점수가 나오기 위해선,
// 구간 중 최솟값을 가지는 아이를 배제한 부분을 계산해봐야 함

// 2104와 같은 문제이지만, 답을 가지는 구간을 함께 출력해줘야 함
// 따라서 재귀함수의 반환값을 struct를 이용해 구간을 함께 반환해주는 식으로 변형

#include <iostream>
#include <vector>
#include <cmath>

typedef long long ll;
const ll inf = 2000000000;

struct solveStruct{
    ll point;
    int start;
    int end;
};

int N;
ll arr[100001];
std::vector<ll> minTree;
// minTree는 구간의 최솟값을 지닌 인덱스를 보관한다
std::vector<ll> sumTree;
// sumTree는 구간의 합을 보관한다

ll makeTree(int node, int s, int e, bool type){
    if( s == e ){
        if(type){
            // minTree
            return minTree[node] = s;
        } else {
            // sumTree
            return sumTree[node] = arr[s];
        }
    } else {
        int mid = (s+e)/2;
        if(type){
            // minTree
            int left = makeTree(node*2,s,mid, true);
            int right = makeTree(node*2+1,mid+1,e, true);
            if(arr[left] < arr[right]){
                return minTree[node] = left;
            } else {
                return minTree[node] = right;
            }
        } else {
            // sumTree
            return sumTree[node] = makeTree(node*2, s, mid, false) + makeTree(node*2+1, mid+1, e, false);
        }
    }
}

ll search(int node, int s, int e, int l, int r, bool type){
    if(r < s || e < l){
        if(type){
            // minTree
            return inf;
        } else {
            // sumTree
            return 0;
        }
    } else {
        if(l <= s && e <= r){
            if(type){
                // minTree
                return minTree[node];
            } else {
                return sumTree[node];
            }
        } else {
            int mid = (s+e)/2;
            if(type){
                int left = search(node*2,s,mid,l,r, true);
                int right = search(node*2+1,mid+1,e,l,r, true);
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
            } else {
                return search(node*2, s, mid, l, r, false) + search(node*2+1, mid+1, e, l, r, false);
            }
        }
    }
}

solveStruct solve(int s, int e){

    solveStruct curAns;
    
    int minInd = search(1,0,N-1,s,e, true);

    curAns.start = s;
    curAns.end = e;
    curAns.point = arr[minInd] * search(1, 0, N-1, s, e, false);

    // minInd 기준 왼쪽에 더 큰 점수가 존재하는지 판별
    if(s <= minInd - 1){
        solveStruct tmp = solve(s, minInd - 1);
        if(tmp.point > curAns.point){
            curAns = tmp;
        }
    }

    // minInd 기준 오른쪽에 더 큰 점수가 존재하는지 판별
    if(e >= minInd + 1){
        solveStruct tmp = solve(minInd+1, e);
        if(tmp.point > curAns.point){
            curAns = tmp;
        }
    }

    return curAns;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 0; i < N; i++){
        std::cin >> arr[i];
    }

    int height = (int)std::ceil(log2(N));
    int size = ( 1 << (height+1));
    minTree.resize(size);
    sumTree.resize(size);

    makeTree(1,0,N-1, true);
    makeTree(1,0,N-1, false);

    solveStruct ans = solve(0,N-1);
    std::cout << ans.point << '\n';
    std::cout << ans.start + 1 << ' ' << ans.end + 1 << '\n';


    return 0;
}