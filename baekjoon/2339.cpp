// 석판 자르기
// 분할 정복

#include <iostream>

int N;
int board[21][21];

int cut(int start[2], int end[2], bool dir){

    // 아직 정답이 유효한지 판정
    int impurities = 0;
    int gem = 0;
    for(int i = start[0]; i <= end[0]; i++){
        for(int j = start[1]; j <= end[1]; j++){
            if(board[i][j] == 1){
                impurities++;
            } else if(board[i][j] == 2){
                gem++;
            }
        }
    }
    if(gem == 0){
        // 보석이 없으면 경우의 수 없음
        return 0;
    }
    if(gem == 1){
        if(impurities == 0){
            // 보석이 하나 남았는데, 불순물이 더 이상 없다면 경우의 수 1
            return 1;
        } else {
            // 보석은 하나 남았는데, 불순물이 존재한다면 경우의 수 0
            return 0;
        }
    } else if(impurities == 0){
        // 보석은 여러개 남았는데, 불순물이 더 이상 없다면 경우의 수 0
        return 0;
    }

    int cnt = 0;

    if(dir){
        // 가로 방향으로 자르기
        for(int i = start[0] + 1; i < end[0]; i++){
            bool possible = false; // 자를 수 있는지 여부

            // 절단면 따라 여부 검사
            for(int j = start[1]; j <= end[1]; j++){
                if(board[i][j] == 2){
                    // 보석이 들어있으므로 못자름!
                    possible = false;
                    break;
                }
                if(board[i][j] == 1){
                    // 불순물이 끼어있는 면이므로 자를 수 있는 여지가 있음
                    possible = true;
                }
            }

            if(!possible){
                // 자를 수 없으면 pass
                continue;
            }

            // 잘린 기준점
            int f[2] = {i-1, end[1]};
            int s[2] = {i+1, start[1]};
            
            // 기준면으로 자르면 두조각 나옴
            int first = cut(start, f, !dir);
            if(first == 0){
                // 답 없으므로 pass
                continue;
            }
            int second = cut(s, end, !dir);
            if(second == 0){
                continue;
            }

            cnt += first * second; // 경우의 수 합산

        }
    } else {
        // 세로 방향으로 자르기
        for(int i = start[1] + 1; i < end[1]; i++){
            bool possible = false; // 자를 수 있는지 여부

            // 절단면 따라 여부 검사
            for(int j = start[0]; j <= end[0]; j++){
                if(board[j][i] == 2){
                    // 보석이 들어있으므로 못자름!
                    possible = false;
                    break;
                }
                if(board[j][i] == 1){
                    // 불순물이 끼어있는 면이므로 자를 수 있는 여지가 있음
                    possible = true;
                }
            }

            if(!possible){
                // 자를 수 없으면 pass
                continue;
            }

            // 잘린 기준점
            int f[2] = {end[0], i-1};
            int s[2] = {start[0], i+1};
            
            // 기준면으로 자르면 두조각 나옴
            int first = cut(start, f, !dir);
            if(first == 0){
                // 답 없으므로 pass
                continue;
            }
            int second = cut(s, end, !dir);
            if(second == 0){
                continue;
            }

            cnt += first * second; // 경우의 수 합산

        }
    }

    return cnt;
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

    int s[2] = {0,0};
    int e[2] = {N-1, N-1};

    int ans = cut(s, e, false) + cut(s, e, true);

    std::cout << (ans == 0 ? -1 : ans) << '\n';

    return 0;
}