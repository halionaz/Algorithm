// 당근 볶기
// 그리디 알고리즘 & 우선순위 큐

// [1088번: 케이크]와 유사한 문제

// 여러 개의 당근 조각이 있을 때, 이를 잘라서 조각 간의 무게 차이를 최소화 하는 문제
// 당연히 무게가 다른 두 당근 조각이 있을 때, 무게가 큰 것을 잘라야 조각 간의 무게 차가 줄어듦
// 큰 친구를 자를 때에는 처음엔 1/2, 그 다음엔 1/3, 1/4, 1/5 ... 식으로 잘라줘야 나뉜 덩이가 균일한 채로 계속 줄어듦 

// 무게가 큰 조각을 항상 잘라주어야 하므로 우선순위 큐를 이용해 큰 조각을 바로 확인할 수 있도록 함

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

int N, ans = 0;
double T, minCarrot, ratio;
std::priority_queue<std::pair<double, int> > pq;
// pq.top().first :: 가장 큰 친구의 무게
// pq.top().second :: 가장 큰 친구의 인덱스
std::vector<std::pair<double, int> > carrots; 
// cakes[i].first :: i번째 인덱스 당근의 원래 무게
// cakes[i].second :: i번째 인덱스 당근의 분할 수

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T >> N;

    carrots.resize(N);

    for(int i = 0; i < N; i++){
        std::cin >> carrots[i].first;
        carrots[i].second = 1;
        pq.push(std::make_pair(carrots[i].first, i));

        // 당근 조각 중 가장 작은 무게 구하기
        if(i == 0){
            minCarrot = carrots[i].first;
        } else {
            minCarrot = std::min(minCarrot, carrots[i].first);
        }
    }

    ratio = minCarrot / pq.top().first;

    while (true) {

        // 비율이 만족될 때까지 자르기
        if(ratio > T){
            break;
        }

        ans++;

        int maxCarrotInd = pq.top().second;
        pq.pop();

        double newPiece = carrots[maxCarrotInd].first / ++carrots[maxCarrotInd].second;
        // 조각 추가
        pq.push(std::make_pair(newPiece, maxCarrotInd));

        minCarrot = std::min(minCarrot, newPiece);
        ratio = std::max(ratio, minCarrot / pq.top().first);

    }

    std::cout << ans << '\n';

    return 0;
}