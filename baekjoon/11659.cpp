// 구간 합 구하기 4
// 누적 합

#include <iostream>

int N,M;
int numArr[100001];
int sumDP[100001]; // sumDP[i] :: 1~i까지의 누적합

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    sumDP[0] = 0;

    std::cin >> N >> M;

    for(int i = 1; i <=N; i++){
        std::cin >> numArr[i];
        sumDP[i] = sumDP[i-1] + numArr[i];
    }

    while(M--){
        int i,j;
        std::cin >> i >> j;

        std::cout << sumDP[j]-sumDP[i-1] << '\n';

    }

    return 0;
}