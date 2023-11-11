// queuestack
// 자료 구조 & 스택 & 덱 & 큐

// 처음에는 각 자료구조의 type을 받고
// 또 각 자료구조에 담겨있는 int값을 관리하는 배열을 만들어
// 새로운 값이 들어올 때마다 시뮬레이션을 돌리는 식으로 구현했지만
// 시간 초과

// 어차피 stack이면 그 값은 절대 쓰이지 않으므로
// queue인 값만 저장하고, deque으로 값을 관리하는 식으로 구현해보자

#include <iostream>
#include <deque>

int N, M, inp;
bool typeArr[100001];
std::deque<int> qs;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 0; i < N; i++){
        std::cin >> typeArr[i];
    }
    for(int i = 0; i < N; i++){
        std::cin >> inp;
        if(typeArr[i] == 0){
            // 자료구조가 큐일때만 삽입
            qs.push_back(inp);
        }
    }

    std::cin >> M;

    while(M--){
        std::cin >> inp;
        qs.push_front(inp);
        std::cout << qs.back() << ' ';
        qs.pop_back();
    }
    std::cout << '\n';

    return 0;
}