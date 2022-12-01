// 북서풍
// 세그먼트 트리 & 값 / 좌표 압축 & 스위핑

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

const int maxN = 100000;

int T, N, x, y;
int seg[4 * maxN];
int yPosCnt[maxN];
std::pair<int,int> a[maxN + 1];

bool compare(std::pair<int, int> a, std::pair<int, int> b) {
    if (a.first == b.first){
        return a.second > b.second;
    } else {
        return a.first < b.first;
    }
}

int updateTree(int node, int s, int e, int ind, int val) {
    if (e < ind || ind < s){
        return seg[node];
    } else {
        if (s == e){
            return seg[node] = val;
        } else {
            int mid = (s + e) >> 1;
            return seg[node] = updateTree(node * 2, s, mid, ind, val) + updateTree(node * 2 + 1, mid + 1, e, ind, val);
        }
    }
}

int searchTree(int node, int s, int e, int l, int r) {
    if (e < l || r < s){
        return 0;
    } else {
        if (l <= s && e <= r){
            return seg[node];
        } else {
            int mid = (s + e) >> 1;
            return searchTree(node * 2, s, mid, l, r) + searchTree(node * 2 + 1, mid + 1, e, l, r);
        }
    }
}

int main() {

    scanf("%d", &T);

    while (T--) {

        memset(seg, 0, sizeof(seg));
        memset(yPosCnt, 0, sizeof(yPosCnt));
        long long res = 0;

        scanf("%d", &N); // 섬의 개수

        std::vector<int> yPosition; // 섬의 y 좌표만 모아 저장

        for (int i = 0; i < N; i++) {
            scanf("%d%d", &x, &y);
            yPosition.push_back(y);
            a[i] = std::make_pair(x,y); // 실제 좌표는 따로 저장
        }

        sort(a, a + N, compare); // x좌표를 기준으로 오름차순 정렬하고, 좌표가 같다면 y좌표 내림차순 
        sort(yPosition.begin(), yPosition.end());
        yPosition.erase(unique(yPosition.begin(), yPosition.end()), yPosition.end());
        // 중복되는 것 삭제

        // 반복문은 x좌표가 작은 섬부터 돌게 됨
        for (int i = 0; i < N; i++) {
            // 현재 섬의 y값이 전체 섬에서 몇번째로 큰 값인지 구하기
            int z = lower_bound(yPosition.begin(), yPosition.end(), a[i].second) - yPosition.begin();
            yPosCnt[z]++;
            // 현재 섬보다 x값이 작은 섬 중에 y값이 더 큰 섬이 몇개인지 구하기
            res += (long long)searchTree(1, 0, N - 1, z, N - 1);
            updateTree(1, 0, N - 1, z, yPosCnt[z]);
        }

        printf("%lld\n", res);

    }
    return 0;
}