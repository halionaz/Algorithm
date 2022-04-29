// 타일 채우기
// 다이나믹 프로그래밍

// DP를 이용한 행렬 곱셈
// DP[n] = 3*DP[n-2] + 2{DP[n-4]+DP[n-6]+DP[n-8]+.....+DP[0]}
// DP[n-2] = 3*DP[n-4] + 2{DP[n-6]+DP[n-8]+.....+DP[0]}
// DP[n] = 4*DP[n-2] - DP[n-4]
// 이 점화식을 행렬곱을 통해 최적화할 수 있음

#include <iostream>
#include <vector>

typedef long long ll;
typedef std::vector<std::vector<ll>> mat;

ll N;

mat mult(mat &a, mat &b) {
  ll n = a.size();
  mat c(n, std::vector<ll>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  return c;
}

int main() {

  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);

  std::cin >> N;

  if (N % 2) {
    std::cout << "0\n";

  } else {

    mat A = {{4, -1}, {1, 0}};
    mat answer = {{1, 0}, {0, 1}};
    mat start = {{1, 0}, {1, 0}};

    N /= 2;

    while (N) {
      if (N % 2) {
        answer = mult(answer, A);
      }
      A = mult(A, A);
      N /= 2;
    }
    answer = mult(answer, start);

    std::cout << answer[0][0] << '\n';
  }

  return 0;
}