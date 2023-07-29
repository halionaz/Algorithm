// 진법 변환
// 수학 & 문자열 & 구현

#include <iostream>
#include <string>

std::string S;
int B;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie();

    std::cin >> S >> B;

    int ans = 0;
    int digit = 1;

    for(int i = S.length() - 1; i >= 0; i--){
        if('9' >= S[i] && S[i] >= '0'){
            // 숫자
            ans += (S[i] - '0') * digit;
        } else {
            // 문자
            ans += (S[i] - 'A' + 10) * digit;
        }
        digit *= B;
    }

    std::cout << ans << '\n';

    return 0;

}