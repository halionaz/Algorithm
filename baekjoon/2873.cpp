// 롤러코스터
// 그리디 알고리즘 & 해 구성하기

#include <iostream>
#include <string>

int R, C;
int arr[1000][1000];
std::string ans;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> R >> C;

    for(int i = 0; i < R; i++){
        for(int j = 0; j< C; j++){
            std::cin >> arr[i][j];
        }
    }

    if(R % 2 == 0 && C % 2 == 0){

        // 좌표가 짝수인 경우,
        // 모든 칸을 지나가는 것은 불가능

        // 다만 하나의 칸만 제외하고 (단 그 칸은 i+j가 홀수인 경우에서만 발생)
        // 모든 칸을 지나갈 수는 있으므로
        // 최솟값을 가지는 타일만 제외하면 됨

        int minVal = 1005;
        int minCoo[2]; // 최솟값을 가지는 좌표 저장

        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if((i+j) % 2 && arr[i][j] < minVal){
                    minVal = arr[i][j];
                    minCoo[0] = i; minCoo[1] = j;
                }
            }
        }

        // minCoo만 안지나가면 됨

        for(int i = 0; i < (minCoo[0]%2 ? minCoo[0] - 1 : minCoo[0]); i++){
            for(int j = 0; j < C - 1; j++){
                if(i%2){
                    ans += 'L';
                } else {
                    ans += 'R';
                }
            }
            ans += 'D';
        }

        for(int i = 0; i < minCoo[1]; i++){
            if(i % 2){
                ans += "UR";
            } else {
                ans += "DR";
            }
        }
        for(int i = minCoo[1]; i < C - 1; i++){
            if(i % 2){
                ans += "RU";
            } else {
                ans += "RD";
            }
        }

        for(int i = 0; i < R - (minCoo[0] % 2 ? minCoo[0] + 1 : minCoo[0] + 2); i++){
            ans += 'D';
            for(int j = 0; j < C-1; j++){
                if(i % 2){
                    ans += 'R';
                } else {
                    ans += 'L';
                }
            }
        }

    } else {

        // 무조건 모든 칸을 지나가는 것이
        // 가장 큰 기쁨을 가짐

        if(R % 2){
            for(int i = 0; i < R; i++){
                for(int j = 0; j < C - 1; j++){
                    if(i%2){
                        ans += 'L';
                    } else {
                        ans += 'R';
                    }
                }
                if(i != R - 1){
                    ans += 'D';
                }
            }
        } else {
            for(int i = 0; i < C; i++){
                for(int j = 0; j < R - 1; j++){
                    if(i%2){
                        ans += 'U';
                    } else {
                        ans += 'D';
                    }
                }
                if(i != C - 1){
                    ans += 'R';
                }
            }
        }
    }

    std::cout << ans << '\n';

    return 0;
}