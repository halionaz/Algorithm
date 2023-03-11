// 감옥 건설
// 볼록 껍질 & 볼록 다각형 내부의 점 판정
// ccw 알고리즘 & 그라함 스캔 알고리즘

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

typedef long long ll;

struct dot{
    ll x, y;

    bool operator==(const dot &input){
        return (x == input.x) && (y == input.y);
    }

};

dot standard;

int ccw(dot A, dot B, dot C) {
    ll val = (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
    if(val > 0){
        return 1;
    } else if(val == 0){
        return 0;
    } else {
        return -1;
    }
}

bool cmp1(dot n1, dot n2){
    if(n1.y == n2.y){
        return n1.x < n2.x;
    } else {
        return n1.y < n2.y;
    }
}

bool cmp2(dot n1, dot n2){
    int cp = ccw(standard, n1, n2);
    if(cp){
        return cp > 0;
    } else {
        // ccw가 0일 경우 (직선일 경우) 좌표가 작은 순으로 나열
        return std::abs(n1.x + n1.y) < std::abs(n2.x + n2.y);
    }
}

std::vector<dot> getHull(std::vector<dot> &dots){

    std::vector<dot> ret;

    // 일단 y좌표와 x좌표가 작은 순으로 정렬해 기준 좌표를 만듦
    std::sort(dots.begin(),dots.end(), cmp1);

    standard = dots[0];

    // 기준 좌표를 제외한 나머지는 반시계 방향으로 정렬
    std::sort(dots.begin()+1, dots.end(), cmp2);

    // 스택에 두개의 점 넣고 시작
    ret.push_back(dots[0]);

    if(dots.size() < 2){
        return ret;
    }

    ret.push_back(dots[1]);

    for(int i = 2; i < dots.size(); i++){
        while(ret.size() >= 2){
            dot n1 = ret.back();
            ret.pop_back();
            dot n2 = ret.back();

            if(ccw(n2,n1,dots[i]) > 0){
                // ccw가 맞을때만 n1을 stack에 넣어준다

                ret.push_back(n1);
                break;
            }
        }

        ret.push_back(dots[i]);

    }

    return ret;

};

bool isInner(std::vector<dot> &dots, dot &p) {

    int dotCCW = ccw(dots[0], dots[1], p);

    for (int i = 1; i < dots.size(); i++) {
        if (dotCCW * ccw(dots[i], dots[(i + 1) % dots.size()], p) <= 0){
            return false;
        }
    }
    return true;
}

std::vector<dot> dots;

int main(void) {

	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	int N;
	std::cin >> N;

	dot cow;
	std::cin >> cow.x >> cow.y;

	for (int i = 0; i < N; i++) {
        dot X;
		std::cin >> X.x >> X.y;
		dots.push_back(X);
	}
	
	int ans = 0;

	while (true) {
		// 더이상 볼록 껍질을 만들 수 없으면 종료
		if (dots.size() < 3) break;

		std::vector<dot> hull = getHull(dots);

		//볼록 껍질 내부에 감옥이 있는지 확인
		if (isInner(hull, cow)) {
			ans += 1;
			// dots에서 hull에 포함된 점 제거
			for (int i = 0; i < hull.size(); ++i){
				dots.erase(find(dots.begin(), dots.end(), hull[i]));
            }
		} else {
            break;
        }
	}

	std::cout << ans << '\n';
	return 0;
}