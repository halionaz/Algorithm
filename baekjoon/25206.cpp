// 너의 평점은
// 구현 & 문자열

#include <iostream>
#include <string>

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    double total = 0;
    double totalGPA = 0;

    std::string S;
    double gpa;
    std::string grade;

    for(int i = 0; i < 20; i++){
        std::cin >> S;
        std::cin >> gpa;
        std::cin >> grade;

        if(grade == "P"){
            continue;
        }
        
        totalGPA += gpa;

        if(grade == "A+"){
            total += gpa * 4.5;
        } else if (grade == "A0"){
            total += gpa * 4.0;
        } else if (grade == "B+"){
            total += gpa * 3.5;
        } else if (grade == "B0"){
            total += gpa * 3.0;
        } else if (grade == "C+"){
            total += gpa * 2.5;
        } else if (grade == "C0"){
            total += gpa * 2.0;
        } else if (grade == "D+"){
            total += gpa * 1.5;
        } else if (grade == "D0"){
            total += gpa * 1.0;
        }
    }

    std::cout << total / totalGPA << '\n';

    return 0;
}