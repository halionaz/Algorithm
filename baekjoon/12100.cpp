// 2048 (Easy)
// 백트래킹 & 시뮬레이션

// 블록 무빙을 구현하기가 조금 힘들었던 백트래킹 문제
// 아이디어 자체는 떠올리기 쉬운 편

#include <iostream>
#include <algorithm>
#include <queue>

const int int_max = 20;

int N, ans;
int board[int_max][int_max];

void move(int type){
    // 블록 무빙
    std::queue<int> que;

    if(type == 0){
        // 왼쪽으로 밀기
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(board[i][j]){
                    que.push(board[i][j]);
                    board[i][j] = 0;
                }
            }
            int ind = 0;
            while(!que.empty()){
                if(board[i][ind] == 0){
                    board[i][ind] = que.front();
                } else if(board[i][ind] == que.front()){
                    board[i][ind] *= 2;
                    ind++;
                } else {
                    // 다른 블럭인 경우
                    ind++;
                    board[i][ind] = que.front();
                }
                que.pop();
            }
        }
    }else if(type == 1){
        // 오른쪽으로 밀기
        for(int i = 0; i < N; i++){
            for(int j = N-1; j >= 0; j--){
                if(board[i][j]){
                    que.push(board[i][j]);
                    board[i][j] = 0;
                }
            }
            int ind = N-1;
            while(!que.empty()){
                if(board[i][ind] == 0){
                    board[i][ind] = que.front();
                } else if(board[i][ind] == que.front()){
                    board[i][ind] *= 2;
                    ind--;
                } else {
                    // 다른 블럭인 경우
                    ind--;
                    board[i][ind] = que.front();
                }
                que.pop();
            }
        }
    }else if(type == 2){
        // 아래쪽으로 밀기
        for(int j = 0; j < N; j++){
            for(int i = N-1; i >= 0; i--){
                if(board[i][j]){
                    que.push(board[i][j]);
                    board[i][j] = 0;
                }
            }
            int ind = N-1;
            while(!que.empty()){
                if(board[ind][j] == 0){
                    board[ind][j] = que.front();
                } else if(board[ind][j] == que.front()){
                    board[ind][j] *= 2;
                    ind--;
                } else {
                    // 다른 블럭인 경우
                    ind--;
                    board[ind][j] = que.front();
                }
                que.pop();
            }
        }
    }else if(type == 3){
        // 위쪽으로 밀기
        for(int j = 0; j < N; j++){
            for(int i = 0; i < N; i++){
                if(board[i][j]){
                    que.push(board[i][j]);
                    board[i][j] = 0;
                }
            }
            int ind = 0;
            while(!que.empty()){
                if(board[ind][j] == 0){
                    board[ind][j] = que.front();
                } else if(board[ind][j] == que.front()){
                    board[ind][j] *= 2;
                    ind++;
                } else {
                    // 다른 블럭인 경우
                    ind++;
                    board[ind][j] = que.front();
                }
                que.pop();
            }
        }
    }

}

void solve(int cnt){
    // 5번 이동 완료!
    if(cnt == 5){

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                ans = std::max(ans,board[i][j]);
            }
        }

        return;

    }

    int original[int_max][int_max];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            original[i][j] = board[i][j];
        }
    }

    for(int i = 0; i < 4; i++){
        // 4방향 무빙
        move(i);
        solve(cnt+1);
        // 복구
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                board[i][j] = original[i][j];
            }
        }
    }

}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            std::cin >> board[i][j];
        }
    }

    solve(0);

    std::cout << ans << '\n';

    return 0;
}