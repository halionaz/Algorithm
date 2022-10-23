# 소수
# 소수 판정

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
for i in range(M, N+1) :
    # i가 소수임을 판별
    isDecimal = True
    for j in range(2, i) :
        if i % j == 0:
            isDecimal = False
            break
    if i != 1 and isDecimal :
        if sum == 0 :
            # 최초로 나온 소수가 최솟값
            min = i
        sum += i

if sum == 0 :
    print(-1)
else :
    print(sum)
    print(min)