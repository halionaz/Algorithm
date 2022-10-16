# 초콜릿 피라미드
# 수학

# 재귀, 반복문 모두로 풀어봤는데
# 문제는 풀었지만 계속 시간초과가 남...

# 결국 수학 문제였음
# 수학 문제임을 알고 풀었을 때도 C++로 했더니 틀렸음이 뜸
# 파이썬으로 해야 풀리네

# X * Y 로 되어있는 층을 채우기 위한 화이트 초콜릿 개수는
# X*Y + (X-1)*(Y-1) 개임
# 또한 피라미드의 층 수는 Y개임 (X >= Y 일때)

# 따라서 i층이 i * (X - Y + i) 의 형태일때
# 이 층의 화이트 초콜릿 개수는
# (X-Y+i)*i + (X-Y+i-1)*(i-1) 개이므로 (= (X-Y)*i + i^2 + (X-Y)(i-1) + (i-1)^2 = (X-Y)*(2i-1) + 2i^2-2i+1)
# 우리는 i가 1, 2, 3, ... Y 인 경우를 모두 더해주면 되는 것임
# ∑{(X-Y)*(2i-1) + 2i^2-2i+1} = (X-Y)∑(2i-1) + ∑2i^2-2i+1
# = (X-Y)(Y(Y+1) - Y) + (Y(Y+1)(2Y+1))/3 - (Y(Y+1)) + Y
# = (X-Y)Y*Y + (Y(Y+1)(2Y+1))/3 - Y*Y
# = (Y(Y+1)(2Y+1))/3 - Y*Y + (X-Y)Y*Y

import sys
input = sys.stdin.readline

T = int(input())

def solve(X, Y) :
    # X * Y 피라미드를 세우는 데 필요한 화이트 초콜릿 개수 반환 
    # (X >= Y)
    if Y == 1 :
        return X
    else :
        return (Y*(Y+1)*(2*Y+1)//3) - Y*Y + Y*Y*(X-Y)

for _ in range(T) :
    R, C = map(int, input().split())

    if C > R :
        R, C = C, R
    
    ans = solve(R, C)

    print(ans, ans - C)
