// 세 막대
// 기하학 & 수학

#include <iostream>
#include <algorithm>

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int len[3];

    std::cin >> len[0] >> len[1] >> len[2];

    // 길이 순 정렬
    std::sort(len, len + 3);

    if(len[2] < len[0] + len[1]){
        std::cout << len[0] + len[1] + len[2] << '\n';
    } else {
        std::cout << 2 * (len[0] + len[1]) - 1 << '\n';
    }

    return 0;
}