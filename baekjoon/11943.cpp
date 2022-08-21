// 파일 옮기기
// 수학

#include <algorithm>
#include <iostream>

int a, b, c, d;

int main(){

    std::cin >> a >> b >> c >> d;

    std::cout << std::min(a + d, b + c) << '\n';

    return 0;
}