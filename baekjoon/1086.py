# 박성원 
# 다이나믹 프로그래밍 & 비트마스킹 & 비트필드를 이용한 다이나믹 프로그래밍

# 시발 너무 어렵다
# 비트마스킹 거의 끝판왕

import sys
import math
input=sys.stdin.readline
def dfs(L,visit,rest):
    if visit==(1<<N)-1:
        if rest==0:
            return 1
        else:
            return 0
    if dp[visit][rest]!=-1:
        return dp[visit][rest]
    dp[visit][rest] = 0
    for i in range(N):
        if visit&(1<<i)==0:
            dp[visit][rest]+=dfs(L+long[i],visit|(1<<i),(rest+rm[i][L])%k)
    return dp[visit][rest]
N=int(input())
arr=[]
for _ in range(N):
    arr.append(int(input()))
long=[]
for i in arr:
    long.append(len(str(i)))
k=int(input())
dp=[[-1]*k for _ in range(1<<N)]
rm = [[-1]*(sum(long)) for _ in range(N)]
for i in range(N):
    for j in range(sum(long)):
        rm[i][j] = (arr[i]*(10**j))%k
son=dfs(0,0,0)
mom=math.factorial(N)
if son == 0:
    print('0/1')
else:
    t = math.gcd(mom,dp[0][0])
    print('{}/{}'.format(son//t,mom//t))