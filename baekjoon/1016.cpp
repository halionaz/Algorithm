// 제곱 ㄴㄴ 수
// 소수 판정 & 에라토스테네스의 체

#include <iostream>
long long min,max;
bool isJegopNoNo[10000000];
int main(){
    std::cin >> min >> max;
    for(long long i = 0; i < 10000000; i++){
        isJegopNoNo[i] = true;
    }
    long long ans = max-min+1;
    for(long long i = 2; i*i <= max; i++){
        long long mult = min/(i*i);
        if(min%(i*i)){
            mult++;
        }
        while(mult*(i*i) <= max){
            // 현재 검사 중인 제곱수의 배수들도 검사
            if(isJegopNoNo[mult*(i*i)-min]){
                isJegopNoNo[mult*(i*i)-min] = false;
                ans--;
            }
            mult++;
        }
    }
    std::cout << ans << '\n';;
    return 0;
}