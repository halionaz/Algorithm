// 구슬 탈출 2
// 너비 우선 탐색

// BFS 구현 자체는 쉬웠는데
// 공 두개를 굴려가면서 계속해서 좌표 비교를 하는 아이디어가 어려웠음

// 공 두개를 굴려야 하기에 move 함수를 따로 빼서 계산 하는 것이 더 용이
// 공 두개를 굴려야 하기에 search_case를 담는 struct를 BFS 하게 됨

// 개인적으론 queue를 활용한 BFS를 연습할 수 있어서 좋았음
// 또 struct를 사용하는 거의 최초의 문제인거 같음

#include <iostream>
#include <queue>

struct search_case
{
    // BFS 탐색 깊이
    // Red ball의 x, y 좌표
    // Blue ball의 x, y 좌표
    int depth, rx, ry, bx, by;
};

int N, M, ans = -1;
int hole[2];
char map[10][10];
bool visited[10][10][10][10];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void move(int &x, int&y, int dir){
    while(1){
        x += dx[dir];
        y += dy[dir];
        if(map[x][y] == '#'){
            x -= dx[dir];
            y -= dy[dir];
            break;
        } else if (map[x][y] == 'O'){
            break;
        }
    }
}

int main()
{

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> M;

    int startRx, startRy, startBx, startBy;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cin >> map[i][j];
            if (map[i][j] == 'O')
            {
                hole[0] = i, hole[1] = j;
            }
            else if (map[i][j] == 'R')
            {
                map[i][j] = '.';
                startRx = i, startRy = j;
            }
            else if (map[i][j] == 'B')
            {
                map[i][j] = '.';
                startBx = i, startBy = j;
            }
        }
    }

    std::queue<search_case> que;
    search_case start_case = {0, startRx, startRy, startBx, startBy};
    que.push(start_case);
    visited[startRx][startRy][startBx][startBy] = true;

    while (!que.empty())
    {
        search_case cur = que.front();
        que.pop();

        if (cur.depth > 10)
        {
            break;
        }
        if (cur.rx == hole[0] && cur.ry == hole[1])
        {
            ans = cur.depth;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            // 4방향으로 기울이는 것 구현
            int newRx = cur.rx;
            int newRy = cur.ry;
            int newBx = cur.bx;
            int newBy = cur.by;
            move(newRx, newRy, i);
            move(newBx, newBy, i);

            if(newBx == hole[0] && newBy == hole[1]){
                continue; // 파란 공이 빠졌으므로 pass
            }
            if(newRx == newBx && newRy == newBy){
                // 두 공이 겹치는 경우 처리
                // 원래 자리 기준으로 더 멀리 있던 공을 한칸 옮김
                switch(i){
                    case 0 :
                        cur.rx < cur.bx ? newRx-- : newBx--;
                        break;
                    case 1 :
                        cur.ry < cur.by ? newRy-- : newBy--;
                        break;
                    case 2 :
                        cur.rx < cur.bx ? newBx++ : newRx++;
                        break;
                    case 3 :
                        cur.ry < cur.by ? newBy++ : newRy++;
                        break;
                }
            }

            if(!visited[newRx][newRy][newBx][newBy]){
                search_case next = {cur.depth+1, newRx, newRy, newBx, newBy};
                que.push(next);
                visited[newRx][newRy][newBx][newBy] = true;
            }
        }
    }

    std::cout << ans << '\n';

    return 0;
}