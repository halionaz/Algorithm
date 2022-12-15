// 합
// 구현

#include <iostream>

using std::cin;
using std::cout;

int main(){

    int n;
    int ans = 0;

    cin >> n;

    for(int i = 1; i<=n; i++){
        ans += i;
    }

    cout << ans << std::endl;
    
    return 0;
}