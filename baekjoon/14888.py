# 연산자 끼워넣기
# 백트래킹

# 처음으로 백트래킹 내 혼자 힘으로 해본듯! 뿌듯

N = int(input())
A = list(map(int,input().split()))
O = list(map(int,input().split()))
arr = [None] * (N-1)
min,max = None,None
def operate(depth) :
    global min,max
    if depth == N-1 :
        sol = A[0]
        for i in range(N-1) :
            if arr[i] == '+' :
                sol += A[i+1]
            elif arr[i] == '-' :
                sol -= A[i+1]
            elif arr[i] == '*' :
                sol *= A[i+1]
            else :
                sol = int(sol / A[i+1])
        if min == None or sol < min :
            min = sol
        if max == None or sol > max :
            max = sol
        return
    for i in range(4) :
        if O[i] > 0 :
            oper = ''
            if i == 0 :
                oper = '+'
            elif i == 1 :
                oper = '-'
            elif i == 2 :
                oper = '*'
            else :
                oper = '/'
            O[i] -= 1
            arr[depth] = oper
            operate(depth+1)
            arr[depth] = None
            O[i] += 1
operate(0)
print(max)
print(min)