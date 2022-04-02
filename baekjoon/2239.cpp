// 스도쿠
// 백트래킹

#include <iostream>
#include <vector>
#include <cstring>

int sudoku[9][9];
std::vector<std::pair<int, int> > zero;

void solve(int ind){
    if(ind == zero.size()){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                std::cout << sudoku[i][j];
            }
            std::cout << '\n';
        }
        exit(0);
    } else {

        int x = zero[ind].first;
        int y = zero[ind].second;
        int dx = (x/3)*3;
        int dy = (y/3)*3;

        bool numList[10];
        memset(numList, true, sizeof(numList));

        // 가로 세로 체크
        for(int i = 0; i< 9; i++){
            if(sudoku[i][y] != 0){
                numList[sudoku[i][y]] = false;
            }
            if(sudoku[x][i] != 0){
                numList[sudoku[x][i]] = false;
            }
        }
        // 3*3 정사각형 체크
        for(int i = dx; i < dx+3; i++){
            for(int j = dy; j < dy+3; j++){
                if(sudoku[i][j] != 0){
                    numList[sudoku[i][j]] = false;
                }
            }
        }

        for(int i = 1; i <= 9; i++){
            if(numList[i]){
                sudoku[x][y] = i;
                solve(ind+1);
                sudoku[x][y] = 0;
            }
        }

    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            char c;
            std::cin >> c;
            sudoku[i][j] = c - '0';
            if(!sudoku[i][j]){
                zero.push_back(std::make_pair(i,j));
            }
        }
    }

    solve(0);

    return 0;
}