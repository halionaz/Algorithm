# 행렬 제곱 
# 분할 정복 & 분할 정복을 이용한 거듭제곱 & 선형대수학

import sys
input = sys.stdin.readline
N, B = map(int,input().split())
matrix = []
for _ in range(N) : matrix.append(list(map(int,input().split())))
def multiple(mat1, mat2) :
    ans = []
    for i in range(len(mat1)) :
        row = []
        for j in range(len(mat2[0])) :
            element = 0
            for l in range(len(mat2)) :
                element += (mat1[i][l] * mat2[l][j])
            row.append(element%1000)
        ans.append(row)
    return ans

def square(mat,n) :
    if n == 1 :
        for i in range(len(mat)) :
            for j in range(len(mat[i])) :
                mat[i][j] %= 1000
        return mat
    else :
        arr = square(mat,n//2)
        if n%2 == 0 :
            return multiple(arr,arr)
        else :
            return multiple(multiple(arr,arr),mat)

for i in square(matrix, B) :
    print(' '.join(map(str,i)))
