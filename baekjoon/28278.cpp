// 스택 2
// 자료 구조 & 스택

#include <iostream>
#include <vector>

int N, type;
std::vector<int> stack;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    while(N--){
        std::cin >> type;

        if(type == 1){

            int X;
            std::cin >> X;
            
            stack.push_back(X);

        } else if(type == 2){
            if(stack.size() > 0){
                std::cout << stack.back() << '\n';
                stack.pop_back();
            } else {
                // 스택이 비었음
                std::cout << "-1\n";
            }
        } else if(type == 3){
            std::cout << stack.size() << '\n';
        } else if(type == 4){
            if(stack.size() > 0){
                std::cout << "0\n";
            } else {
                // 스택이 비었음
                std::cout << "1\n";
            }
        } else if(type == 5){
            if(stack.size() > 0){
                std::cout << stack.back() << '\n';
            } else {
                // 스택이 비었음
                std::cout << "-1\n";
            }
        }
    }

}