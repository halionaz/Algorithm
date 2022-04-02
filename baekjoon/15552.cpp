// 빠른 A+B
// 사칙연산

#include <iostream>
using std::cin;
using std::cout;
int main(){
    int T;
    int a,b;
    cin.tie(NULL);
    cin >> T;
    for(int i = 0; i<T; i++){
        cin >> a >> b;
        cout << a+b << '\n';
    }
}