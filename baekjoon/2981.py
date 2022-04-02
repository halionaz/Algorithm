# 검문
# 유클리드 호제법 & 수학

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