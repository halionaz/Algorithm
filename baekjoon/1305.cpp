// 광고
// kmp

// 실패 함수 이용하는 문제

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> getPartialMatch(const string N){
    int M = N.size();
    vector<int> pi(M, 0);
    int begin = 1, matched = 0;
    while (begin + matched < M){
        if (N[begin + matched] == N[matched]){
            matched++;
            pi[begin + matched - 1] = matched;
        }else{
            if (matched == 0)
                begin++;
            else{
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return pi;
}
int main(){
    int L;
    string s;
    cin >> L;
    cin >> s;
    vector<int> pi = getPartialMatch(s);
    // pi[i] :: s[0:i+1]에서 prefix와 suffix가 같을 길이
    cout << L-pi[L-1] << '\n';
    return 0;
}