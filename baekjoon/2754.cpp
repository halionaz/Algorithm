// 학점계산
// 구현

#include <iostream>
#include <string.h>

std::string S, ans;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> S;

    if(S == "A+"){
        ans = "4.3";
    } else if(S == "A0"){
        ans = "4.0";
    } else if(S == "A-"){
        ans = "3.7";
    } else if(S == "B+"){
        ans = "3.3";
    } else if(S == "B0"){
        ans = "3.0";
    } else if(S == "B-"){
        ans = "2.7";
    } else if(S == "C+"){
        ans = "2.3";
    } else if(S == "C0"){
        ans = "2.0";
    } else if(S == "C-"){
        ans = "1.7";
    } else if(S == "D+"){
        ans = "1.3";
    } else if(S == "D0"){
        ans = "1.0";
    } else if(S == "D-"){
        ans = "0.7";
    } else if(S == "F"){
        ans = "0.0";
    }

    std::cout << ans << '\n';

    return 0;
}