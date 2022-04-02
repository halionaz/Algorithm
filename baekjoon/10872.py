# 팩토리얼
# 구현

# N = int(input())

# def factorial(n):
#     if n > 1 :
#         return n*factorial(n-1)
#     else :
#         return 1

# print(factorial(N))

N = int(input())

def fact(n) :
    if n == 0 :
        return 1
    else :
        return fact(n-1)*n

print(fact(N))