// 도키도키 간식드리미
// 스택

#include <iostream>
#include <vector>

int N, inp, order = 1;
std::vector<int> stck;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 0; i < N; i++){
        std::cin >> inp;
        // 우선 공간에 있는 사람을 체크해봄
        while(!stck.empty()){
            if(stck.back() == order){
                // 맞으니 간식 배부
                order++;
                stck.pop_back();
            } else {
                break;
            }
        }

        if(inp == order){
            // 간식을 받음
            order++;
        } else {
            // 차례가 아니고 스택에도 후보자가 없으니 일단 옆 공간으로 이동
            stck.push_back(inp);
        }
    }

    while(!stck.empty()){
        if(stck.back() == order){
            stck.pop_back();
            order++;
        } else {
            std::cout << "Sad\n";
            return 0;
        }
    }

    std::cout << "Nice\n";

    return 0;
}