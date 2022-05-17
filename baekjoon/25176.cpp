// 청정수열 (Easy)
// 조합론 & 그리디 알고리즘 & 수학

// 문제가 좀 꼬였지만, 결국 N이 주어졌을 때 N!을 반환하면 됨
// ex) N = 3일 때, 청정 수열은 [1,1,2,2,3,3] 또는 [1,1,3,3,2,2] 등으로 나타나므로, [1,2,3]을 열거하는 것과 같음

#include <iostream>

int N;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int ans = 1;

    std::cin >> N;

    for(int i = 1; i <= N; i++){
        ans *= i;
    }

    std::cout << ans << '\n';

    return 0;
}