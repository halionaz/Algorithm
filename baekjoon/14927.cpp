// 전구 끄기
// 비트마스킹 & 그리디 알고리즘

#include <iostream>
#include <bitset>

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

const int ansMax = 1000;

int N;
int answer = ansMax;
bool dp[18][18];
bool original[18][18];

void toggle(int x, int y){
    dp[x][y] = !dp[x][y];
    for(int d = 0; d < 4; d++){
        int newX = x + dx[d];
        int newY = y + dy[d];
        if(0 <= newX && newX < N && 0 <= newY && newY < N){
            dp[newX][newY] = !dp[newX][newY];
        }
    }
}

int main()
{

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> original[i][j];
        }
    }

    for (int firstRow = 0; firstRow < (1 << N); firstRow++)
    {

        int cnt = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                dp[i][j] = original[i][j];
            }
        }

        for(int i = 0; i < N; i++){
            if(firstRow & (1<<i)){
                cnt++;
                toggle(0,i);
            }
        }


        for(int i = 1; i < N; i++){
            for(int j = 0; j < N; j++){
                if(dp[i-1][j]){
                    cnt++;
                    toggle(i,j);
                }
            }
        }


        bool isDone = true;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(dp[i][j]){
                    isDone = false;
                    break;
                }
            }
            if(!isDone){
                break;
            }
        }


        if(isDone){
            if(cnt < answer){
                answer = cnt;
            }
        }

    }

    if(answer == ansMax){
        std::cout << -1 << '\n';
    } else {
        std:: cout << answer << '\n';
    }

    return 0;
}