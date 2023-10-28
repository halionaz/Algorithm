// 덱 2
// 자료 구조 & 덱

#include <iostream>
#include <deque>

int N, X;
std::deque<int> dq;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    while(N--){
        int command;
        std::cin >> command;
        
        switch(command){
            case 1 :
                std::cin >> X;
                dq.push_front(X);
                break;
            case 2 :
                std::cin >> X;
                dq.push_back(X);
                break;
            case 3 :
                if(dq.size() > 0){
                    std::cout << dq.front() << '\n';
                    dq.pop_front();
                } else {
                    std::cout << "-1\n";
                }
                break;
            case 4 :
                if(dq.size() > 0){
                    std::cout << dq.back() << '\n';
                    dq.pop_back();
                } else {
                    std::cout << "-1\n";
                }
                break;
            case 5 :
                std::cout << dq.size() << '\n';
                break;
            case 6 :
                std::cout << dq.empty() << '\n';
                break;
            case 7 :
                if(dq.size() > 0){
                    std::cout << dq.front() << '\n';
                } else {
                    std::cout << "-1\n";
                }
                break;
            case 8 :
                if(dq.size() > 0){
                    std::cout << dq.back() << '\n';
                } else {
                    std::cout << "-1\n";
                }
                break;
        }
    }

    return 0;
}