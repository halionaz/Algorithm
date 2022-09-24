// 재귀의 귀재
// 재귀

#include <iostream>
#include <string>

typedef long long ll;

int T;
std::string S;
ll ans;

int isPalindrome(std::string &S, int l, int r){
    ans++;
    if(l >= r){
        return 1;
    } else if(S[l] != S[r]){
        return 0;
    } else {
        return isPalindrome(S, l+1, r-1);
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;

    while(T--){

        ans = 0;

        std::cin >> S;

        std::cout << isPalindrome(S, 0, S.length()-1) << ' ';
        std::cout << ans << '\n';
    }

    return 0;
}