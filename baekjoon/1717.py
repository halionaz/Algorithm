# 집합의 표현
# 분리 집합

# 대망의 유니온 파인드를 처음으로 사용해보는 문제.
# 유니온 파인드 = 분리 집합 = disjoint set

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)
n,m = map(int,input().split())
parents = [0]*(n+1) # 조상을 담는 memo
for i in range(1,n+1) :
    parents[i] = i

# 조상을 찾는 함수
def find(x) :
    if x == parents[x] :
        return x
    else :
        parents[x] = find(parents[x])
        return parents[x]

# a와 b를 같게 함
def union(a,b) :
    x = find(a)
    y = find(b)
    if x != y :
        if x<y : # 더 작은 조상 기준으로 설정
            parents[y] = x
        else :
            parents[x] = y

for _ in range(m) :
    c,a,b = map(int,input().split())
    if c :
        if find(a) == find(b) :
            print('YES')
        else :
            print('NO')
    else :
        # 합집합 연산
        union(a,b)