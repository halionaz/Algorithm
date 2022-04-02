// 에디터
// 스택

#include <iostream>
#include <stack>
#include <string>

int M;
std::string str;
std::stack<char> left;
std::stack<char> right;

void leftPrint(){
    char val = left.top();
    left.pop();
    if(!left.empty()){
        leftPrint();
    }
    std::cout << val;
    return;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> str;

    for(int i = 0; i < str.length(); i++){
        left.push(str[i]);
    }

    std::cin >> M;

    while(M--){
        char commend;
        std::cin >> commend;
        switch(commend){
            case 'L' :
                if(!left.empty()){
                    right.push(left.top());
                    left.pop();
                }
                break;
            case 'D' :
                if(!right.empty()){
                    left.push(right.top());
                    right.pop();
                }
                break;
            case 'B' :
                if(!left.empty()){
                    left.pop();
                }
                break;
            case 'P' :
                char inp;
                std::cin >> inp;
                left.push(inp);
                break;
        }
    }
    if(!left.empty()){
        leftPrint();
    }
    while(!right.empty()){
        std::cout << right.top();
        right.pop();
    }
    std::cout << '\n';

    return 0;
}