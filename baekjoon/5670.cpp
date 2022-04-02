// 휴대폰 자판 
// 트라이

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>

int sum , N;
bool initial;
std::string dict[100001];

struct Node{
    bool finish;
    int childCnt;
    std::map<char, Node> child;
    Node(){
        finish = false;
        childCnt = 0;
    }
};

void insert(Node &cur, std::string str,int len, int ind){
    if(ind == len){
        cur.finish = true;
        return;
    } else {
        if(!cur.child.count(str[ind])){
            cur.childCnt += 1;
            cur.child[str[ind]] = Node();
        }
        insert(cur.child[str[ind]], str, len, ind+1);
    }
}

void dfs(Node &cur, std::string str,int len, int ind){
    if(ind == len){
        return;
    } else {
        if(initial){
            initial = false;
            sum++;
        } else if(cur.childCnt > 1 || cur.finish){
            sum++;
        }
        dfs(cur.child[str[ind]],str, len ,ind+1);
    }
}

int main(){

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    while(std::cin >> N){

        sum = 0;

        Node root;

        for(int i = 0; i < N; ++i){
            std::cin >> dict[i];
            insert(root, dict[i],dict[i].length(), 0);
        }

        for(int i = 0; i < N; ++i){
            initial = true;
            dfs(root,dict[i],dict[i].length(),0);
        }


        std::cout << std::fixed << std::setprecision(2) << (double)sum / (double)N << '\n';
    }


    return 0;
}