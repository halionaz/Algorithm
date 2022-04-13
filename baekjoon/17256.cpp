// 달달함이 넘쳐흘러
// 사칙연산

#include <iostream>

struct cake{
    int x,y,z;
};

int main(){


    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    cake a, c;

    std::cin >> a.x >> a.y >> a.z;
    std::cin >> c.x >> c.y >> c.z;

    std::cout << c.x - a.z << ' ' << c.y/a.y << ' ' << c.z - a.x << '\n';
    
    return 0;
}