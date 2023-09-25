// 가로수
// 정수론 & 유클리드 호제법

#include <iostream>

typedef long long ll;

ll GCD(ll a, ll b){
    // 최대공약수 반환하는 함수

    if(a < b){
        ll tmp = a;
        a = b;
        b = tmp;
    }

    while(b){
        ll tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
    
}

int N;
ll gap;
ll treePos[100001];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;


    for(int i = 0; i < N; i++){
        std::cin >> treePos[i];

        if(i == 1){
            // 2번째 나무인 경우, 그 전 나무까지의 거리 기록
            gap = treePos[1] - treePos[0];
        } else if(i > 1){
            // 3번째 나무부턴 갭 간 최대공약수를 구해, 최종 나무 간 거리를 구함
            gap = GCD(gap, treePos[i] - treePos[i-1]);
        }
    }

    // 전체 나무의 수는 (전체 거리 / 나무 간 거리) + 1 이고,
    // 새로 심어야 할 나무의 수는 이 전체 나무의 수에서 심겨져 있는 나무 개수를 뺀 것
    std::cout << ((treePos[N-1] - treePos[0]) / gap) + 1 - N << '\n';

    return 0;
}