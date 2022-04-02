// 타일 채우기 2
// 다이나믹 프로그래밍 & 선형대수학

// 행렬곱 이용
// DP[n] = 3*DP[n-2] + 2{DP[n-4]+DP[n-6]+DP[n-8]+.....+DP[0]}
// DP[n-2] = 3*DP[n-4] + 2{DP[n-6]+DP[n-8]+.....+DP[0]} 
// DP[n] = 4*DP[n-2] - DP[n-4]

#include <iostream>
#include <vector>

typedef long long ll;
typedef std::vector<std::vector<ll> > mat;

const ll mod = 1000000007;

ll N;

mat mult(mat &a, mat &b){
    ll n = a.size();
    mat c(n,std::vector<ll>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                c[i][j] += (a[i][k]*b[k][j])%mod;
                c[i][j] = (c[i][j]+mod)%mod;
            }
        }
    }

    return c;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> N;

    if(N%2){
        std::cout << "0\n";

    } else {

        mat A = {{4,-1},{1,0}};
        mat answer = {{1,0},{0,1}};

        N /= 2;

        while(N){
            if(N%2){
                answer = mult(answer,A);
            }
            A = mult(A,A);
            N /= 2;
        }

        std::cout << (answer[0][0] + answer[0][1] + mod) % mod << '\n';
    }


    return 0;
}