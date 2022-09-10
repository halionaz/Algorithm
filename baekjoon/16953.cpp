// A → B
// 깊이 우선 탐색 & 그리디 알고리즘

// 시간, 메모리 조건이 까다롭지 않아
// 단순한 dfs 탐색으로도 문제가 풀림

// #include <iostream>
// #include <algorithm>

// typedef long long ll;

// ll A, B;
// int ans = 99999999;

// void dfs(ll a, int cnt){
//     if(a > B){
//         return;
//     }

//     if(a == B){
//         ans = std::min(ans, cnt);
//         return;
//     }

//     dfs(a*2, cnt+1);
//     dfs(a*10 + 1, cnt+1);
// }

// int main(){

//     std::ios_base::sync_with_stdio(0);
//     std::cin.tie(0);

//     std::cin >> A >> B;

//     dfs(A, 1);

//     std::cout << (ans == 99999999 ? -1 : ans) << '\n';

//     return 0;
// }

// 또는 그리디하게 B, 즉 답에서부터 돌아가는 식의 풀이

#include <iostream>

int main(){
    
    long A, B; 
    
    std::cin>>A>>B;

    long answer=1;

    while(B>=A){

        if(B==A) {

            std::cout << answer << '\n';
            return 0;
        }

        answer++;

        if(B%2==0){
            B/=2;
        }else if(B % 10 == 1){
            B-=1;
            B/=10;
        }else{
            break;
        }
    }

    // 불가능
    std::cout << -1 << "\n";
    
    return 0;
}