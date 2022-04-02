// 시철이가 사랑한 GCD
// 분할 정복 & 유클리드 호제법

#include <iostream>
#include <vector>

int N;
int ans = 0;
std::vector<int> arr;

int gcd(int a, int b){
    int tmp;
    if(a < b){
        tmp = a;
        a = b;
        b = tmp;
    }
    while(b){
        tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}

int solve(int s, int e){
    if(s == e){
        return arr[s];
    } else {

        int mid = e-s+1;
        mid = mid/2;

        int g = arr[s];
        for(int i = s+1; i <= s+mid-1; i++){
            g = gcd(arr[i],g);
        }
        int first = g + solve(s+mid,e);

        g = arr[e];
        for(int i = e-1; i >= s+mid; i--){
            g = gcd(arr[i],g);
        }
        int second = g + solve(s,s+mid-1);

        return first > second ? first : second;
    }
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    for(int i = 0; i < N; i++){
        int val;
        std::cin >> val;
        arr.push_back(val);
    }


    std::cout << solve(0,N-1) << '\n';

    return 0;
}