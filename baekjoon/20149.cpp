// 선분 교차 3
// 기하학 & 선분 교차 판정 & 많은 조건 분기
// ccw 알고리즘

#include <iostream>
#include <utility>

typedef long long ll;

ll ccw(std::pair<ll, ll> A, std::pair<ll, ll> B, std::pair<ll, ll> C){
    ll ret = (A.first * B.second + B.first * C.second + C.first * A.second) - (B.first * A.second + C.first * B.second + A.first * C.second);

    if(ret == 0){
        return ret;
    } 
    if(ret < 0){
        // 시계 방향
        return -1;
    } else {
        // 반시계 방향
        return 1;
    }
}

std::pair<ll, ll> L11, L12, L21, L22;

void findCrossPoint(){
	double px = (L11.first * L12.second - L11.second * L12.first) * (L21.first - L22.first) - (L11.first - L12.first) * (L21.first * L22.second - L21.second * L22.first);
	double py = (L11.first * L12.second - L11.second * L12.first) * (L21.second - L22.second) - (L11.second - L12.second) * (L21.first * L22.second - L21.second * L22.first);
	double p = (L11.first - L12.first) * (L21.second - L22.second) - (L11.second - L12.second) * (L21.first - L22.first);

    if(p != 0){
        // 선분이 교차
        double x = px / p;
        double y = py / p;
        std::cout << std::fixed;
        std::cout.precision(10);
        std::cout << x << ' ' << y << '\n';
    } else {
        // 선분이 평행
        if(L12 == L21 && L11 <= L21){
            // L12에서 만남
            std::cout << L12.first << ' ' << L12.second << '\n';
        } else if(L11 == L22 && L21 <= L11){
            // L11에서 만남
            std::cout << L11.first << ' ' << L11.second << '\n';
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> L11.first >> L11.second;
    std::cin >> L12.first >> L12.second;
    std::cin >> L21.first >> L21.second;
    std::cin >> L22.first >> L22.second;

    ll case1 = ccw(L11, L12, L21) * ccw(L11, L12, L22);
    ll case2 = ccw(L21, L22, L11) * ccw(L21, L22, L12);

    if(case1 == 0 && case2 == 0){
        // L1, L2가 평행하거나, L1, L2가 한 점에 맞닿아 있음
        if(L11 > L12){
            std::swap(L11, L12);
        }
        if(L21 > L22){
            std::swap(L21, L22);
        }

        if(L12 >= L21 && L11 <= L22){
            // 평행하지만 두 선분이 만남
            std::cout << 1 << '\n';
            findCrossPoint();
        } else {
            // 평행하고 안 만남
            std::cout << 0 << '\n';
        }
    } else {
        if(case1 <= 0 && case2 <= 0){
            // 교차하거나, 한 선분의 끝 점만 한 선분에 닿아있음
            std::cout << 1 << '\n';
            findCrossPoint();
        } else {
            // ccw의 곱이 양수이므로, 한 선분 기준으로 다른 선분의 양 끝점이 모두 한편에 쏠려있음
            // 즉, 두 선이 만나지 않음
            std::cout << 0 << '\n';
        }
    }

    return 0;
}