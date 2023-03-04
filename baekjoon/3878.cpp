// 점 분리
// 볼록 껍질 & 선분 교차 판정 & 볼록 다각형 내부의 점 판정
// ccw 알고리즘 & 그라함 스캔 알고리즘

#include <iostream>
#include <vector>
#include <algorithm>

struct dot{
    int x, y;
    bool operator>(dot a){
        return std::make_pair(x, y) > std::make_pair(a.x, a.y); 
    }
    bool operator<=(dot a){ 
        return std::make_pair(x, y) <= std::make_pair(a.x, a.y); 
    }
};

dot standard;
std::vector<dot> blackDots, whiteDots;

int ccw(dot A, dot B, dot C) {
    int val = (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
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

bool isCross(dot L11, dot L12, dot L21, dot L22){
    // 선분 L1과 선분 L2의 선분 교차성 판단

    int case1 = ccw(L11, L12, L21) * ccw(L11, L12, L22);
    int case2 = ccw(L21, L22, L11) * ccw(L21, L22, L12);

    if(case1 == 0 && case2 == 0){
        // L1, L2가 평행하거나, L1, L2가 한 점에 맞닿아 있음
        if(L11 > L12){
            std::swap(L11, L12);
        }
        if(L21 > L22){
            std::swap(L21, L22);
        }

        if(L21 <= L12 && L11 <= L22){
            // 평행하지만 두 선분이 만남
            return 1;
        } else {
            // 평행하고 안 만남
            return 0;
        }
    } else {
        if(case1 <= 0 && case2 <= 0){
            // 교차하거나, 한 선분의 끝 점만 한 선분에 닿아있음
            return 1;
        } else {
            // ccw의 곱이 양수이므로, 한 선분 기준으로 다른 선분의 양 끝점이 모두 한편에 쏠려있음
            // 즉, 두 선이 만나지 않음
            return 0;
        }
    }

    return 0;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int T;

    std::cin >> T;

    while(T--){

        int N, M;

        std::cin >> N >> M;

        blackDots.resize(N);
        whiteDots.resize(M);

        for(int i = 0; i < N; i++){
            std::cin >> blackDots[i].x >> blackDots[i].y;
        }
        for(int i = 0; i < M; i++){
            std::cin >> whiteDots[i].x >> whiteDots[i].y;
        }

        std::vector<dot> blackHull = getHull(blackDots);
        std::vector<dot> whiteHull = getHull(whiteDots);
        
        bool ans = true;

        // 두 컨벡스 헐이 만나면 안되므로,
        // 우선 컨벡스 헐의 한 점이 다른 컨벡스 헐 내부로 들어가는지 체크
        if(blackHull.size() > 2){
            for(int i = 0; i < whiteHull.size(); i++){
                if(isInner(blackHull, whiteHull[i])){
                    // blackHull 내부에 whiteHull의 점이 있다면
                    ans = false;
                    break;
                }
            }
        }
        if(whiteHull.size() > 2){
            for(int i = 0; i < blackHull.size(); i++){
                if(isInner(whiteHull, blackHull[i])){
                    // whiteHull 내부에 blackHull의 점이 있다면
                    ans = false;
                    break;
                }
            }
        }

        // 그 후, 두 컨벡스 헐에 겹치는 선분이 있는지 체크
        for(int i = 0; i < blackHull.size(); i++){
            for(int j = 0; j < whiteHull.size(); j++){
                if(isCross(blackHull[i], blackHull[(i+1) % blackHull.size()], whiteHull[j], whiteHull[(j+1) % whiteHull.size()])){
                    // blackHull과 whiteHull에 겹치는 선분이 있다면
                    ans = false;
                    break;
                }
            }
        }

        std::cout << (ans ? "YES" : "NO") << '\n';

    }

    return 0;
}
