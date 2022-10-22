# 루나의 게임 세팅
# 수학 & 조합론

import math
N, K = map(int, input().split())
_ = input()
mod = 10**9+7
print(int(((math.comb(N,K)%mod)*(2**(K-1)))%mod)) # k-1_C_0 + k-1_C_1 + k-1_C_2 + ... + k-1_C_k-1 