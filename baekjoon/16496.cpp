// 큰 수 만들기
// 그리디 알고리즘 & 정렬

// 그리디하게 문자열 기준으로 정렬하는 문제
// C++ STL의 sort()를 사용하면 쉽게 문제 해결

#include <iostream>
#include <string>
#include <algorithm>

std::string arr[1000];
int N;

bool compare(std::string A, std::string B){
    if(A == B){
        // 바꿔줄 필요 X
        return false;
    }

    if(A + B > B + A){
        return true;
    } else {
        return false;
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    bool isAll0 = true;

    for(int i = 0; i < N; i++){
        std::cin >> arr[i];
        if(arr[i] != "0"){
            isAll0 = false;
        }
    }

    if(isAll0){
        std::cout << 0 << '\n';
        return 0;
    }

    std::sort(arr, arr+N, compare);

    for(int i = 0; i < N; i++){
        std::cout << arr[i];
    }

    std::cout << '\n';

    return 0;
}