// 노브 돌리기

#include <iostream>
#include <algorithm>
#include <stdlib.h>

int N, A;
long long ans = 0;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    std::cin >> A;

    for(int i = 0; i < N; i++){

        int An;

        std::cin >> An;

        if(An > A){
            ans += std::min(An-A, A + 360 - An);
        } else {
            ans += std::min(A - An, 360-A + An);
        }


        A = An;
        
    }

    std::cout << ans << '\n';

    return 0;
}