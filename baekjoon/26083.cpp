// 유통기한
// 구현 & 많은 조건 분기

#include <iostream>

int Y, M, D, N, A, B, C;
const int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> Y >> M >> D;

    std::cin >> N;

    while(N--){

        bool validDate = false;

        bool allInvalid = true;
        bool allSafe = true;

        std::cin >> A >> B >> C;

        // Y / M / D
        if(1 <= B && B <= 12){
            // 월은 유효함
            if(B == 2){
                // 2월
                if(A % 4 == 0){
                    // 윤년
                    if(C >= 1 && C <= 29){
                        validDate = true;
                    }
                } else {
                    // 윤년이 아닌 다른 달 
                    if(C >= 1 && C <= 28) {
                        validDate = true;
                    }
                }
            } else {
                // 2월이 아닌 다른 달
                if(C >= 1 && C <= days[B]){
                    validDate = true;
                }
            }
        }
        // 유효한 날짜일 때,
        if(validDate){
            allInvalid = false;
            if(!(A > Y || (A == Y && B > M) || (A == Y && B == M && C >= D))){
                // 이 식품은 위험
                // 모든 유효기간이 안전한건 아님
                allSafe = false;
            }
        }

        // D / M / Y
        validDate = false;
        if(1 <= B && B <= 12){
            // 월은 유효
            if(B == 2){
                // 2월
                if(C % 4 == 0 && A >= 1 && A <= 29){
                    // 윤년
                    validDate = true;
                } else if(A >= 1 && A <= 28) {
                    validDate = true;
                }
            } else {
                // 2월이 아닌 다른 날
                if(A >= 1 && A <= days[B]){
                    validDate = true;
                }
            }
        }
        if(validDate){
            allInvalid = false;
            if(!(C > Y || (C == Y && B > M) || (C == Y && B == M && A >= D))){
                allSafe = false;
            }
        }

        // M / D / Y
        validDate = false;
        if(1 <= A && A <= 12){
            if(A == 2){
                // 2월
                if(C % 4 == 0 && B >= 1 && B <= 29){
                    // 윤년
                    validDate = true;
                } else if(B >= 1 && B <= 28) {
                    validDate = true;
                }
            } else {
                if(B >= 1 && B <= days[A]){
                    validDate = true;
                }
            }
        }
        if(validDate){
            allInvalid = false;
            if(!(C > Y || (C == Y && A > M) || (C == Y && A == M && B >= D))){
                allSafe = false;
            }
        }

        
        if(allInvalid){
            std::cout << "invalid";
        } else if (allSafe){
            std::cout << "safe";
        } else {
            std::cout << "unsafe";
        }

        std::cout << '\n';

    }

    return 0;
}