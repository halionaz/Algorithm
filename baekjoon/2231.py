# 분해합
# 브루트포스 알고리즘

# num = int(input())

# def solve(num):
#     for i in range(num):
#         strI = str(i+1) #각각의 숫자를 계산하기 위해 str로 형변환
#         sumOfNum = 0
#         for j in strI :
#             sumOfNum += int(j)
#         d = i+1 + sumOfNum #D값
#         if d == num :
#             return i+1
#     return 0

# print(solve(num))

N = int(input())

def T(n):
    strN = str(n)
    sum = 0
    for i in strN :
        sum += int(i)
    return sum+n


noAnswer = True
for i in range(N) :
    if T(i) == N :
        print(i)
        noAnswer = False
        break
if noAnswer :
    print(0)