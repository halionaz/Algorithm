# 검문
# 정수론 & 유클리드 호제법 & 수학

# 숫자 A, B, C, D... 가 있을 때,
# 문제의 조건에 성립하는 M으로 위 수를 표현해 보면

# A = M*a + R
# B = M*b + R
# C = M*c + R ....
# 이고, 이를 아래로 빼보면

# (A-B) = M(a-b)
# (B-C) = M(b-c) 와 같은 형태로 정리가 가능하다
# 즉, M은 A-B, B-C, C-D... 의 공약수여야 하는 것!
# 따라서 arr를 정렬한 후, 이들의 차이들의 약수들을 모두 구해보면 답이 된다

import math

N = int(input())

arr = []

for i in range(N) :
    arr.append(int(input()))

arr.sort()

gcd = arr[1] - arr[0]

for i in range(1,N-1) :
    gcd = math.gcd(gcd, arr[i+1]-arr[i])

ans = []

for i in range(2,int(gcd**0.5)+1) :
    if i not in ans and gcd%i == 0 :
        ans.append(i)

for i in reversed(ans) :
    if i != gcd**0.5:
        ans.append(gcd//i)

ans.append(gcd)

print(' '.join(list(map(str,ans))))