// 이 별은 무슨 색일까
// 구현

#include <iostream>
#include <string>

int wl;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> wl;

    std::string res;

    if(wl >= 620 && wl <= 780){
        res = "Red";
    } else if(wl >= 590){
        res = "Orange";
    } else if(wl >= 570){
        res = "Yellow";
    } else if(wl >= 495){
        res = "Green";
    } else if(wl >= 450){
        res = "Blue";
    } else if(wl >= 425){
        res = "Indigo";
    } else {
        res = "Violet";
    }

    std::cout << res << '\n';

    return 0;
}