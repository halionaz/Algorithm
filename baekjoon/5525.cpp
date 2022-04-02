// IOIOI
// 문자열

#include <iostream>
#include <string>

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int N, M;
    std::string S;

    std::cin >> N >> M >> S;

    int ans = 0;

    for(int i = 0; i < M; i++){
        // O를 0으로 두고 탐색 시작
        int Onum = 0;
        while(S[i] == 'I' and S[i+1] == 'O'){
            // IO
            i += 2;
            Onum++;
            if(S[i] == 'I' and Onum == N){
                // 2칸 넘어왔을 때, I로 끝나고
                // 지금까지 쌓인 O가 N과 동일할 경우
                ans += 1;
                Onum--;
            }
        }
    }

    std::cout << ans << '\n';

    return 0;
}