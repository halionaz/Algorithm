// 롤러코스터
// 그리디 알고리즘

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
        int minVal = 1005;
        int minCoo[2];
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if((i+j)%2 && arr[i][j] < minVal){
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