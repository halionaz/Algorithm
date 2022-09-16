// 합성함수와 쿼리
// 희소 배열 

#include <iostream>

int m,Q;
const int log = 18;
int func[log+1][200001]; // func[i][n] :: f_(2^i)(n)

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> m;

    for(int i = 1; i <= m; i++){
        std::cin >> func[0][i];
    }

    // 미리 Sparse Table (희소 배열 테이블) 만들어 놓기
    for(int i = 1; i < log+1; i++){
        for(int j = 1; j < 200001; j++){
            func[i][j] = func[i-1][func[i-1][j]];
        }
    }

    std::cin >> Q;
    
    while(Q--){
        int n,x;
        std::cin >> n >> x;
        for(int i = log; i >= 0 && n > 0; i--){
            int cur = 1<<i;
            if(n >= cur){
                x = func[i][x];
                n -= cur;
            }
        }
        std::cout << x << '\n';
    }
    return 0;
}