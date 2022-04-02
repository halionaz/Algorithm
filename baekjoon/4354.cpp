// 문자열 제곱
// kmp

#include <iostream>
#include <string>
#include <vector>

std::vector<int> findPi(std::string s){
    int m = s.length();
    std::vector<int> pi(m,0);
    int i = 1, j = 0;
    while(i+j<m){
        if(s[j] == s[i+j]){
            j++;
            pi[i+j-1] = j;
        } else {
            if(j==0){
                i++;
            } else {
                i += j - pi[i-1];
                j = pi[j-1];
            }
        }
    }
    return pi;
}
int main(){
    std::string S;
    while(1){
        std::cin >> S;
        if(S == "."){
            break;
        }
        std::vector <int> pi = findPi(S);
        int len = S.length();
        if(len%(len-pi[len-1])){
            std::cout << 1 << '\n';
        } else {
            std::cout<< len/(len-pi[len-1]) << '\n';
        }
    }
    return 0;
}