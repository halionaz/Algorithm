// Z
// 분할 정복 & 재귀

#include <iostream>

int N,r,c,ans;

void solve(int n,int sX, int sY){
    if(sX == r && sY == c){
        std::cout << ans << '\n';
        return;
    } 
    if(sX+n > r && sX <= r && sY+n > c && sY <= c){
        solve(n/2,sX,sY);
        solve(n/2,sX,sY+n/2);
        solve(n/2,sX+n/2,sY);
        solve(n/2,sX+n/2,sY+n/2);
    } else {
        ans += n*n;
    }
}
int main(){
    std::cin>>N>>r>>c;
    ans = 0;
    solve((1<<N),0,0);
    return 0;
}