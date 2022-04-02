// Boggle
// 트라이 & 백트래킹

#include <iostream>
#include <string>
#include <map>
#include <cstring>

const int dx[8] = {1,1,1,-1,-1,-1,0,0};
const int dy[8] = {1,0,-1,1,0,-1,1,-1};

bool visited[4][4];
std::map<std::string, bool> wordVisited;

char board[4][4];

int W,B;

int point;
int maxLen;
std::string maxLenWord;
int wordCnt;

struct Node{
    bool finish;
    std::map<char, Node> child;
    Node(){
        finish = false;
    }
};

void insert(Node &cur, std::string str, int ind){
    if(str.length() == ind){
        cur.finish = true;
        return;
    } else {
        if(!cur.child.count(str[ind])){
            cur.child[str[ind]] = Node();
        }
        insert(cur.child[str[ind]],str,ind+1);
    }
}

void dfs(int x, int y, Node &cur, std::string str){
    if(cur.finish){
        if(!wordVisited[str]){
            wordVisited[str] = true;
            wordCnt++;
            int l = str.length();
            if(l > maxLen){
                maxLen = l;
                maxLenWord = str;
                // std::cout << str << '\n';
            } else if (l == maxLen){
                if(str < maxLenWord){
                    maxLenWord = str;
                }
            }
            if(l == 3 || l == 4){
                point += 1;
            } else if(l==5){
                point += 2;
            } else if(l==6){
                point += 3;
            } else if(l==7){
                point += 5;
            } else if(l==8){
                point += 11;
            }
        }
    }
    for(int i = 0; i < 8; i++){
        int newX = x + dx[i];
        int newY = y + dy[i];
        if(newX > -1 && newX < 4 && newY > -1 && newY < 4){
            if(!visited[newX][newY] && cur.child.count(board[newX][newY])){
                visited[newX][newY] = true;
                dfs(newX,newY,cur.child[board[newX][newY]],str+board[newX][newY]);
                visited[newX][newY] = false;
            }
        }
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> W;

    Node root;

    for(int i = 0; i < W; i++){
        std::string inp;
        std::cin >> inp;
        insert(root,inp,0);
    }

    std::cin >> B;

    while(B--){
        point = 0;
        maxLen = 0;
        wordCnt = 0;
        wordVisited.clear();
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                std::cin >> board[i][j];
            }
        }
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                memset(visited,false,sizeof(visited));
                if(root.child.count(board[i][j])){
                    std::string s;
                    visited[i][j] = true;
                    dfs(i,j,root.child[board[i][j]],s+board[i][j]);
                }
            }
        }
        std::cout << point << ' ' << maxLenWord << ' ' << wordCnt << '\n';
    }

    return 0;
}