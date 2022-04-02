// 전화번호 목록
// 트라이

#include <iostream>
#include <string>
#include <map>

int T;

struct Node{
    bool finish;
    int childCnt;
    std::map<char, Node> child;
    Node(){
        childCnt = 0;
        finish = false;
    }
};

int insert(Node &cur, std::string str, int ind){
    if(ind == str.length()){
        if(cur.childCnt > 0){
            return 0;
        } else {
            cur.finish = true;
            return 1;
        }
    } else {
        if(!cur.child.count(str[ind])){
            cur.child[str[ind]] = Node();
            cur.childCnt+=1;
        } else {
            if(cur.child[str[ind]].finish){
                return 0;
            }
        }
        return insert(cur.child[str[ind]], str, ind+1);
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;

    while(T--){
        int n;
        Node root;
        std::cin >> n;
        bool ans = true;

        for(int i = 0; i < n; i++){
            std::string inp;
            std::cin >> inp;

            if(!insert(root,inp,0)){
                ans = false;
            }

        }

        std::cout << (ans?"YES":"NO") << '\n';

    }

    return 0;
}