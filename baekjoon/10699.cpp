// 오늘 날짜
// 구현

#include <iostream>
#include <ctime>

int main(void) {
    struct tm *t;
    time_t timer;
    timer = time(NULL);
    t = localtime(&timer);

    std::cout<<t->tm_year + 1900<<"-";
    std::cout.width(2);
    std::cout.fill('0');
    std::cout<<t->tm_mon + 1<<"-";
    std::cout.width(2);
    std::cout.fill('0');
    std::cout<<t->tm_mday + 1 << '\n';
    return 0;
}