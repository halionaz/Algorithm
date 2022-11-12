// 안녕 클레오파트라 세상에서 제일가는 포테이토칩
// 구현

#include <iostream>

int N, X;
int limit[101];

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N >> X;

    for(int i = 1; i <= N; i++){
        std::cin >> limit[i];
    }

    int curPerson = 1;
    int curVoice = X;

    while(true){

        if(limit[curPerson] < curVoice){
            std::cout << curPerson;
            return 0;
        } else {
            curPerson++;
            curVoice++;
            if(curPerson > N){
                curPerson = 1;
            }
        }
    }
}