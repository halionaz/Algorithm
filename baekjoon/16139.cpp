// 인간-컴퓨터 상호작용
// 누적 합

#include <iostream>
#include <string>

// pSum[x][j] :: x문자가 문자열의 0~j 사이에 몇번 등장하는지 저장
int pSum[26][200001];
int q;
std::string S;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> S;

    for(int i = 0; i < S.length(); i++){
        if(i != 0){
            // i가 처음이 아닐 때,
            for(int j = 0; j < 26; j++){
                pSum[j][i] = pSum[j][i-1];
            }
        }

        // 현재 해당되는 문자 추가
        pSum[S[i]-'a'][i]++;
    }

    std::cin >> q;

    for(int i = 0; i < q; i++){
        char a;
        int l, r;
        std::cin >> a >> l >> r;
        // l~r까지 a가 등장하는 빈도는
        // pSum[a][r] - pSum[a][l-1] 임
        // 그러나 l이 0일 수도 있고, 이런 경우엔 pSum[a][r]이므로, 예외처리
        std::cout << pSum[a-'a'][r] - (l ? pSum[a-'a'][l-1] : 0) << '\n';
    }

    return 0;
}