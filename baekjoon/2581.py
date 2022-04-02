# 소수
# 소수 판정 & 에라토스테네스의 체

# M = int(input())
# N = int(input())

# arr = []
# for i in range(N-M+1) :
#     arr.append(i+M)
# for i in range(N) :
#     if i!=0 and i!=1 :
#         for j in arr :
#             if (i < j and j%i == 0) or j == 1 :
#                 arr.remove(j)
# if len(arr) == 0 :
#     print(-1)
# else :
#     min = arr[0]
#     sum = 0
#     for i in arr :
#         if i<min :
#             min = i
#         sum += i

#     print(sum)
#     print(min)

M = int(input())
N = int(input())

sum = 0
min = 0
for i in range(N-M+1) :
    isDecimal = True
    for j in range(M+i) :
        if (j!=0 and j!=1 and (M+i)%j==0) or M+i == 1 :
            isDecimal = False
            break
    if isDecimal :
        if sum == 0 :
            min = M+i
        sum += M+i

if sum == 0 :
    print(-1)
else :
    print(sum)
    print(min)