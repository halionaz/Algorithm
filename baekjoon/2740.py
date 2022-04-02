# 행렬 곱셈
# 구현 & 선형대수학

N,M = map(int, input().split())
A = []
for _ in range(N) :
    A.append(list(map(int,input().split())))
M, K = map(int,input().split())
B = []
for _ in range(M) :
    B.append(list(map(int,input().split())))
ans = []
for i in range(N) :
    row = []
    for j in range(K) :
        element = 0
        for l in range(M) :
            element += A[i][l] * B[l][j]
        row.append(element)
    ans.append(row)
for i in ans :
    print(' '.join(map(str,i)))