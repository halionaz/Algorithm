// 개미굴 
// 트라이

#include <iostream>
#include <string>
#include <map>
#include <vector>

int N;

struct Node{

    std::map<std::string, Node> child;
    
};

void insert(Node &cur, std::vector<std::string> s , int ind ){
    if(ind == s.size()){
        return;
    } else {
        if(!cur.child.count(s[ind])){
            cur.child[s[ind]] = Node();
        }
        insert(cur.child[s[ind]], s, ind+1);
    }
}

void dfs(Node &cur, int d){
    for(std::pair<std::string,Node> item : cur.child){
        for(int i = 0; i < d; i++){
            std::cout << "--";
        }
        std::cout << item.first << '\n';
        dfs(item.second, d+1);
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    Node r;

    for(int i = 0; i < N; i++){
        int x;
        std::cin >> x;
        std::vector<std::string> food;
        for(int j = 0; j < x; j++){
            std::string f;
            std::cin >> f;
            food.push_back(f);
        }
        insert(r,food,0);
    }

    dfs(r,0);

    return 0;
}