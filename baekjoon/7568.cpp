// 덩치
// 브루트포스 알고리즘

#include <iostream>

int main(){
    int N;
    int size[50][2];
    std::cin >> N;
    for(int i = 0; i < N; i++){
        std::cin >> size[i][0] >> size[i][1];
    }
    for(int i = 0; i < N; i++){
        int cnt = 1;
        for(int j = 0; j < N; j++){
            if(size[j][0] > size[i][0] && size[j][1] > size[i][1]){
                cnt++;
            }
        }
        std::cout << cnt << ' ';
    }
    std::cout << '\n';
    return 0;
}