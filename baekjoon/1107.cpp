// 리모컨
// 브루트포스 알고리즘

#include <iostream>
#include <string>
int N,M;
int ans = 5000000;
int btn[10] = {1,1,1,1,1,1,1,1,1,1};
int min(int a,int b){
    return a < b ? a : b;
}
void solve(std::string num){
    for(int i = 0; i<10; i++){
        if(btn[i]){
            std::string tmp = num + std::to_string(i);
            ans = min(ans,abs(N-std::stoi(tmp))+tmp.length());
            if(tmp.length() < 6){
                solve(tmp);
            }
        }
    }
}
int main(){
    int k;
    std::cin >> N >> M;
    ans = min(ans,abs(100-N));
    for(int i = 0; i < M; i++){
        std::cin >> k;
        btn[k] = 0;
    }
    solve("");
    std::cout << ans << '\n';
    return 0;
}