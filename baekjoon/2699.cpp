// 격자점 컨벡스헐
// 기하학 & 볼록 껍질
// ccw 알고리즘 & 그라함 스캔 알고리즘

#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

struct dot {
	ll x, y;
};
std::vector<dot> dots;

ll ccw(dot A, dot B, dot C) {
	return (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
}

ll dist(dot a, dot b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

bool cmp(const dot& a, const dot& b) {
	int val = ccw(dots[0], a, b);
    if(val){
        return val < 0;
    } else {
        // ccw가 0일 경우 (직선일 경우) 시작점으로부터 거리가 짧은 순으로
        return dist(dots[0], a) < dist(dots[0], b);
    }
}

int main() {
	std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

	int n,t;
	std::cin >> t;
	while (t--) {

		std::cin >> n;

		dots.clear();
		dots.resize(n);

		for (int i = 0; i < n; i++){
			std::cin >> dots[i].x >> dots[i].y;
        }

        int temp = 0;
        for (int i = 1; i < dots.size();i++){
            if (dots[i].y > dots[temp].y || (dots[i].y == dots[temp].y && dots[i].x < dots[temp].x)){
                temp = i;
            }
        }

        std::swap(dots[temp], dots[0]); // 시작점 지정
        std::sort(dots.begin() + 1, dots.end(), cmp);

        std::vector<dot> stack;

        for (int i = 0; i < dots.size(); i++) {

            // 스택에 두 개 보다 많은 점이 들어가 있을 때,
            // ccw로 외곽점 체크
            // 꼭짓점이 아니라 외곽선 위에 있다면 답에 미포함
            while (2 <= stack.size() && ccw(stack[stack.size() - 2], stack[stack.size() - 1], dots[i]) >= 0){
                stack.pop_back();
            }
            stack.push_back(dots[i]);
        }

        std::cout << stack.size() << '\n';

        for (int i = 0;i < stack.size();i++){
            std::cout << stack[i].x << " " << stack[i].y << '\n';
        }
	}
	return 0;
}