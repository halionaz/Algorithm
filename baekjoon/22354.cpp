// 돌 가져가기
// 그리디 알고리즘 & 정렬

// 최적해는
// 돌이 WBWBWBWBWB... 와 같이 번갈아가며 N개 배치되어있을 때,
// 무게가 무거운 ceil((N-2)/2)개의 합

// 돌이 WW와 같이 겹쳐져 있으면 어차피 하나는 포기해야 하므로
// 둘 중 무거운 것만 남김

// https://static.ucpc.me/files/2021/ucpc21-prelim-solutions.pdf
// https://nicotina04.tistory.com/223
// 두 링크 참조

#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

int N;
char color[300001];
int weight[300001];
std::vector<int> realArr;

int main() {
    
    std::cin >> N;
    std::cin >> color;

    for (int i = 0; i < N; i++) {
        std::cin >> weight[i];
    }

    int prevMax = weight[0];

    for (int i = 1; i < N; i++) {
        if (color[i - 1] == color[i]) {
            prevMax = std::max(prevMax, weight[i]);
        } else {
            realArr.push_back(prevMax);
            prevMax = weight[i];
        }
    }
    realArr.push_back(prevMax);

    ll ans = 0;

    if (realArr.size() <= 2) {
        std::cout << 0 << '\n';
    } else {
        std::sort(realArr.begin() + 1, realArr.end() - 1);

        for (int i = 0; i < (realArr.size() - 1) / 2; i++) {
            ans += realArr.rbegin()[1 + i];
        }

        std::cout << ans << '\n';
    }


    return 0;
}