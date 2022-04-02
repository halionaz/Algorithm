// 007
// 다이나믹 프로그래밍 & 비트마스킹 & 비트필드를 이용한 다이나믹 프로그래밍

#include <iostream>

int N;
int percent[20][20];
double dp[1<<20] = {1,};

int bitCount(int x){
    int retrn = 0;
    while(x){
        retrn += x&1;
        x = x>>1;
    }
    return retrn;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.precision(6);
    std::cout<<std::fixed;

    std::cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            std::cin >> percent[i][j];
        }
    }

    for(int i = 0; i < (1<<N); i++){
        int k = bitCount(i);
        for(int j = 0; j < N; j++){
            if(!(i&(1<<j))){
                dp[i|(1<<j)] = dp[i] * ((double)percent[j][k])/100.0 > dp[i|(1<<j)] ? dp[i] * ((double)percent[j][k])/100.0 : dp[i|(1<<j)];
            }
        }
    }

    std::cout << dp[(1<<N)-1]*100.0 << '\n';

    return 0;
}