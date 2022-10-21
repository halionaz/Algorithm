// 검열
// 덱

// 스택을 써도 크게 문제는 없으나
// 덱을 사용하는 이유는
// C++에서 스택은 인덱스로 접근이 불가능하기 때문에
// 쌓인 단어를 확인하는 절차 구현이 까다로움

#include <iostream>
#include <deque>
#include <string>

std::string A, T, answer;
std::deque<char> front, back;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> A;
    std::cin >> T;

    int l = 0;
    int r = T.length() - 1;

    while(l <= r){
        // 앞과 뒤가 역전되지 않는 한 1, 2, 3, 4 계속 반복 수행
        while(l <= r){
            // 먼저 앞에서 단어를 찾아봄
            front.push_back(T[l++]);
            
            if(front.size() >= A.length()){
                // 지금까지 지나온 글자수가 패턴보다 길다면 탐색 진행
                bool isCorrect = true;
                for(int i = 0; i < A.length(); i++){
                    if(A[i] != front[front.size() - A.length() + i]){
                        // 단어가 안맞음
                        isCorrect = false;
                        break;
                    }
                }

                if(isCorrect){
                    // 일치하는 단어가 존재하므로 front 덱에서 빼냄
                    for(int i = 0; i < A.length(); i++){
                        front.pop_back();
                    }

                    // 뒤에서 단어를 찾는 턴으로 넘김
                    break;
                }
            }
        }

        while(l <= r){
            // 뒤에서 단어를 찾아봄
            back.push_front(T[r--]);

            if(back.size() >= A.length()){
                // 지금까지 지나온 글자수가 패턴보다 길다면 탐색 진행
                bool isCorrect = true;
                for(int i = 0; i < A.length(); i++){
                    if(A[i] != back[i]){
                        // 단어가 안맞음
                        isCorrect = false;
                        break;
                    }
                }

                if(isCorrect){
                    // 일치하는 단어가 존재하므로 back 덱에서 빼냄
                    for(int i = 0; i < A.length(); i++){
                        back.pop_front();
                    }

                    // 앞에서 단어를 찾는 턴으로 넘김
                    break;
                }
            }
        }
    }

    // std::cout << front.size() << '\n';
    // std::cout << back.size() << '\n';
    // 덱을 이용해 탐색하는 절차 종료
    // 이제 남은 두 덱을 합쳐주기

    for(int i = 0; i < front.size(); i++){
        answer += front[i];
    }
    for(int i = 0; i < back.size(); i++){
        answer += back[i];
    }

    // 합쳐졌을 때 나올 수 있는 패턴 문자열 검열

    while(answer.find(A) < std::string::npos){ // find함수는 단어를 찾지 못하면 npos 반환
        answer.erase(answer.find(A), A.length());
    }

    std::cout << answer << '\n';

    return 0;
}