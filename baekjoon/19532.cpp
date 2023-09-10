// 수학은 비대면강의입니다
// 브루트포스 알고리즘

// #include <iostream>

// int a, b, c, d, e, f;

// int main(){

//     std::ios_base::sync_with_stdio(0);
//     std::cin.tie(0);

//     std::cin >> a >> b >> c >> d >> e >> f;

//     for(int x = -999; x <= 999; x++){
//         for(int y = -999; y <= 999; y++){
//             if(a * x + b * y == c && d * x + e * y == f){
//                 // 조건을 만족하는 해
//                 std::cout << x << ' ' << y << '\n';
//                 return 0;
//             }
//         }
//     }

//     return 0;
// }

// 수학은 비대면강의입니다
// 수학

#include <iostream>

int a, b, c, d, e, f;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> a >> b >> c >> d >> e >> f;

    int y = (c * d - a* f) / (b * d - a * e);

    int x;

    if(a == 0){
        x = (f - e * y) / d;
    } else {
        x = (c - b * y) / a;
    }

    std::cout << x << ' ' << y << '\n';

    return 0;
}