// 007
// 다이나믹 프로그래밍 & 비트마스킹 & 비트필드를 이용한 다이나믹 프로그래밍
// bottom-up

#include <iostream>
#include <algorithm>

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
        
        // 지금까지 0 ~ k-1까지 임무가 수행됨, 즉 k번째 임무 수행할 차례
        int k = bitCount(i); 

        for(int j = 0; j < N; j++){
            if(!(i&(1<<j))){
                // 아직 미션을 수행하지 않은 지미 본드에게 일 할당
                dp[i|(1<<j)] = std::max(dp[i] * ((double)percent[j][k])/100.0 , dp[i|(1<<j)]);
            }
        }
    }

    std::cout << dp[(1<<N)-1]*100.0 << '\n';

    return 0;
}