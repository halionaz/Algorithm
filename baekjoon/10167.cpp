// 금광
// 세그먼트 트리 & 값 / 좌표 압축 & 스위핑 & 분할 정복

// 분할정복 개념을 적용한 세그 노드에 관련된 설명은 16993.cpp를 참조

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long ll;

struct segNode{
    // i ~ j 구간에 대한 정보를 저장
    // sum :: i ~ j 구간 합
    // left :: i ~ k 구간 최대 연속합
    // right :: k ~ j 구간 최대 연속합
    // mid :: k ~ p 구간 최대 연속합
    ll sum, left, right, mid;
};
struct mine{

    ll x, y, w;

	bool operator < (const mine &p) const {
		if(y == p.y){
            // y 좌표가 같다면
		    return x < p.x;
        } else {
            return y < p.y;
        }
	}
};

int N;
std::vector<mine> mines;
std::vector<segNode> segTree;
// 좌표 압축용 벡터
std::vector<ll> xVec;
std::vector<ll> yVec;

segNode updateTree(int node, int s, int e, int ind, int val){
    if(ind < s || e < ind){
        return segTree[node];
    } else {
        if(s == e){
            segTree[node].sum += val;
            segTree[node].left += val;
            segTree[node].right += val;
            segTree[node].mid += val;
            return segTree[node];
        } else {
            int mid = (s+e)/2;
            segNode left = updateTree(node*2, s, mid, ind, val);
            segNode right = updateTree(node*2+1, mid+1, e, ind, val); 

            segTree[node].sum = left.sum + right.sum;
            segTree[node].left = std::max(left.left, left.sum + right.left);
            segTree[node].right = std::max(right.right, right.sum + left.right);
            segTree[node].mid = std::max(std::max(right.mid, left.mid), left.right + right.left);
            return segTree[node];
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;
    mines.resize(N);

    // segtree 크기 지정
    int height = (int)std::ceil(log2(N));
    int size = (1<<(height+1));
    segTree.resize(size);

    for(int i = 0; i < N; i++){
        std::cin >> mines[i].x >> mines[i].y >> mines[i].w;
        xVec.push_back(mines[i].x);
        yVec.push_back(mines[i].y);
    }

    std::sort(xVec.begin(), xVec.end());
    std::sort(yVec.begin(), yVec.end());

    // 중복값 삭제
    xVec.erase(unique(xVec.begin(), xVec.end()), xVec.end());
    yVec.erase(unique(yVec.begin(), yVec.end()), yVec.end());

    // 압축값으로 좌표 변경
    for(int i = 0; i < N; i++){
        mines[i].x = lower_bound(xVec.begin(), xVec.end(), mines[i].x) - xVec.begin();
        mines[i].y = lower_bound(yVec.begin(), yVec.end(), mines[i].y) - yVec.begin();
    }

    // y값 기준으로 정렬됨
    std::sort(mines.begin(), mines.end());

    ll ans = 0;

    for(int i = 0; i < N; i++){
		if(i > 0 && mines[i-1].y == mines[i].y){
            // 이미 탐색한 범위,
            // 이 경우에 대해 탐색을 정상 진행해버리면
            // y좌표가 mines[i].y 이지만, mines[i].x보다 작은 x좌표를 가지고 있는 금광이 계산에서 배제되므로
            // 오답을 출력할 수 있음
            continue;
        }

        // y 좌표가 고정됨
        // y 좌표가 mines[i].y 이상인 금광에 대해서 탐색

        // segTree 초기화
        for(int j = 0; j < size; j++){
            segTree[j].left = segTree[j].right = segTree[j].sum = segTree[j].mid = 0;
        }

        // y좌표 범위가 고정되어 있고, y 좌표가 같은 경우 x 좌표가 작은 값 먼저 정렬되어 있으므로
        // 탐색 순서 상 문제 없음
        
        for(int j = i; j < N; j++){

            // 이거 범위 지정 때문에 2시간 해멨다..
            // 좌표 압축을 하면 0까지 나와버리기 때문에 탐색 범위를 1 ~ N이 아닌
            // 0 ~ N-1까지 해야 함
            updateTree(1, 0, N-1, mines[j].x, mines[j].w);

            if(j == N-1 || mines[j].y != mines[j+1].y){
                ans = std::max(ans, segTree[1].mid);
            }
        }
    }

    std::cout << ans << '\n';

    return 0;
}