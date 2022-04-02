// 가장 가까운 두 점
// 스위핑

// 분할 정복으로 푸는 것이 정석인 문제.
// 나중에 분할 정복 방식으로도 복습 필요

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

typedef std::pair<int, int> p;

const long long inf = 1 << 30;

int N;
std::vector<p> arr;
std::set<p> candidate; 
// 가까운 점의 후보군을 넣는 set container
// 중복 좌표가 있어, set을 이용해 중복 좌표 처리

int dist(p a, p b){
    int xd = a.first - b.first;
    int yd = a.second - b.second;
    return (xd*xd + yd*yd);
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 0; i < N; i++){
        int x, y;
        std::cin >> x >> y;
        arr.push_back(std::make_pair(x,y));
    }

    std::sort(arr.begin(), arr.end());

    int ind = 0;
    int ans = dist(arr[0], arr[1]);

    candidate.insert(std::make_pair(arr[0].second, arr[0].first));
    candidate.insert(std::make_pair(arr[1].second, arr[1].first));

    for(int i = 2; i < N; i++){
        // 이전 점들과의 거리
        while(ind < i){
            int d = arr[i].first - arr[ind].first;
            if(d*d > ans){
                // ans보다 x 좌표 사이 거리가 멀면 candidate에서 제거
                candidate.erase(std::make_pair(arr[ind].second, arr[ind].first));
                ind++;
            } else {
                // 거리가 범주 안으로 들어오면 stop
                break;
            }
        }

        // x 좌표는 이미 고려했으므로, y좌표만 고려해보면 됨
        // y 좌표를 따졌을 때 최솟값이 될 수 있는 s,e 찾기
        std::set<p>::iterator s = candidate.lower_bound(std::make_pair(arr[i].second - std::sqrt(ans), -inf));
        std::set<p>::iterator e = candidate.upper_bound(std::make_pair(arr[i].second + std::sqrt(ans), inf));
        for(std::set<p>::iterator iter = s; iter != e; iter++){
            ans = std::min(ans, dist(arr[i], std::make_pair(iter->second, iter->first)));
        }
        candidate.insert(std::make_pair(arr[i].second, arr[i].first));
    }

    std::cout << ans << '\n';

    return 0;
}