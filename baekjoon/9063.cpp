// 대지
// 기하학 & 수학

#include <iostream>
#include <algorithm>

int N;
long long ans;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int maxX = -10001;
    int maxY = -10001;
    int minX = 10001;
    int minY = 10001;

    std::cin >> N;

    for(int i = 0; i < N; i++){
        int x, y;
        std::cin >> x >> y;
        maxX = std::max(maxX, x);
        maxY = std::max(maxY, y);
        minX = std::min(minX, x);
        minY = std::min(minY, y);
    }

    ans = (maxX - minX) * (maxY - minY);
    std::cout << ans << '\n';

    return 0;
}