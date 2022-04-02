// 숫자의 신
// 그리디 알고리즘 & 정렬

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int K,N;
std::vector<std::string> arr;

bool compare(std::string a, std::string b){
    if(a+b > b+a){
        return true;
    } else {
        return false;
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> K >> N;

    int surplus = N-K;

    std::string king = "";

    for(int i = 0; i < K; i++){
        std::string inp;
        std::cin >> inp;
        if((inp.length() > king.length()) || (king.length()==inp.length() && inp > king)){
            king = inp;
        }
        arr.push_back(inp);
    }

    // 가장 큰 수 (King)을 남은 횟수만큼 반복해 앞에 붙임
    for(int i = 0; i < surplus; i++){
        arr.push_back(king);
    }

    // 남은 수는 붙였을 때 큰 순서로 정렬
    // 이 조건을 만들기가 까다로웠음
    std::sort(arr.begin(),arr.end(),compare);

    for(int i = 0; i < N; i++){
        std::cout << arr[i];
    }

    std::cout << '\n';

    return 0;
}