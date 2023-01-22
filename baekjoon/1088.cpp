// 케이크
// 그리디 알고리즘 & 우선순위 큐

// 여러 개의 케이크 조각이 있을 때, 이를 잘라서 조각 간의 무게 차이를 최소화 하는 문제
// 당연히 무게가 다른 두 케이크 조각이 있을 때, 무게가 큰 것을 잘라야 조각 간의 무게 차가 줄어듦
// 큰 친구를 자를 때에는 처음엔 1/2, 그 다음엔 1/3, 1/4, 1/5 ... 식으로 잘라줘야 나뉜 덩이가 균일한 채로 계속 줄어듦 

// 무게가 큰 조각을 항상 잘라주어야 하므로 우선순위 큐를 이용해 큰 조각을 바로 확인할 수 있도록 함

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

int N, M;
double minCake, ans;
std::priority_queue<std::pair<double, int> > pq;
// pq.top().first :: 가장 큰 친구의 무게
// pq.top().second :: 가장 큰 친구의 인덱스
std::vector<std::pair<double, int> > cakes; 
// cakes[i].first :: i번째 인덱스 케이크의 원래 무게
// cakes[i].second :: i번째 인덱스 케이크의 분할 수

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    cakes.resize(N);

    for(int i = 0; i < N; i++){
        std::cin >> cakes[i].first;
        cakes[i].second = 1;
        pq.push(std::make_pair(cakes[i].first, i));

        // 케이크 조각 중 가장 작은 무게 구하기
        if(i == 0){
            minCake = cakes[i].first;
        } else {
            minCake = std::min(minCake, cakes[i].first);
        }
    }

    std::cin >> M;

    ans = pq.top().first - minCake;

    for(int i = 0; i < M; i++){ // M번 자르기
        int maxCakeInd = pq.top().second;
        pq.pop();

        double newPiece = cakes[maxCakeInd].first / ++cakes[maxCakeInd].second;
        // 조각 추가
        pq.push(std::make_pair(newPiece, maxCakeInd));

        minCake = std::min(minCake, newPiece);
        ans = std::min(ans, pq.top().first - minCake);
    }

    std::cout << std::fixed;
    std::cout.precision(10);
    std::cout << ans << '\n';

    return 0;
}