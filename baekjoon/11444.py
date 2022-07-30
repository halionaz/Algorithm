# 피보나치 수 6
# 분할 정복을 이용한 거듭제곱 & 수학

# 피보나치 수열의 점화식을 행렬의 곱셈으로 바꾸는 아이디어를 활용함
# (F_n+1  Fn   ) = (1 1)^n
# (F_n    F_n-1)   (1 0)

n = int(input())
eM = [[1,1],[1,0]] # 초기 행렬
def multiple(mat1, mat2) :
    ans = []
    for i in range(len(mat1)) :
        row = []
        for j in range(len(mat2[0])) :
            element = 0
            for l in range(len(mat2)) :
                element += (mat1[i][l] * mat2[l][j])
            row.append(element%1000000007)
        ans.append(row)
    return ans
def square(mat, N) :
    if N == 1 :
        return mat
    else :
        arr = square(mat, N//2)
        if N%2 == 0 :
            return multiple(arr, arr)
        else :
            return multiple(multiple(arr, arr), mat)
print(square(eM, n)[0][1])